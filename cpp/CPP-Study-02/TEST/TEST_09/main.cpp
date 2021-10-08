#include <iostream>
#include <algorithm>
#include <deque>
#include <functional>

int *foo(void) {
    int i = 10;
    return &i;
}

int main(void) {
    int *i = foo();

    *i = 256;

  return -1;
}
