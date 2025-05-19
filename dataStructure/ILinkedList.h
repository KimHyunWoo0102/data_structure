#pragma once

#include <memory>
#include "Node.h"
#include "IList.h"
#include "Exception.h"

template<typename T>
class ILinkedList : public IList<T> {
public:
	ILinkedList() : _size(0), IList<T>() {
		_head = std::make_shared<Node<T>>(); // dummy head
	}

	virtual ~ILinkedList() = default;

	size_t size() const override { return _size; }

	bool isEmpty() const override {
		std::cout << "isEmpty: this = " << this << ", _head = " << _head.get() << std::endl;
		return _head->_next == nullptr;
	}

	virtual const std::vector<T> getElements() const = 0; // TODO: 추후 이터레이터로 변경
	virtual const T& get(int rank) = 0;
	virtual std::shared_ptr<Node<T>> getNode(int rank);
	virtual std::shared_ptr<Node<T>> getHead();
	virtual void append(int rank, const T& element) = 0;
	virtual const T& remove(int rank) = 0;

	virtual const size_t search(const T& element) = 0;

protected:
	std::shared_ptr<Node<T>> _head;
	size_t _size;
};

template<typename T>
inline std::shared_ptr<Node<T>> ILinkedList<T>::getNode(int rank)
{
	if (rank < 0 || rank > this->size()) {
		throw InvalidRankException(__func__, "Rank is out of bounds!");
	}

	std::shared_ptr<Node<T>> current = this->_head;

	if (this->isEmpty())
		throw InvalidRankException(__func__, "list is Empty");
	for (int i = 0; i <= rank; i++) {
		current = current->_next;
	}

	return current;
}

template<typename T>
inline std::shared_ptr<Node<T>> ILinkedList<T>::getHead()
{
	return _head;
}
