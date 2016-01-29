#include "../src/vector.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <thread>
#include "prettyprint.hpp"

#define COUNT 1000ul
#define THREADS 50ul

void workload_adder(araxes::shared::vector<int>& input) {
    for(auto& x : input) {
        std::this_thread::yield();
        x += 1;
    }
}

int main(int argc, char* argv[]) {
    araxes::shared::vector<int> v(COUNT);
    std::vector<std::thread> workers;
    for(int i=0; i<THREADS; ++i) {
        workers.emplace_back(workload_adder, std::ref(v));
    }
    for(auto& t : workers ) {
        t.join();
    }
    // vector must contain only 1:
    int count = std::count(v.cbegin(), v.cend(), THREADS);
    std::cerr << "count= " << count << std::endl;
    std::cerr << "vector= " << v << std::endl;
    assert(count==COUNT);
}



