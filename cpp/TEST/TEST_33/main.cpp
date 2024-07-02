#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <fstream>

#include <google/protobuf/text_format.h>
#include <benchmark/benchmark.h>

class KWExploreNode {
public:
  KWExploreNode() {
    mId = "";
    mWeig = -1;
    mNext = mChild = nullptr;
  }
  KWExploreNode(int32_t weig)
    : KWExploreNode() {
    mWeig = weig;
  }

public:
  struct Compare {
    bool operator()(const std::shared_ptr<KWExploreNode> l, const std::shared_ptr<KWExploreNode> r) {
      return l->GetWeight() < r->GetWeight();
    }
  };

public:
  int32_t GetWeight() const {
    return mWeig;
  }

public:
  std::string mId;
  std::shared_ptr<KWExploreNode> mNext;
  std::shared_ptr<KWExploreNode> mChild;

private:
  int32_t mWeig;
};

void print_v(const std::vector<std::shared_ptr<KWExploreNode>>& v) {
  auto it = v.begin();
  while (it != v.end()) {
    std::cout << (*it)->mId << ": " << std::endl;

    if (!(*it)->mNext) {
      std::cout << "\tnext_id: null" << std::endl;
    } else {
      std::cout << "\tnext_id: " << (*it)->mNext->mId << std::endl;
      ;
    }

    if (!(*it)->mChild) {
      std::cout << "\tchild_id: null" << std::endl;
    } else {
      std::cout << "\tchild_id: " << (*it)->mChild->mId << std::endl;
    }

    std::cout << "\tweight: " << (*it)->GetWeight() << std::endl;

    it = std::next(it);
  }
}

auto BinarySearchExploreNode(const std::vector<std::shared_ptr<KWExploreNode>> &v, int32_t weig) {
  auto comp = [](const auto &ele, int32_t weig) { return ele->GetWeight() < weig; };

  auto it = std::lower_bound(v.cbegin(), v.cend(), weig, std::move(comp));

  if (it == v.cend())
    return it;

  if (weig < (*it)->GetWeight())
    return v.cend();

  return it;
}

int32_t get_main_node_weight(const KWExploreNode &node) {
  int32_t mainNodeWeight = node.GetWeight();
  mainNodeWeight = mainNodeWeight % int32_t(std::pow(10, int32_t(std::log10(mainNodeWeight))));
  mainNodeWeight = mainNodeWeight % int32_t(std::pow(10, 3));
  mainNodeWeight = node.GetWeight() - mainNodeWeight;
  return mainNodeWeight;
}

std::vector<std::shared_ptr<KWExploreNode>> foo_BM_MOVE(benchmark::State& state) {
  state.PauseTiming();

  std::vector<std::shared_ptr<KWExploreNode>> ret;
  ret.reserve(1200);

  std::map<int32_t, decltype(ret)> tmp;

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      int32_t weight = i * 1000000 + j * 1000; 

      KWExploreNode n(weight);
      n.mId = "Node_" + std::to_string(weight);

      auto ptr = std::make_shared<KWExploreNode>(n);
      ret.push_back(std::move(ptr));
    }
  }

  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  for (auto it = ret.begin(); it != ret.end(); ++it) {
    if (std::next(it) == ret.end())
      break;

    (*it)->mNext = *std::next(it);
  }

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      for (int z = 1; z <= 99; ++z) {
        int32_t weight = i * 1000000 + j * 1000;

        KWExploreNode node(weight + z);
        node.mId = "Node_" + std::to_string(weight) + "_" + std::to_string(z);

        auto ptr = std::make_shared<KWExploreNode>(node);
        tmp[get_main_node_weight(node)].push_back(std::make_shared<KWExploreNode>(node));
      }
    }
  }

  for (auto &[weig, nodes] : tmp) {
    std::sort(nodes.begin(), nodes.end(), KWExploreNode::Compare());

    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
      if (std::next(it) == nodes.end())
        break;

      (*it)->mNext = *std::next(it);
    }

    auto it = BinarySearchExploreNode(ret, weig);
    if (it == ret.end())
      continue;

    (*it)->mChild = nodes.front();
  }

  state.ResumeTiming();

  for (auto &[_, nodes] : tmp) {
    ret.insert(ret.end(),
        std::make_move_iterator(nodes.begin()),
        std::make_move_iterator(nodes.end()));
  }
  
  state.PauseTiming();
  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  state.ResumeTiming();

  return ret;
}

static void BM_MOVE(benchmark::State& state) {
  for (auto _ : state) {
    auto ret = foo_BM_MOVE(state);
  }
}
BENCHMARK(BM_MOVE);
BENCHMARK(BM_MOVE);
BENCHMARK(BM_MOVE);

