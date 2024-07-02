#include <iostream>

class ClassName {
public:
  explicit ClassName(int Member)
    : member_(Member) {}

  int FunctionName(int one, int two) {
    return (++member_ + one) * two;
  }

private:
  int member_;
};

// class to capture the caller and print it.
class ClassNameDecorator {
public:
  ClassNameDecorator(int Member)
    : className_(Member) {}

  ClassNameDecorator &FunctionName(std::string Caller, std::string File, int Line) {
    std::cout
      << "Reporter: ClassName::FunctionName() is being called by "
      << Caller << "() in " << File << ":" << Line << std::endl;
    return *this;
  }
  int operator()(int one, int two) {
    return className_.FunctionName(one, two);
  }

private:
  ClassName className_;
};

// remove the symbol for the function, then define a new version that instead
// creates a stack temporary instance of ClassNameDecorator.
// FunctionName is then replaced with a version that takes the caller information
// and uses Method Chaining to allow operator() to be invoked with the original
// parameters.
#undef ClassName
#define ClassName ClassNameDecorator
#undef FunctionName
#define FunctionName FunctionName(__FUNCTION__, __FILE__, __LINE__)


void Caller1() {
  ClassName foo(21);
  int val = foo.FunctionName(7, 9);  // <-- works for captured return value
  std::cout << "Mystery Function got " << val << std::endl;
}

void Caller2() {
  ClassName foo(42);
  // Works for inline as well.
  std::cout << "Mystery Function got " << foo.FunctionName(11, 13) << std::endl;
}

int main(int argc, char **argv) {
  Caller1();
  Caller2();
  return 0;
}
