#include <iostream>
#include <string>
#include <dlfcn.h>
#include <memory>

std::int32_t g_val = 1024;

// void fix();

typedef std::int32_t (* foo_fp)(std::int32_t);
typedef void (* bar_fp)(void);

template<typename ... Args>
std::string string_format( const std::string& format, Args ... args )
{
    int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    std::unique_ptr<char[]> buf( new char[ size ] );
    std::snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}

void show_main() {
  std::cout << "------------------------------" << std::endl;

  std::cout << "main.cpp *g_val: " << g_val << std::endl;
  std::cout << "main.cpp &g_val: " << &g_val << std::endl;

  std::cout << "------------------------------" << std::endl;
}

void show_test(std::int32_t idx) {
  std::cout << "------------------------------" << std::endl;

  const std::string& path = string_format("/home/ngpong/code/cpp/CPP-Study-02/TEST/TEST_97/libtest%d.so", idx); 

  std::cout << path << std::endl;

  void *handler = dlopen(path.c_str(), RTLD_GLOBAL | RTLD_NOW); // RTLD_GLOBAL

  bar_fp handler_bar = (bar_fp)dlsym(handler, "bar");
  std::int32_t *handler_g_val = (std::int32_t *)dlsym(handler, "g_val"); 
 
  std::cout << "main.cpp handler: " << handler << std::endl;
  std::cout << "main.cpp handler::bar(): " << (void *)handler_bar << std::endl;
  std::cout << "main.cpp handler::*g_val: " << *handler_g_val << std::endl;
  std::cout << "main.cpp handler::&g_val: " << (void *)handler_g_val << std::endl;
  std::cout << std::endl;

  handler_bar();

  // dlclose(handler);

  std::cout << "------------------------------" << std::endl;
}

int main(int argc, char *argv[]) {
  show_main();
  show_test(1);
  show_test(2);

  // fix();

  return 0;
}
