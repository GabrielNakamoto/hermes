#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include "common.h"


/*
 * (1)  Select a batch of inputs (previous outputs located at
 *      the wallets adress) and unlock them
 *
 * (2)  Create a new batch of coins (outputs) and put locks
 *      on them
 *
 *      These new locks will only be unlockable by the people
 *      they are intended for. This will be acheived by including
 *      the public key of the payee and require the corresponding
 *      private key to make a digital signature.
 *
 *
 *
 *  Input:
 *
 *      TXID (32 byte) -> hash of transaction being used
 *      outIndex (4 byte) -> index of specific output of that transaction
 *
 *      unlocking code (this must be publicly verifiable)
 *
 *
 *  Output:
 *
 *      Amount (8 bytes) -> amount to be transferred
 *
 *      locking code -> this needs to be only possible to unlock / fulfill
 *                      with the private key of the intended payee
 *
 *
 *  Verification types:
 *
 *      P2PK
 *
 *      P2PKH
 */

class Transaction
{
public:


    struct Outpoint
    {
        uint256_t TXID;
        int32_t outIndex;
    };

    /*
     * Need some way to verify without scripting
     * langauge (for now)
     *
     * Will use verId to represent 1 byte
     * which I can use for a finite amount of
     * defined transaction verification methods
     *
     */

    struct Input
    {


        Outpoint outpoint;
        unsigned char verId;
    };

    struct Output
    {
        // in satoshis
        int64_t amount;

    };

private:

    int nInputs;
    int nOutputs;

    std::vector<Input> inputs;
    std::vector<Output> outputs;

public:

};

#endif
