#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <thread>
int main()
{
    std::vector<int> coll;
    coll.reserve(10000);
    for (int i = 0; i < 10000; ++i) {
        coll.push_back(i);
    }

    std::for_each(std::execution::par_unseq,
        coll.begin(), coll.end(),
        [](auto& val) {
            std::cout << std::this_thread::get_id() << std::endl;
            val *= val;
        });
}
