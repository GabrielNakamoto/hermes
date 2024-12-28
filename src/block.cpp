#include "block.h"
#include "crypto.h"

Block::Block()
{

}

Block::~Block()
{

}

bool Block::is_valid(const std::string &hash, int32_t targetRep) const
{
    uint256_t value = crypto::hexStringToInteger<uint256_t>(hash);

    int64_t exponent = (targetRep >> 24) - 3;
    uint256_t coefficient = targetRep & 0x00FFFFFF;
    uint256_t target = coefficient << (exponent * 8);

    return value <= target;
}
