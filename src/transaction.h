#pragma once

#include <iostream>
#include "common.h"

class Transaction
{
public:

    struct Input
    {
        // hash of the data of the transaction
        // which has an output this input is
        // trying to spend / unlock
        uint256_t previousOutput;
        int32_t outIndex;
    };

    struct Output
    {
        // in satoshis
        int64_t amount;

    };

private:

    int inputs;
    int outputs;

public:
};
