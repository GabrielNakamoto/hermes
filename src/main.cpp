#include <iostream>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>

#include "uint256_t.h"

#include "wallet.h"
#include "crypto.h"


std::string hash256(const std::string &input)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    const unsigned char *data = reinterpret_cast<const unsigned char *>(input.c_str());

    SHA256(data, input.size(), hash);

    std::stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        // setw(2) -> each byte is represented by 2 hex characters
        // setfill('0') -> leading 0's if less than 2 hex digits
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

bool verify(const std::string &hash, int32_t targetRep)
{

    uint256_t value = crypto::hexStringToInteger<uint256_t>(hash);

    int64_t exponent = (targetRep >> 24) - 3;
    uint256_t coefficient = targetRep & 0x00FFFFFF;
    uint256_t target = coefficient << (exponent * 8);

    return value <= target;
}

int main(){
    int32_t target = 0x1EFFDD01;

    std::string input = "Gabriel Raine Nakamoto";
    std::string hash;
    int nonce = 0;

    do
    {
        hash = hash256(input + std::to_string(nonce));

        std::cout << "\rNonce: " << nonce << std::flush;

        ++nonce;

    } while (! verify(hash, target));

    std::cout << "\nFinal hash: " << hash;

    return 0;
}
