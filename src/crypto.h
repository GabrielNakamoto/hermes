#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

#include "common.h"
#include "uint256_t.h"

namespace crypto
{

template<typename T>
static
T hexStringToInteger(const std::string &hex)
{
    // make sure there is enough room in T type
    // for # of bytes in hex
    //
    //
    // support 0x.. prefix
    // support spaces?
    T value = 0;

    for (char c : hex)
    {
        uint8_t digit = isdigit(c) ?    static_cast<uint8_t>(c - '0') :
                                        static_cast<uint8_t>(c - 'a' + 10);

        value = (value << 4) | digit;
    }

    return value;
}

static
std::string hash256(const std::string &input)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    const unsigned char *data = reinterpret_cast<const unsigned char *>(input.c_str());

    SHA256(data, input.size(), hash);

    std::stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        // setw(2) -> each byte is represented by 2 hex characters
        // setfill('0') -> leading 0's if less than 2 hex digits
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}


}

#endif
