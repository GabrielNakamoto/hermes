#include "wallet.h"

#include <iostream>
#include <fstream>
#include <sstream>


Wallet::Wallet()
{

}

Wallet::~Wallet()
{

}

void Wallet::createPrivateKey()
{
    std::ifstream urandom("/dev/urandom", std::ios::binary);


    // put this somewhere else
    const uint256_t maxValue = crypto::hexStringToInteger<uint256_t>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364140");

    uint256_t randomValue = uint256_max;

    if (urandom)
        while(randomValue > maxValue)
            urandom.read(reinterpret_cast<char*>(&randomValue), 32);

    // else throw exception?
    urandom.close();

    privateKey = randomValue;
}

/* std::string Wallet::getPublicKey() const */
/* { */
/*     unsigned char buffer[33]; */

/*     buffer[0] = publicKey.prefix; */

/*     for (int i = 32 - 1; i >= 0; --i) */
/*     { */
/*         buffer[i] = static_cast<unsigned char>((publicKey.xCoord >> (i * 8)) & 0xFF); */
/*     } */

/*     std::string bufferString(&buffer[0]); */

/*     return bufferString; */
/* } */
