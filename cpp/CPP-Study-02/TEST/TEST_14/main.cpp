#include <iostream>

class TicketPayload
{
public:
    int64_t create_ts;
    std::string account;
    bool verify = false;
    std::string rand_bytes;
};

std::string EncryptForCtr(const std::string_view& strText, const std::string_view& strSecretKey, const std::string_view& strIV)
{
    EVP_CIPHER_CTX_PTR ctx(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free);

    if (!EVP_CipherInit_ex(ctx.get(), EVP_aes_256_ctr(), NULL, NULL, NULL, 1))
        return "";

    std::string key = KWBase64::Decode(strSecretKey);
    std::string iv = KWBase64::Decode(strIV);

    if (!EVP_CipherInit_ex(ctx.get(), NULL, NULL, (const unsigned char*)key.c_str(), (const unsigned char*)iv.c_str(), 1))
        return "";

    int text_len = strText.size();

    KWBufferCell plain_buffer_cell(mMultiBuffer, text_len);
    unsigned char* plain_buff = plain_buffer_cell.GetBuffer();
    if (!plain_buff)
        return "";

    KWBufferCell out_buffer_cell(mMultiBuffer, text_len);
    unsigned char* out_buff = out_buffer_cell.GetBuffer();
    if (!out_buff)
        return "";

    uint32_t nOffset = 0;

    memcpy(plain_buff + nOffset, reinterpret_cast<void*>(const_cast<char*>(strText.data())), text_len);
    nOffset += text_len;

    int len = 0;
    int out_len = 0;

    if (!EVP_CipherUpdate(ctx.get(), out_buff, &out_len, plain_buff, text_len))
        return "";

    len += out_len;

    if (!EVP_CipherFinal_ex(ctx.get(), out_buff + out_len, &out_len))
        return "";

    len += out_len;

    std::string strEncrypted(reinterpret_cast<const char*>(out_buff), len);

    return strEncrypted;
}

int main(void) {
  

  return EXIT_SUCCESS;
}
