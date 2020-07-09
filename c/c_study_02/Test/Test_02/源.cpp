#include <iostream>
#include <typeinfo>
using namespace std;

int main() {

    int a = 10;
    int *p = &a;
    int **pp = &p;

    cout << typeid(pp).name() << endl;;
    return 0;
}