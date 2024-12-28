#include <iostream>
#include <vector>
#include <memory>

#include "block.h"


using std::unique_ptr;
using std::vector;

class Blockchain
{
private:

    vector<unique_ptr<Block> > m_blocks;

public:

};
