#include <iostream>

#include <secp256k1.h>

#include "common.h"

#include "wallet.h"
#include "block.h"
#include "crypto.h"

int main(){

    wallet::Wallet w;
    w.createPrivateKey();
    w.derivePublicKey();

    /* Block b; */

    /* int32_t target = 0x1EFFDD01; */

    /* std::string input = "Fwea"; */
    /* std::string hash; */
    /* int nonce = 0; */

    /* do */
    /* { */
    /*     hash = crypto::hash256(input + std::to_string(nonce)); */

    /*     std::cout << "\rNonce: " << nonce << std::flush; */

    /*     ++nonce; */

    /* } while (! b.is_valid(hash, target)); */

    /* std::cout << "\nFinal hash: " << hash; */

    /* return 0; */
}
