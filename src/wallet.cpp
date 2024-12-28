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

    uint256_t randomValue;

    /* if (urandom) */
    /*     while(randomValue < Wallet::MAX_PRIVATE_VALUE) */
    /*         urandom.read(reinterpret_cast<char*>(&randomValue), 32); */
    // else throw exception?
    urandom.close();

    privateKey = randomValue;

    std::stringstream ss;
    ss << std::hex << privateKey;

    std::string buf(ss.str());

    std::cout << buf.size() << " hex digits\n" << buf;
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
