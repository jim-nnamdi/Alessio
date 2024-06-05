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
void a_error_msg(const char* msg) { perror(msg);}