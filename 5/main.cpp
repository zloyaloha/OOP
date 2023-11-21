#include "allocator.h"

int main() {
    PoolAllocator<int> test;
    int *ptr = test.allocate(5);
    test.allocate(1);
    test.allocate(1);
    test.allocate(1);
    test.allocate(1);
    test.allocate(1);
}