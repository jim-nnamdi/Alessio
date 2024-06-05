
#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <chrono>
#include <vector>
#include <set>

struct BlockHeader{
    std::string prev_hash;
    time_t created_date;
    bool operator=(const BlockHeader& header){
        return prev_hash == header.prev_hash && 
        created_date == header.created_date;
    }
};

namespace std {
    template<>
    struct hash<BlockHeader> {
        size_t operator()(const BlockHeader& blockheader){
            size_t bprev_hash = std::hash<std::string>()(blockheader.prev_hash);
            size_t bcreated_at = std::hash<time_t>()(blockheader.created_date);
            return bprev_hash ^ (bcreated_at << 1);
        }
    };
}

struct Block{
    public:
    std::string address;
    BlockHeader header;
    std::vector<std::string> transactions;
    bool operator=(const Block& block) const {
        return address == block.address && 
        header.prev_hash == block.header.prev_hash 
        && transactions == block.transactions;
    }
};

namespace std {
    template<>
    struct hash<Block> {
        size_t operator()(const Block& block) const {
            size_t block_address = std::hash<std::string>()(block.address);
            size_t block_prev_hash = std::hash<std::string>()(block.header.prev_hash);
            size_t block_transacts = std::hash<size_t>()(block.transactions.size());
            return block_address ^ (block_prev_hash << 1) ^ (block_transacts << 2);
        }
    };
}

template<typename A>
class Blockchain {
    public: 
    Blockchain();
    ~Blockchain();
    Blockchain(const Blockchain& blockchain);
    Blockchain<A>& operator=(const Blockchain& blockchain);
    std::vector<std::set<std::vector<Block> > > vault();
    std::vector<Block> aalloc(const Block& alloc_block, A data);

    private:  
    std::vector<Block> chain;
};
