#include <memory>
#include <benchmark/benchmark.h>

class CustomMemoryManager: public benchmark::MemoryManager {
public:

    int64_t num_allocs;
    int64_t max_bytes_used;


    void Start() BENCHMARK_OVERRIDE {
        num_allocs = 0;
        max_bytes_used = 0;
    }

    void Stop(Result* result) BENCHMARK_OVERRIDE {
        result->num_allocs = num_allocs;
        result->max_bytes_used = max_bytes_used;
    }
};

std::unique_ptr<CustomMemoryManager> mm(new CustomMemoryManager());

#ifdef MEMORY_PROFILER
void *custom_malloc(size_t size) {
    void *p = malloc(size);
    mm.get()->num_allocs += 1;
    mm.get()->max_bytes_used += size;
    return p;
}
#define malloc(size) custom_malloc(size)
#endif


static void BM_memory(benchmark::State& state) {
    for (auto _ : state)
        for (int i =0; i < 10; i++) {
            benchmark::DoNotOptimize((int *) malloc(10 * sizeof(int *)));
        }
}

BENCHMARK(BM_memory)->Unit(benchmark::kMillisecond)->Iterations(17);

//BENCHMARK_MAIN();
int main(int argc, char** argv)
{
    ::benchmark::RegisterMemoryManager(mm.get());
    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
    ::benchmark::RegisterMemoryManager(nullptr);
}
