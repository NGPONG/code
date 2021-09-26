#include <set>
#include <deque>
#include <iostream>
#include <algorithm>

#include "rand.h"

using namespace std;

inline static constexpr std::array<char, 64> alphabet
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};


std::string Encode(const std::string_view& plain)
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


int main(void) {
    unsigned char iv[16];

    RAND_bytes(iv, sizeof(iv));

    return EXIT_SUCCESS;
}
