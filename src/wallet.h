#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include "common.h"
#include "crypto.h"

class Wallet
{
public:

    struct CompressedPubKey
    {
        uint8_t prefix;
        uint256_t xCoord;
    };

private:

    uint256_t privateKey;
    CompressedPubKey publicKey;

public:

    Wallet();
    ~Wallet();

    void createPrivateKey();

    const unsigned char *getPublicKey() const;
};

#endif
