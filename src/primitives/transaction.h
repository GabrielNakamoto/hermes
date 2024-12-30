#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <memory>

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
 * Sender verifies the input signatures
 * Payee can verify the output signatures
 *
 * Sender signs outputs and verifies inputs
 *
 *
 * Example:
 *
 *      Bob sending coins to Alice
 *
 *
 *
 *
 *  Script sig basically just provides a signature (input)
 *
 *  Public key script basically just requires a signature
 *  matching a public key to unlcok it (output)
 *
 *  ECDSA Signing:
 *
 *      Inputs:
 *
 *          message
 *          private key
 *
 *      Output:
 *
 *          signature
 *
 *  ECDSA Verify Signature:
 *
 *      Inputs:
 *
 *          signed message
 *          signature
 *          public key
 *
 *      Output:
 *
 *          valid (boolean)
 *
 *
 *  Verification types:
 *
 *  *   scriptPubKey is the lock (for the person sending to
 *      put on the output)
 *
 *      scriptSig is for the person creating a new transaction
 *      to put on an input (unlock it)
 *
 *
 *      P2PK (Pay to public key)
 *
 *
 *
 *      P2PKH (Pay to public key hash)
 */


//
// store byte information in unsigned chars,
// convert to integers when comparisons are
// needed?
//


class Transaction;

template<typename Stream>
void SerializeTransaction(const Transaction &tx, Stream &s)
{

}

template<typename Stream>
void DeSerializeTransaction(const Transaction &tx, Stream &s)
{

}

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
        /**
         *
         * Verid options:
         *
         * 0x1 = P2PK
         * 0x2 = P2PKH
         *
         */
        unsigned char verId;
        /*
         * show that you own the private key
         * corresponmding to the public key contained
         * in the output
         *
        */
        uint256_t signature;
    };

    struct Output
    {
        // in satoshis
        int64_t amount;
        uint256_t publicKey;
    };

private:

    int nInputs;
    int nOutputs;

    std::vector<Input> inputs;
    std::vector<Output> outputs;

public:

    Transaction();
    ~Transaction();


};

typedef std::shared_ptr<const Transaction> TransactionRef;

#endif
