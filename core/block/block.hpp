
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <utility>

struct extra{
    const char* rev;
    const char* aev;
    time_t stamp;
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
