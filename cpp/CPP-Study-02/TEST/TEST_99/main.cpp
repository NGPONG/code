#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <iomanip>
#include <thread>
#include <sstream>

using namespace std::chrono_literals;

std::string get_time() {
	auto now = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  auto tm = *std::gmtime(&time);
  // auto tm = *std::localtime(&time);

  auto epoch = now.time_since_epoch();
  auto us = std::chrono::duration_cast<std::chrono::microseconds>(epoch).count() % 1000000;

  std::stringstream ss;

  ss << std::put_time(&tm, "%F %T.") << us << std::put_time(&tm, " %Z");

  return ss.str();
}

class BASE {
public:
  static auto GetInstance() {
    std::this_thread::sleep_for(100ms);

    std::cout << "[" << std::this_thread::get_id() << "]" << std::endl;
    std::shared_ptr<BASE> p { new BASE() };

    return p;
  }

  ~BASE() {
    std::cout << "BASE destructor" << std::endl;
  }

private:
  BASE() {
    std::this_thread::sleep_for(1000ms);
    std::cout << "BASE constructor" << std::endl;
  }
};

void thread_handler() {
  auto b = BASE::GetInstance();
}

int main (int argc, char *argv[]) {
  std::thread t1(thread_handler);
  std::thread t2(thread_handler);

  t1.join();
  t2.join();

  return 0;
}