std::vector<std::shared_ptr<KWExploreNode>> foo_BM_COPY(benchmark::State& state) {
  state.PauseTiming();

  std::vector<std::shared_ptr<KWExploreNode>> ret;
  ret.reserve(1200);

  std::map<int32_t, decltype(ret)> tmp;

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      int32_t weight = i * 1000000 + j * 1000; 

      KWExploreNode n(weight);
      n.mId = "Node_" + std::to_string(weight);

      auto ptr = std::make_shared<KWExploreNode>(n);
      ret.push_back(std::move(ptr));
    }
  }

  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  for (auto it = ret.begin(); it != ret.end(); ++it) {
    if (std::next(it) == ret.end())
      break;

    (*it)->mNext = *std::next(it);
  }

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      for (int z = 1; z <= 99; ++z) {
        int32_t weight = i * 1000000 + j * 1000;

        KWExploreNode node(weight + z);
        node.mId = "Node_" + std::to_string(weight) + "_" + std::to_string(z);

        auto ptr = std::make_shared<KWExploreNode>(node);
        tmp[get_main_node_weight(node)].push_back(std::make_shared<KWExploreNode>(node));
      }
    }
  }

  for (auto &[weig, nodes] : tmp) {
    std::sort(nodes.begin(), nodes.end(), KWExploreNode::Compare());

    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
      if (std::next(it) == nodes.end())
        break;

      (*it)->mNext = *std::next(it);
    }

    auto it = BinarySearchExploreNode(ret, weig);
    if (it == ret.end())
      continue;

    (*it)->mChild = nodes.front();
  }

  state.ResumeTiming();

  for (auto &[_, nodes] : tmp) {
    std::copy(nodes.begin(), nodes.end(), std::back_inserter(ret));
  }

  state.PauseTiming();
  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  state.ResumeTiming();

  return ret;
}

static void BM_COPY(benchmark::State& state) {
  for (auto _ : state) {
    auto ret = foo_BM_COPY(state);
  }
}
BENCHMARK(BM_COPY);
BENCHMARK(BM_COPY);
BENCHMARK(BM_COPY);

std::vector<std::shared_ptr<KWExploreNode>> foo_BM_RANGE_MOVE(benchmark::State& state) {
  state.PauseTiming();

  std::vector<std::shared_ptr<KWExploreNode>> ret;
  ret.reserve(1200);

  std::map<int32_t, decltype(ret)> tmp;

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      int32_t weight = i * 1000000 + j * 1000; 

      KWExploreNode n(weight);
      n.mId = "Node_" + std::to_string(weight);

      auto ptr = std::make_shared<KWExploreNode>(n);
      ret.push_back(std::move(ptr));
    }
  }

  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  for (auto it = ret.begin(); it != ret.end(); ++it) {
    if (std::next(it) == ret.end())
      break;

    (*it)->mNext = *std::next(it);
  }

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      for (int z = 1; z <= 99; ++z) {
        int32_t weight = i * 1000000 + j * 1000;

        KWExploreNode node(weight + z);
        node.mId = "Node_" + std::to_string(weight) + "_" + std::to_string(z);

        auto ptr = std::make_shared<KWExploreNode>(node);
        tmp[get_main_node_weight(node)].push_back(std::make_shared<KWExploreNode>(node));
      }
    }
  }

  for (auto &[weig, nodes] : tmp) {
    std::sort(nodes.begin(), nodes.end(), KWExploreNode::Compare());

    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
      if (std::next(it) == nodes.end())
        break;

      (*it)->mNext = *std::next(it);
    }

    auto it = BinarySearchExploreNode(ret, weig);
    if (it == ret.end())
      continue;

    (*it)->mChild = nodes.front();
  }

  state.ResumeTiming();

  for (auto &[_, nodes] : tmp) {
    std::ranges::move(nodes, std::back_inserter(ret));
  }

  state.PauseTiming();
  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  state.ResumeTiming();

  return ret;
}

static void BM_RANGE_MOVE(benchmark::State& state) {
  for (auto _ : state) {
    auto ret = foo_BM_RANGE_MOVE(state);
  }
}
BENCHMARK(BM_RANGE_MOVE);
BENCHMARK(BM_RANGE_MOVE);
BENCHMARK(BM_RANGE_MOVE);

