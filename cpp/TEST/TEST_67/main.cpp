#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

#include "zip.h"

int main(void) {
  std::set<int32_t> s = {1,2,3,4,5,6,7};

  auto it = s.begin();
  std::advance(it, s.size() - 1);

  std::cout << *it << std::endl;

  // std::vector<int32_t> v1;
  // for (int i = 0; i < 100; ++i)
  //   v1.push_back(i);

  // std::vector<int32_t>& v2 = v1;

  // std::vector<int32_t>&& v3 = std::move(v2);

  // const std::vector<int32_t> v4 = v3;

  // const std::vector<int32_t>& v5 = v4;

  // const std::vector<int32_t>&& v6 = std::move(v5);

  // std::deque<float> d1;
  // for (float i = 0; i < 100; ++i)
  //   d1.push_back(i);

  // std::deque<float>& d2 = d1;

  // std::deque<float>&& d3 = std::move(d2);

  // const std::deque<float> d4 = d3;

  // const std::deque<float>& d5 = d4;

  // const std::deque<float>&& d6 = std::move(d5);

  // std::set<double> s1;
  // for (int i = 0; i < 100; ++i) {
  //   s1.insert(i);
  // }

  // std::set<double>& s2 = s1;

  // std::set<double>&& s3 = std::move(s2);

  // const std::set<double> s4 = s3;

  // const std::set<double>& s5 = s4;

  // const std::set<double>&& s6 = std::move(s5);

  // for (auto &&[a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r] : zip(v1, v2, v3, v4, v5, v6, d1, d2, d3, d4, d5, d6, s1, s2, s3, s4, s5, s6)) {
  //   std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k << " " << l << " " << m << " " << n << " " << o << " " << p << " " << q << " " << r << std::endl;
  // }

  return EXIT_SUCCESS;
}
