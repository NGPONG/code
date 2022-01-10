#include <iostream>
#include <array>
#include <memory>
#include <set>
#include <unordered_map>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <chrono>

#include <unistd.h>

#include "openssl/aes.h"
#include "openssl/rand.h"
#include "openssl/evp.h"

#include "ajson.hpp"

using EVP_CIPHER_CTX_PTR = std::unique_ptr<EVP_CIPHER_CTX, decltype(&EVP_CIPHER_CTX_free)>;

class TicketPayload
{
public:
    int64_t create_ts;
    std::string account;
    std::string verify;
};
AJSON(TicketPayload, create_ts, account, verify)

#define BUFF_SIZE           1024

#define AES_ECB_KEY_SIZE    32

#define AES_CBC_KEY_SIZE    32
#define AES_CBC_IV_SIZE     16

#define AES_CTR_KEY_SIZE    32
#define AES_CTR_IV_SIZE     16

#define MAX_BUFF_BLOCK_COUNT    10
#define MIN_NULTI_BUFF_SIZE     (1 * 1024 * 1024)
#define MAX_NULTI_BUFF_SIZE     (32 * 1024 * 1024)

class KWMultiBuffer
{
public:
    explicit KWMultiBuffer(int bufferBlockCount, const int initBufferSize, const int maxBufferSize)
    {
        mMaxBufferSize = maxBufferSize;

        for (int i = 0; i < bufferBlockCount; i++)
        {
            unsigned char* buffer = new unsigned char[initBufferSize]();

            mBufferInfoMap[buffer] = initBufferSize;
            mAvailableBufferSet.insert({initBufferSize, buffer});
        }
    }

    ~KWMultiBuffer()
    {
#if BUFFER_THREADING_ENABLED
        std::lock_guard<std::mutex> lck(mMtx);
#endif
        for (auto& [buffer, size] : mBufferInfoMap)
            delete []buffer;

        mBufferInfoMap.clear();
        mAvailableBufferSet.clear();
    }

    unsigned char* GetAvailableBuffer(const int needBufferSize)
    {
        if (needBufferSize > mMaxBufferSize)
            return nullptr;

#if BUFFER_THREADING_ENABLED
        std::lock_guard<std::mutex> lck(mMtx);
#endif

        if (mAvailableBufferSet.empty())
            return nullptr;

        unsigned char* buffer = nullptr;
        std::pair<int, unsigned char*> bufferPair(needBufferSize, nullptr);

        auto itor = mAvailableBufferSet.lower_bound(bufferPair);

        // 没找到大小合适的buffer，则扩充最大的buffer
        if (itor == mAvailableBufferSet.end())
        {
            auto itorMaxBuffPair = mAvailableBufferSet.rbegin();

            mBufferInfoMap.erase(itorMaxBuffPair->second);
            mAvailableBufferSet.erase(*itorMaxBuffPair);

            int newBufferSize = std::min(needBufferSize*2, mMaxBufferSize);
            buffer = new unsigned char[newBufferSize];

            mBufferInfoMap[buffer] = newBufferSize;
        }
        else
        {
            buffer = itor->second;
            mAvailableBufferSet.erase(itor);
        }

        return buffer;
    }

    bool GiveBackBuffer(unsigned char* buffer)
    {
        if (!buffer)
            return false;

#if BUFFER_THREADING_ENABLED
        std::lock_guard<std::mutex> lck(mMtx);
#endif

        if (mBufferInfoMap.count(buffer) == 0)
            return false;

        int nBufferSize = mBufferInfoMap[buffer];

        std::pair<int, unsigned char*> bufferPair(nBufferSize, buffer);
        if (mAvailableBufferSet.count(bufferPair) > 0)
            return false;

        std::memset(buffer, 0x0, nBufferSize);
        mAvailableBufferSet.insert(bufferPair);

        return true;
    }

private:
    int mMaxBufferSize;
    std::unordered_map<unsigned char*, int> mBufferInfoMap;
    std::set<std::pair<int, unsigned char*>> mAvailableBufferSet;
#if BUFFER_THREADING_ENABLED
    std::mutex mMtx;
#endif
};

class KWBufferCell
{
public:
    explicit KWBufferCell(std::shared_ptr<KWMultiBuffer>& multiBuffer, const int needBufferSize)
    {
        mMultiBuffer = multiBuffer;
        mBuffer = mMultiBuffer->GetAvailableBuffer(needBufferSize);
    }

    ~KWBufferCell()
    {
        mMultiBuffer->GiveBackBuffer(mBuffer);
    }

    unsigned char* GetBuffer()
    {
        return mBuffer;
    }

private:
    unsigned char* mBuffer;
    std::shared_ptr<KWMultiBuffer> mMultiBuffer;
};

class KWBase64
{
public:
    static std::string Encode(const std::string_view& plain)
    {
        unsigned char const* bytes_to_encode = reinterpret_cast<const unsigned char*>(plain.data());
        unsigned int in_len = plain.length();

        int i = 0, j = 0;

        unsigned char char_array_3[3], char_array_4[4];

        std::string dest;

        while (in_len--)
        {
            char_array_3[i++] = *(bytes_to_encode++);

            if (i == 3)
            {
                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for (i = 0; i < 4; ++i)
                {
                    dest += alphabet[char_array_4[i]];
                }

                i = 0;
            }
        }

        if (i)
        {
            for (j = i; j < 3; ++j)
            {
                char_array_3[j] = '\0';
            }

            char_array_4[0] = ((char_array_3[0] & 0xfc) >> 2);
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

            for (j = 0; j < i + 1; ++j)
            {
                dest += alphabet[char_array_4[j]];
            }

            while (i++ < 3)
            {
                dest += '=';
            }
        }

        return dest;
    }

