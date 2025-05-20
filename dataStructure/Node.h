#pragma once

#include<iostream>
#include <memory>

template<typename T>
class ILinkedList;

template<typename T>
class CSingleList;

template<typename T>
class Node
{
public:
	Node() :_next(nullptr), _prev(nullptr) {}
	Node(T data) :_data(data), _next(nullptr), _prev(nullptr) {}

	friend ILinkedList<T>;
	friend CSingleList<T>;

    virtual void print(std::ostream& os) const {
        os << "[data: " << _data
            << ", this: " << static_cast<const void*>(this)
            << ", next: " << static_cast<const void*>(_next.get());
        if (_prev)
            os << ", prev: " << static_cast<const void*>(_prev.get());
        os << "]";
    }

    friend std::ostream& operator<< (std::ostream& os, const Node<T>& node) {
        node.print(os);
        return os;
    }

private:
    std::shared_ptr<Node<T>> _next;
    std::shared_ptr<Node<T>> _prev;
	T _data;
};

