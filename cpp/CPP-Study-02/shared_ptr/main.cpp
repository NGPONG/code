#include <iostream>
#include <memory>
using namespace std;

class B;

class A {
public:
  weak_ptr<B> pb_;

  ~A() {
    cout << pb_.use_count() << endl;
    cout << "A destructor\n";
  }
};

class B {
public:
  shared_ptr<A> pa_;

  ~B() {
    cout << pa_.use_count() << endl;
    cout << "B destructor\n";
  }
};

void foo() {
  shared_ptr<B> pb(new B());
  shared_ptr<A> pa(new A());
  cout << pb.use_count() << endl; /* 1 */
  cout << pa.use_count() << endl; /* 1 */
  pb->pa_ = pa;
  pa->pb_ = pb;
  cout << pb.use_count() << endl; /* 1 */
  cout << pa.use_count() << endl; /* 2 */
}

int main(void) {
  foo();

  return EXIT_SUCCESS;
}