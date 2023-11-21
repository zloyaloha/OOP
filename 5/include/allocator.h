#include <iostream>
#include <cstdint>
#include <vector>


template<class T>
class PoolAllocator {
    private:
        static constexpr size_t POOL_SIZE = 1024;
        std::vector<T*> _pool;
        std::vector<T**> _free;
    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        PoolAllocator();

};

template <typename T>
PoolAllocator::PoolAllocator(){
    _pool.reserve(POOL_SIZE);
}