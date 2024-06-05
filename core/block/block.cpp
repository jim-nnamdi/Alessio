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

int main() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::string now_str = std::ctime(&now_time_t);
    struct extra aextra;
    aextra.aev = "previous hash"; aextra.rev="current hash"; aextra.stamp = now_time_t; aextra.tstamp = now_str;
    struct alessio<struct extra>* zblock = new struct alessio<struct extra>;
    zblock->data.push_back(aextra);
    std::vector<struct extra> z = zblock->data;
    typedef std::vector<struct extra>::const_iterator aiterator;
    for(aiterator zb = z.begin(); zb != z.end(); zb++){
        const char *revx = zb->rev; std::cout << revx << std::endl;
        const char *aevx = zb->aev; std::cout << aevx << std::endl;
        time_t creation_t = zb->stamp; std::cout << creation_t << std::endl;
        std::string timed = zb->tstamp; std::cout << timed << std::endl;
    }
    delete zblock;
    return 0;
}