#include <iostream>

#include "wallet.h"
#include "block.h"
#include "crypto.h"

int main(){
    Block b;

    int32_t target = 0x1EFFDD01;

    std::string input = "Gabriel Raine Nakamoto";
    std::string hash;
    int nonce = 0;

    do
    {
        hash = crypto::hash256(input + std::to_string(nonce));

        std::cout << "\rNonce: " << nonce << std::flush;

        ++nonce;

    } while (! b.is_valid(hash, target));

    std::cout << "\nFinal hash: " << hash;

    return 0;
}
