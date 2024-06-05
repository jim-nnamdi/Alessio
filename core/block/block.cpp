#include "block.hpp"

template<typename A>
Blockchain<A>& Blockchain<A>::operator=(const Blockchain& blockchain){
    if(this != &blockchain)
        chain = blockchain.chain;
    return *this;
}

template<typename A>
std::vector<Block> Blockchain<A>::aalloc(const Block& alloc_block, A data){
    std::vector<Block> newblock;
    newblock.push_back(alloc_block);
    return newblock;
}