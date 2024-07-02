#include <iostream>
#include <vector>
#include <functional>
#include <tuple>
#include <string>
#include <map>
#include <unistd.h>

class TicketTimeoutCallbackInfo {
public:
  TicketTimeoutCallbackInfo(int timerid, std::function<void(const std::string &)> &&cb)
    : TimerId(timerid), CB(std::move(cb)) {
        std::cout << "constructor" << std::endl;
    }
  TicketTimeoutCallbackInfo(TicketTimeoutCallbackInfo &&obj)
    : TimerId(obj.TimerId), CB(std::move(obj.CB)) {
        std::cout << "move constructor" << std::endl;
    }
  TicketTimeoutCallbackInfo(const TicketTimeoutCallbackInfo &obj)
    : TimerId(obj.TimerId), CB(std::move(obj.CB)) {
        std::cout << "copy constructor" << std::endl;
    }

public:
  int TimerId;
  std::function<void(const std::string &ticket)>&& CB;
};

std::map<std::string, TicketTimeoutCallbackInfo> mTimerCache;

class BASE1 {
public:
    void SetTicketTimer(const std::string& ticket, 
            std::function<void(const std::string& ticket)>&& onTicketCheckTimeOut)
    {
        onTicketCheckTimeOut("4");

        mTimerCache.emplace(std::piecewise_construct,
                std::forward_as_tuple(ticket),
                std::forward_as_tuple(1, std::move(onTicketCheckTimeOut)));
    }

    void OnTicketTimeOut(const std::string &ticket) {
        auto it = mTimerCache.find(ticket);
        if (it == mTimerCache.end())
            return;

        TicketTimeoutCallbackInfo obj(std::move(it->second));

        obj.CB(ticket);
    }
};

class BASE2 {
public:
    void SetTicketTimer(const std::string &ticket) {
        b1.SetTicketTimer(ticket, std::move(ff));
    }

    void OnTicketTimeOut(const std::string &ticket) {
        std::cout << ticket << std::endl;
    }

    std::function<void(const std::string& ticket)> ff = std::bind(&BASE2::OnTicketTimeOut, this, std::placeholders::_1);

    BASE1 b1;
};

int main(void) {
    BASE2 b2;

    b2.SetTicketTimer("NGPONG");
    auto it = mTimerCache.find("NGPONG");

    auto &&obj = std::move(it->second);

    obj.CB("NGPONG");

  return EXIT_SUCCESS;
}
