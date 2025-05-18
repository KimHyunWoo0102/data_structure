#pragma once

#include<iostream>

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

    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const Node<T>* node) {
        if (node == nullptr) {
            return os << "[nullptr]";
        }

        os << "[data: " << node->_data
            << ", this: " << static_cast<const void*>(node)
            << ", next: " << static_cast<const void*>(node->_next);

        if (node->_prev == nullptr)
            return os << "]";
        else
            return os << ", prev: " << static_cast<const void*>(node->_prev) << "]";
    }


private:
	Node<T>* _next;
	Node<T>* _prev;
	T _data;
};

