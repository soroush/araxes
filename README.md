# libaraxes
Araxes is a C++ library of lock-free, thread-safe data structures.

Well, it's not actually **lock-free** though all synchronization mechanisms are hidden from user.

# Installation
Araxes is a header-only library. You can either install pre-configured packages or install the library from source.

# Compile
## Linux

    ./configure --prefix=/usr/local
    # No need to do a make
    make check # Optional, though recommended
    sudo make install

#Usage
All containers in libaraxes have exact same API with their equivalent std containers. For example you may use `deque` like this:

    araxes::lockfree::shared::deque<int> d;
    araxes::lockfree::exclusive::deque<int> x;
    d.push_front(1);
    d.push_back(2);
    std::cout << d.size();
    for(const auto& i : d) {
        std::cout << i << std::endl;
    }
    std::sort(d.begin(), d.end());
    x = d;
    // ... and so on


