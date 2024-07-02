#include <iostream>
#include <functional>
#include <deque>
#include <memory>
#include <string>
#include <utility>
#include "ajson.hpp"

class KWQueueUpTicketPayLoad
{
public:
    uint64_t create_ts;
    std::string account;
    bool verify;

public:
    template<class F, class... Args>
    std::string Encode(F encrypter, Args... args) 
    {
        ajson::string_stream ss;
        ajson::save_to(ss, *this);

        return encrypter(ss.str(), std::forward<Args>(args)...);
    }

    template<class F, class... Args>
    static KWQueueUpTicketPayLoad Decode(std::string ticket, F decrypter, Args... args) 
    {
        const std::string& js = decrypter(ticket, std::forward<Args>(args)...);

        KWQueueUpTicketPayLoad payLoad;
        ajson::load_from_buff(payLoad, js.c_str());
        return payLoad;
    }
};

AJSON(KWQueueUpTicketPayLoad, create_ts, account, verify)


class BASE {
public:
    virtual int foo(int a, std::string b, float c) = 0;
};

class ease : public BASE {
public:
  int foo(int a, std::string b, float c) override 
  {
      std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        return 1024;
  }
};

// Type base, R (Type::*handler)(Args...), Args... args
// R (*handler)(Args...), Args... args
template<class F, class... Args>
int Encode(F handler, Args... args) {
    return handler(std::forward<Args>(args)...);
}

int main(void) {
    // BASE *b = new ease();

    // using namespace std::placeholders;

    // int g = 10;
    // float h = 20;

    // auto func = std::bind(&BASE::foo, b, _1, "hello,world", _2);
    // std::cout << Encode(func, g, h) << std::endl;

    const char *str = "{\"create_ts\":10, \"account\":\"hello,world\", \"verify\":true}";
    KWQueueUpTicketPayLoad payload;
    try {
        ajson::load_from_buff(payload, str);
    } catch (...) {
        std::cout << "error" << std::endl;
    }

}
