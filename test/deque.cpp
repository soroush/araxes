#include "../src/deque.hpp"
#include  <cassert>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {
        araxes::shared::deque<int> d;
        d.push_front(5);
        d.push_front(6);
        d.push_front(7);
        d.push_front(8);
        d.push_front(9);
        d.push_front(10);
        d.push_back(4);
        d.push_back(3);
        d.push_back(2);
        d.push_back(1);
        assert(d.size()==10);
        assert(d.front()==10);
        assert(d.back()==1);
        d.pop_front();
        assert(d.size()==9);
        assert(d.front()==9);
        assert(d.back()==1);
        d.pop_back();
        assert(d.size()==8);
        assert(d.front()==9);
        assert(d.back()==2);
        d.pop_back();
        assert(d.size()==7);
        assert(d.front()==9);
        assert(d.back()==3);
        assert(d.empty()!=true);
        for(const auto& i : d) {
                std::cout << i << std::endl;
        }
        std::sort(d.begin(), d.end());
}
