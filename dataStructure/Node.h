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

    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const std::weak_ptr<Node<T>>& node) {
        // weak_ptr을 lock하여 shared_ptr로 변환
        auto shared_node = node.lock();

        // shared_ptr이 유효한지 확인 (즉, 객체가 여전히 존재하는지 확인)
        if (!shared_node) {
            return os << "[nullptr]";
        }

        // 데이터와 다른 정보를 출력
        os << "[data: " << shared_node->_data
            << ", this: " << static_cast<void*>(shared_node.get())
            << ", next: " << static_cast<void*>(shared_node->_next);

        // 이전 노드를 확인 (양방향 연결 리스트인 경우)
        if (shared_node->_prev == nullptr)
            return os << "]";
        else
            return os << ", prev: " << static_cast<const void*>(shared_node->_prev) << "]";
    }



private:
    std::shared_ptr<Node<T>> _next;
    std::shared_ptr<Node<T>> _prev;
	T _data;
};