    static std::string Decode(const std::string_view& encoded)
    {
        int in_len = encoded.size();

        int i = 0, j = 0;
        int in_ = 0;

        unsigned char char_array_3[3], char_array_4[4];

        std::string dest;

        while (in_len-- && (encoded[in_] != '=') && isBase64(encoded[in_]))
        {
            char_array_4[i++] = encoded[in_++];

            if (i == 4)
            {
                for (i = 0; i < 4; ++i)
                {
                    char_array_4[i] = std::distance(alphabet.begin(), std::find(alphabet.begin(), alphabet.end(), char_array_4[i]));
                }

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) +   char_array_4[3];

                for (i = 0; i < 3; ++i)
                {
                    dest += char_array_3[i];
                }

                i = 0;
            }
        }

        if (i)
        {
            for (j = 0; j < i; ++j)
            {
                char_array_4[j] = std::distance(alphabet.begin(), std::find(alphabet.begin(), alphabet.end(), char_array_4[j]));
            }

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);

            for (j = 0; j < i - 1; ++j)
            {
                dest += char_array_3[j];
            }
        }

        return dest;
    }

private:

    inline static constexpr std::array<char, 64> alphabet
    {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
    };

    inline static bool isBase64(unsigned char c)
    {
        return isalnum(c) || (c == '+') || (c == '/');
    }
};

std::string EncryptForEcb(const std::string_view& strText, const std::string_view& strSecretKey)
{
    int cipher_block_size = EVP_CIPHER_block_size(EVP_aes_256_ecb());
    unsigned char out_buff[BUFF_SIZE + cipher_block_size];
    memset(out_buff, 0, sizeof(out_buff));

    int out_len = 0;

    EVP_CIPHER_CTX_PTR ctx(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free);

    if (!EVP_CipherInit_ex(ctx.get(), EVP_aes_256_ecb(), NULL, NULL, NULL, 1))
        return "";

    OPENSSL_assert(EVP_CIPHER_CTX_key_length(ctx.get()) == AES_ECB_KEY_SIZE);

    std::string strKey = KWBase64::Decode(strSecretKey);

    if (!EVP_CipherInit_ex(ctx.get(), NULL, NULL, (const unsigned char*)strKey.c_str(), NULL, 1))
        return "";

    int len = 0;

    //---------------------------------------------------------------------------------------------------
    //in order to disable aes padding, the plain text buffer to aes must be 'cipher_block_size' length,
    //so transform plain text in the following format:
    //[Head Padding][Body Data...][Tail Padding]
    //Head Padding: 4 bytes, store the reald body data length value.
    //Body Data: the real plain text content.
    //Tail Padding: pad the final block to make a 'cipher_block_size'-length block.
    //---------------------------------------------------------------------------------------------------
    int text_len = strText.size();
    int zero_len = cipher_block_size - (sizeof(text_len) + text_len) % cipher_block_size;

    int plain_len = sizeof(text_len) + text_len + zero_len;

    unsigned char plain_buff[plain_len];
    memset(plain_buff, 0x0, plain_len);

    uint32_t nOffset = 0;

    int encode_len = htobe32(text_len);

    memcpy(plain_buff + nOffset, reinterpret_cast<void*>(&encode_len), sizeof(text_len));
    nOffset +=  sizeof(text_len);

    memcpy(plain_buff + nOffset, reinterpret_cast<void*>(const_cast<char*>(strText.data())), text_len);
    nOffset += text_len;

    if (zero_len > 0)
        memset(plain_buff + nOffset, 0, zero_len);

    if (!EVP_CipherUpdate(ctx.get(), out_buff, &out_len, plain_buff, plain_len))
        return "";

    len = out_len;

    if (!EVP_CIPHER_CTX_set_padding(ctx.get(), 0))
        return "";

    if (!EVP_CipherFinal_ex(ctx.get(), out_buff + out_len, &out_len))
        return "";

    len += out_len;

    std::string strEncrypted(reinterpret_cast<const char*>(out_buff), len);

    return strEncrypted;
}

template<typename T, typename... Args>
std::shared_ptr<T> KWMakeShared(Args&&... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

std::string foo(std::string account, bool verify) {
  TicketPayload payload;
  payload.account = account;
  payload.create_ts = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000;

  u_char buf[16];
  RAND_bytes(buf, sizeof(buf));

  std::string verifystr = KWBase64::Encode(std::string_view(reinterpret_cast<const char *>(buf), sizeof(buf)));
  verifystr.at(0) = std::to_string(verify).at(0);

  payload.verify = verifystr;

  bool v = payload.verify.at(0) - '0';
  std::cout << v << std::endl;

  ajson::string_stream ss;
  ajson::save_to(ss, payload);

  std::cout << ss.str() << std::endl;

  return KWBase64::Encode(EncryptForEcb(ss.str(), "MwCVGzAAWLhCYnz4ZmPJxLA4dYGXAjVRltjWCGUt4j4="));
}

int main(void) {
  for (int i = 0; i < 10; ++i) {
    foo("xxtest_" + std::to_string(i), true);
  }

  // std::string str = std::to_string(false);

  // std::cout << std::stoi(str) << std::endl;

  // str = std::to_string(true);
  // std::cout << std::stoi(str) << std::endl;

  return EXIT_SUCCESS;
}
