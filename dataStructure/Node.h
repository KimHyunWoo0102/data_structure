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
        // nullptr을 처리
        if (node == nullptr) {
            return os << "[nullptr]";
        }

        os << "[data : " << node->_data << ", next : " << node->_next;

        // _prev를 _prev로 수정
        if (node->_prev == nullptr)
            return os << "]";
        else
            return os << ", prev : " << node->_prev << "]";
    }

private:
	Node<T>* _next;
	Node<T>* _prev;
	T _data;
};

