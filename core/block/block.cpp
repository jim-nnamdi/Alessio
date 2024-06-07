#include "block.hpp"

template<typename A>
void new_alessio(struct alessio<A>* agen, std::vector<A> aev){
    if(agen == nullptr) a_error_msg("no blocks");
    struct alessio<A>* asam = new struct alessio<A>();
    asam->data = aev; asam->nassio = nullptr;
    struct alessio<A>* csam = new struct alessio<A>();
    csam->data = aev; csam->nassio = nullptr;
    asam->next_block = csam;
}

template<typename A> 
void end_alessio(struct alessio<A>* agen, std::vector<A> aev){
    struct alessio<A>* ptr; ptr = agen; 
    std::unique_ptr<struct alessio<A> > temp = make_unique<struct alessio<A> >;
    temp->data = aev; temp->nassio = nullptr;
    while(ptr->nassio != nullptr)
        ptr = ptr->nassio;
    ptr->nassio = temp;
}

template<typename A>
struct alessio<A> arbitrary_pos(struct alessio<A>* agen, std::vector<A> aev, int pos){
    struct alessio<A>* frst; frst = agen; 
    std::unique_ptr<struct alessio<A> >scnd = make_unique<struct alessio<A> >;
    scnd->data = aev; scnd->nassio = nullptr; pos--;
    while(pos != 1)
        frst = frst->nassio; pos--;
    scnd->nassio = frst->nassio;
    frst->nassio = scnd;
}

template<typename T>
std::vector<struct alessio<T> > Alogic<T>::get_blocks(){
    for(typename std::vector<struct alessio<T> >::const_iterator block = chain.begin(); block != chain.end(); ++block)
        std::cout << *block << std::endl;
    return chain;
}

template<typename T> 
std::vector<struct alessio<T> > Alogic<T>::add_block(struct alessio<T>& newentry) {
    for(typename std::vector<struct alessio<T> >::iterator vec = chain.begin(); vec != chain.end(); ++vec){
        struct alessio<T>& vdata = *vec;
        struct extra datax = vdata.data;
        struct extra nentx = newentry.data;
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
        std::time_t block_diff = nentx.stamp - now_time_t;
        if(datax.rev != nentx.rev && now_time_t > block_diff)
            chain.push_back(newentry);
        else break;
    }
    std::vector<struct alessio<T> > ablocks = get_blocks(); 
    return ablocks;
}
template<typename T>
void Alogic<T>::display_chain_blocks(){
    for(typename std::vector<struct alessio<T> >::const_iterator bk = chain.begin(); bk != chain.end();)
        std::cout << *bk << std::endl;
}

void a_error_msg(const char* msg) { perror(msg);}