#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include "common.h"

class Wallet
{
public:

    struct CompressedPubKey
    {
        uint8_t prefix;
        uint256_t xCoord;
    };

private:

    /* static constexpr uint256_t MAX_PRIVATE_VALUE = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364140; */

    uint256_t privateKey;
    CompressedPubKey publicKey;

public:

    Wallet();
    ~Wallet();

    void createPrivateKey();

    const unsigned char *getPublicKey() const;
};

#endif
