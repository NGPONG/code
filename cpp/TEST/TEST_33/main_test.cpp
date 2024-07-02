#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

#include <google/protobuf/text_format.h>
#include <benchmark/benchmark.h>

class Node {
public:
  int32_t weig;
  std::string id;
  bool is_child = false;

  std::shared_ptr<Node> next = nullptr;
  std::shared_ptr<Node> child = nullptr;

  bool operator<(const Node& cmp) { 
    return weig < cmp.weig;
  }
};

static void BM_1(benchmark::State& state) {
  std::vector<std::shared_ptr<Node>> ret;

  int32_t idx = 0;
  for (auto _ : state) {
    Node n;
    n.weig = 100 + idx * 10;
    n.id = "Node_100" + std::to_string(idx);
    
    auto ptr = std::make_shared<Node>(n);
    ret.push_back(std::move(ptr));

    ++idx;
  }
}
BENCHMARK(BM_1);

static void BM_2(benchmark::State& state) {
  std::vector<std::shared_ptr<Node>> ret;

  int32_t idx = 0;
  for (auto _ : state) {
    Node n;
    n.weig = 100 + idx * 10;
    n.id = "Node_100" + std::to_string(idx);
    
    ret.push_back(std::make_shared<Node>(n));

    ++idx;
  }
}

BENCHMARK_MAIN();
BENCHMARK(BM_2);
