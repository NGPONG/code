#include <iostream>
#include <vector>
using namespace std;


int main(void) {
  vector<bool> v;
  v.push_back(true);

  /* class std::_Vb_reference<struct std::_Wrap_alloc<class std::allocator<unsigned int> > > */
  auto var = v[0];
  cout << typeid(var).name() << endl;

  return EXIT_SUCCESS;
}