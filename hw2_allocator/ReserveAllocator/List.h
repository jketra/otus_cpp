#pragma once
#include <list>
#include <memory>

#include <iostream>

namespace hw2 {

template <class T, class Allocator = std::allocator<T>>
class List {
    struct Node {
        Node* prev{ nullptr };
        Node* next{ nullptr };
        T value;
    };

    using alloc_traits = std::allocator_traits<Allocator>;
    using NodeAllocator = typename alloc_traits::template rebind_alloc<Node>;
    using node_alloc_traits = typename alloc_traits::template rebind_traits<Node>;

public:
    using allocator_type = Allocator;
    using value_type = T;

    void push_front(const value_type& v) {
        Node *n = node_alloc_traits::allocate(_allocator, 1);
        node_alloc_traits::construct(_allocator, &n->value, v);
        n->next = _head;
        _head = n;
        if (!_tail)
            _tail = n;
    }

    Node* begin() {
        return _head;
    }

    Node* end() {
        return nullptr;
    }

private:
    NodeAllocator _allocator;

    Node* _head{ nullptr };
    Node* _tail{ nullptr };
};

}
