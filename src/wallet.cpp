#include "wallet.h"

#include <iostream>
#include <sstream>

#include <secp256k1.h>


Wallet::Wallet()
{

}

Wallet::~Wallet()
{

}

void Wallet::createPrivateKey()
{
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);

    // put this somewhere else
    /* const uint256_t maxValue = crypto::hexStringToInteger<uint256_t>("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364140"); */

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

    secp256k1_context_destroy(ctx);
}

void Wallet::send(int64_t amount, CompressedPubKey payeePubKey)
{
    // exception
    if (amount > balance)
        return;

    //

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
