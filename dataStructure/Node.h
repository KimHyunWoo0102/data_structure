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
        // weak_ptr�� lock�Ͽ� shared_ptr�� ��ȯ
        auto shared_node = node.lock();

        // shared_ptr�� ��ȿ���� Ȯ�� (��, ��ü�� ������ �����ϴ��� Ȯ��)
        if (!shared_node) {
            return os << "[nullptr]";
        }

        // �����Ϳ� �ٸ� ������ ���
        os << "[data: " << shared_node->_data
            << ", this: " << static_cast<void*>(shared_node.get())
            << ", next: " << static_cast<void*>(shared_node->_next);

        // ���� ��带 Ȯ�� (����� ���� ����Ʈ�� ���)
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

