
#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <chrono>
#include <ctime>
#include <utility>
#include <string>

struct extra{
    time_t stamp;
    const char* rev;    
    const char* aev;
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
