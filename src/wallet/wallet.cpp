#include "wallet.h"

#include <iostream>
#include <sstream>

#include <secp256k1.h>

namespace wallet
{

Wallet::Wallet()
{

}

Wallet::~Wallet()
{

}

void Wallet::createPrivateKey()
{
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);

    uint256_t randomValue = uint256_max;

    while (! secp256k1_ec_seckey_verify(ctx, reinterpret_cast<const unsigned char *>(&randomValue)))
    {
        crypto::getRandom(reinterpret_cast<unsigned char *>(&randomValue), 32);
    }

    privateKey = randomValue;

    secp256k1_context_destroy(ctx);
}

void Wallet::derivePublicKey()
{
    unsigned char randomize[32];
    unsigned char compressedPubkey[33];
    secp256k1_pubkey pubkey;

    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    int ret;

    crypto::getRandom(randomize, 32);

    ret = secp256k1_context_randomize(ctx, reinterpret_cast<unsigned char*>(randomize));

    ret = secp256k1_ec_pubkey_create(ctx, &pubkey, reinterpret_cast<const unsigned char *>(&privateKey));

    size_t targetLen = sizeof(compressedPubkey);
    ret = secp256k1_ec_pubkey_serialize(ctx, compressedPubkey, &targetLen, &pubkey, SECP256K1_EC_COMPRESSED);

    publicKey.prefix = compressedPubkey[0];
    memcpy(&publicKey.xCoord, compressedPubkey + 1, 32);

    secp256k1_context_destroy(ctx);
}

//
// Send function:
//
//      if we have enough balance
//
//      create unsigned transaction
//
//          iterates through all outputs that
//          reside at this adress
//
//          save them as inputs until >= amount
//
//      create outputs (miner fee, reroute to self, destination)
//
//      sign transaction
//
//      transmit / broadcast transaction
//
//
//

void Wallet::send(int64_t amount, CompressedPubKey payeePubKey)
{
    // exception
    if (amount > balance){
        return;
    }

    int64_t coins;


    // how do I know that this transaction
    // was sent to me?
    //
    // do I just verify it right away
    /* for (const auto txRef : watchedTx) */
    /* { */

    /* } */

}


}
