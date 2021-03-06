﻿#pragma once 

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
    //using reference = T&;
    //using const_reference = const T&;
    //using void_pointer = void*;
    using const_void_pointer = const void*;
    using size_type = std::size_t;
    //using difference_type = std::ptrdiff_t;
    //using propagate_on_container_move_assignment = std::true_type;

    template<typename U>
    struct rebind {
        using other = ReserveAllocator<U>;
    };

    pointer allocate(size_type n, const_void_pointer hint = nullptr) const {
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
        (void)hint;
        return reinterpret_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) const {
        std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;

        delete[] reinterpret_cast<char*>(p);
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args &&...args) const {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        new(p) U(std::forward<Args>(args)...);
    }

    template< class U >
    void destroy(U* p) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        ((T*)p)->~T();
        p->~U();
    }

    // NEED COPY CONSTRUCTOR !!!!!!!!!
};

}
