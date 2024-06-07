
#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <chrono>
#include <ctime>
#include <utility>
#include <string>
#include <type_traits>
#include <algorithm>
#include <optional>

struct extra{
    time_t stamp;
    ssize_t rev;    
    ssize_t aev;
    std::string tstamp;
};

template<typename T, typename... X>
std::unique_ptr<T> make_unique(X&&... x) {
    return std::unique_ptr<T>(new T(std::forward<X>(x)...));
}

template<typename A>
struct alessio{
    std::vector<A> data;
    struct Alessio* nassio;
};

void a_error_msg(const char* msg);
template<typename A>
void new_alessio(struct alessio<A>* agen, std::vector<A> aev);
template<typename A>
void end_alessio(struct alessio<A>* agen, std::vector<A> aev);
template<typename A>
struct alessio<A> arbitrary_pos(struct alessio<A>* agen, std::vector<A> aev, int pos);

template<typename T>
class Alogic{
    public:
    Alogic(){
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
        std::string now_str = std::ctime(&now_time_t);
        struct extra aextra;
        ssize_t real_compute = aextra.stamp ^ aextra.stamp << 1 ^ aextra.stamp << 2;
        aextra.aev = real_compute; aextra.rev= real_compute; aextra.stamp = now_time_t; aextra.tstamp = now_str;
        struct alessio<struct extra> ablock;
        ablock.data.push_back(aextra);
        chain.push_back(ablock);
    };

    Alogic(const Alogic& alogic);
    Alogic operator=(const Alogic& alogic);
    std::vector<struct alessio<T> > get_blocks();
    std::vector<struct alessio<T> > add_block(struct alessio<T>& newentry);
    void display_chain_blocks();
    private:  
    std::vector<struct alessio<T> > chain;
};
