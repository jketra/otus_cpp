#pragma once 

#include <cstddef>
#include <vector>
#include <iostream>

#ifdef _WIN32
    #define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

namespace hw2 {

template<typename T/*, size_t size_*/>
struct ReserveAllocator {
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using propagate_on_container_move_assignment = std::true_type;

    template<typename U>
    struct rebind {
        typedef ReserveAllocator<U> other;
        //using other = ReserveAllocator<U>;
    };

    T* allocate(std::size_t n, const void* hint = 0) const {
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
        auto p = std::malloc(n * sizeof(T));
        if (!p)
            throw std::bad_alloc();
        return reinterpret_cast<T*>(p);
    }

    void deallocate(T* p, std::size_t n) const {
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
        std::free(p);
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args &&...args) const {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        new(p) U(std::forward<Args>(args)...);
    };

    template< class U >
    void destroy(U* p) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        ((T*)p)->~T();
        p->~U();
    }
};

}
