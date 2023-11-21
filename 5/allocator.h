#include <iostream>
#include <cstdint>
#include <vector>


template<class T>
class PoolAllocator {
    private:

        static constexpr size_t _size = 1024;
        std::vector<T> _pool;
        std::vector<T*> _free;

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    PoolAllocator() {
        _pool.reserve(_size);
        for (size_t i = 0; i < _size; i++) {
            _free.push_back(&_pool[i]);
        }
    }

    ~PoolAllocator() = default;

    template<class U>
    struct rebind {
        using value = PoolAllocator<U>;
    };

    T* allocate(size_t n) {
        if (_free.size() < n) {
            throw std::bad_alloc();
        }
        T* tmp = _free.back();
        for (size_t i = 0; i < n; ++i) {
            _free.pop_back();
        }
        return tmp;
    }

    void deallocate(T *p, size_t n) {
        for (size_t i = 0; i < n; ++i) {
            _free.push_back(p + i * sizeof(T));
        }
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

};