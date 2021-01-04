#include <iostream>
#include <set>

/* binary functor */
template<class _Ty>
struct __DESC {
  constexpr bool operator()(const _Ty &left, const _Ty &right) {
    return left > right;
  }
};

int main(void) {
  /* set<T,F = less<T>>() */
  std::set<int> __s_nor;

  /* set<T,F = less<T>>((V _begin, V _end) */
  int nums[5] = { 3, 1, 5, 2, 4 };
  std::set<int, __DESC<int>> __s(nums, nums + sizeof(nums) / sizeof(int));

  /* set(const set &__s) */
  std::set<int, __DESC<int>> __s_des(__s);
}