std::vector<std::shared_ptr<KWExploreNode>> foo_BM_insert(benchmark::State& state) {
  state.PauseTiming();

  std::vector<std::shared_ptr<KWExploreNode>> ret;
  ret.reserve(1200);

  std::map<int32_t, decltype(ret)> tmp;

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      int32_t weight = i * 1000000 + j * 1000; 

      KWExploreNode n(weight);
      n.mId = "Node_" + std::to_string(weight);

      auto ptr = std::make_shared<KWExploreNode>(n);
      ret.push_back(std::move(ptr));
    }
  }

  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  for (auto it = ret.begin(); it != ret.end(); ++it) {
    if (std::next(it) == ret.end())
      break;

    (*it)->mNext = *std::next(it);
  }

  for (int i = 1; i <= 2; ++i) {
    for (int j = 0; j <= 5; ++j) {
      for (int z = 1; z <= 99; ++z) {
        int32_t weight = i * 1000000 + j * 1000;

        KWExploreNode node(weight + z);
        node.mId = "Node_" + std::to_string(weight) + "_" + std::to_string(z);

        auto ptr = std::make_shared<KWExploreNode>(node);
        tmp[get_main_node_weight(node)].push_back(std::make_shared<KWExploreNode>(node));
      }
    }
  }

  for (auto &[weig, nodes] : tmp) {
    std::sort(nodes.begin(), nodes.end(), KWExploreNode::Compare());

    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
      if (std::next(it) == nodes.end())
        break;

      (*it)->mNext = *std::next(it);
    }

    auto it = BinarySearchExploreNode(ret, weig);
    if (it == ret.end())
      continue;

    (*it)->mChild = nodes.front();
  }

  state.ResumeTiming();

  for (auto &[_, nodes] : tmp) {
    ret.insert(ret.end(), nodes.begin(), nodes.end());
  }

  state.PauseTiming();
  std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
  state.ResumeTiming();

  return ret;
}

static void BM_INSERT(benchmark::State& state) {
  for (auto _ : state) {
    auto ret = foo_BM_insert(state);
  }
}
BENCHMARK(BM_INSERT);
BENCHMARK(BM_INSERT);
BENCHMARK(BM_INSERT);

BENCHMARK_MAIN();

// std::vector<std::shared_ptr<KWExploreNode>> foo() {
//   std::vector<std::shared_ptr<KWExploreNode>> ret;

//   std::map<int32_t, decltype(ret)> tmp;

//   for (int i = 1; i <= 2; ++i) {
//     for (int j = 0; j <= 5; ++j) {
//       int32_t weight = i * 1000000 + j * 1000;

//       KWExploreNode n(weight);
//       n.mId = "Node_" + std::to_string(weight);

//       auto ptr = std::make_shared<KWExploreNode>(n);
//       ret.push_back(std::move(ptr));
//     }
//   }

//   std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());
//   for (auto it = ret.begin(); it != ret.end(); ++it) {
//     if (std::next(it) == ret.end())
//       break;

//     (*it)->mNext = *std::next(it);
//   }

//   for (int i = 1; i <= 2; ++i) {
//     for (int j = 0; j <= 5; ++j) {
//       for (int z = 1; z <= 99; ++z) {
//         int32_t weight = i * 1000000 + j * 1000;

//         KWExploreNode node(weight + z);
//         node.mId = "Node_" + std::to_string(weight) + "_" + std::to_string(z);

//         auto ptr = std::make_shared<KWExploreNode>(node);
//         tmp[get_main_node_weight(node)].push_back(std::make_shared<KWExploreNode>(node));
//       }
//     }
//   }

//   for (auto &[weig, nodes] : tmp) {
//     std::sort(nodes.begin(), nodes.end(), KWExploreNode::Compare());

//     for (auto it = nodes.begin(); it != nodes.end(); ++it) {
//       if (std::next(it) == nodes.end())
//         break;

//       (*it)->mNext = *std::next(it);
//     }

//     auto it = BinarySearchExploreNode(ret, weig);
//     if (it == ret.end())
//       continue;

//     (*it)->mChild = nodes.front();
//   }

//   for (auto &[_, nodes] : tmp) {
//     ret.insert(ret.end(),
//         std::make_move_iterator(nodes.begin()),
//         std::make_move_iterator(nodes.end()));
//   }
//   std::sort(ret.begin(), ret.end(), KWExploreNode::Compare());

//   std::cout << ret.size() << std::endl;
//   std::cout << ret.capacity() << std::endl;

//   return ret;
// }

// int main(void) {
//   std::ofstream of("main.out");
//   std::cout.rdbuf(of.rdbuf());

//   auto v = foo();
//   print_v(v);

//   of.flush();
//   of.close();

//   return EXIT_SUCCESS;
// }
