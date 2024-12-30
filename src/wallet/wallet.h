#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <unordered_map>

#include <primitives/transaction.h>
#include "common.h"
#include "crypto.h"

namespace wallet
{

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

    int64_t balance;

    // dont work for some reaoson
    /* std::unordered_map<uint256_t, TransactionRef> watchedTx; */

public:

    Wallet();
    ~Wallet();

    void createPrivateKey();
    void derivePublicKey();

    void send(int64_t amount, CompressedPubKey payeePubKey);
};

}

#endif
