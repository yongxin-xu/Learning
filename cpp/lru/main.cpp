#include "lru.hpp"

int main() {
    LRUCache lc(2);
    assert(lc.get(1) == -1);
    assert(lc.get(1) == -1);
    lc.put(1, 1);
    lc.put(2, 2);
    assert(lc.get(1) == 1);
    lc.put(3, 3);
    assert(lc.get(2) == -1);
    assert(lc.get(3) == 3);


    std::cout << "All tests are passed" << std::endl;
    return 0;
}