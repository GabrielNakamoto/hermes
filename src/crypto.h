#ifndef CRYPTO_H
#define CRYPTO_H

namespace crypto
{

template<typename T>
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


}

#endif
