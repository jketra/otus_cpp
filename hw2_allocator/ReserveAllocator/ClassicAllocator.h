#pragma once

#include <cstddef>
#include <cstdint>

namespace hw2 {

template<typename T>
struct ClassicAllocator {
    using value_type = T;
    using size_type = std::size_t;

    // Next typedefs deprecated in C++17, removed in C++20 for std::allocator.
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    using void_pointer = void*;
    using const_void_pointer = const void_pointer;

    // rebind<> deprecated in C++17, removed in C++20 for std::allocator.
    template<typename U>
    struct rebind {
        using other = ClassicAllocator<U>;
    };

    pointer allocate(size_type n, const_void_pointer hint = nullptr) const {
        (void)hint;
        return reinterpret_cast<T*>(::operator new(n * sizeof(value_type)));
    }

    void deallocate(pointer p, size_type) const {
        delete[] reinterpret_cast<uint8_t*>(p);
    }

    // The default construct() may be absent, it can be provided by the allocator_traits.
    // Deprecated in C++17, removed in C++20 for std::allocator.
    template<typename U, typename ...Args>
    void construct(U* p, Args &&...args) const {
        new(p) U(std::forward<Args>(args)...);
    }

    // The default destroy() may be absent, it can be provided by the allocator_traits.
    // Deprecated in C++17, removed in C++20 for std::allocator.
    template<typename U>
    void destroy(U* p) {
        ((pointer)p)->~T();
        p->~U();
    }
};

// Memory can be allocated by ClassicAllocator<T1> and deallocated by ClassicAllocator<T2>.
template<typename T1, typename T2>
bool operator==(const ClassicAllocator<T1>&, const ClassicAllocator<T2>&) noexcept {
    return true;
}

template<typename T1, typename T2>
bool operator!=(const ClassicAllocator<T1>&, const ClassicAllocator<T2>&) noexcept {
    return false;
}

}
