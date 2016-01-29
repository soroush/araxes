#include "../src/vector.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <thread>
#include "prettyprint.hpp"

#define COUNT 10000ul
#define THREADS 50ul

typedef araxes::shared::vector<int> vector_type;  // Okay
// typedef std::vector<int> vector_type;   // High probablity of segfault (or double-free)

void workload_adder(vector_type& input) {
    static int sequence = 0;
    for(int i=0; i< COUNT/THREADS; ++i) {
        input.push_back(sequence++);
    }
}

int main(int argc, char* argv[]) {
    vector_type v;
    std::vector<std::thread> workers;
    for(int i=0; i<THREADS; ++i) {
        workers.emplace_back(workload_adder, std::ref(v));
    }
    for(auto& t : workers ) {
        t.join();
    }
    int count = v.size();
    std::cerr << "count= " << count << std::endl;
    std::cerr << "vector= " << v << std::endl;
    assert(count==COUNT);
}






