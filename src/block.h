#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include "common.h"
#include "transaction.h"


class Block
{
public:

    struct Header
    {
        uint256_t prevHash;
        uint256_t merkleRoot;
        int32_t nonce;
        int32_t bits;
    };

private:

    Header m_header;

    std::vector<Transaction> transactions;

public:

    Block() = default;
};

#endif
