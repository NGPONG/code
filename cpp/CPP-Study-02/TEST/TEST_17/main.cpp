#include <iostream>
#include <string>
#include <sstream>

#include <google/protobuf/text_format.h>
#include <benchmark/benchmark.h>

#include "kwmsgshare.pb.h"
#include "kwmsgbase.pb.h"
#include "kwmsgdefine.pb.h"

static void BM_1(benchmark::State& state) {
  KWMsg::ReqInitMainRoleName pkg;
  pkg.set_name("NGPONG");
  pkg.set_is_random_name(true);

  for (auto _ : state) {
    std::ostringstream log;
    
    log << pkg.ShortDebugString();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_1);

// Define another benchmark
static void BM_2(benchmark::State& state) {
  KWMsg::ReqInitMainRoleName pkg;
  pkg.set_name("NGPONG");
  pkg.set_is_random_name(true);

  for (auto _ : state) {
    std::ostringstream log;
    log << "name " << pkg.name() << " is_random_name " << pkg.is_random_name();
  }
}
BENCHMARK(BM_2);

BENCHMARK_MAIN();
