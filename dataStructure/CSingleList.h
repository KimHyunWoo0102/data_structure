#pragma once

#include "ILinkedList.h"
#include "Exception.h"

template<typename T>
class CSingleList : public ILinkedList<T> {
public:
	explicit CSingleList() : ILinkedList<T>() {}
	virtual ~CSingleList() = default;

	virtual const std::vector<T> getElements() const override;
	virtual const T& get(int rank) override;

	virtual void append(int rank, const T& element) override;
	virtual const T& remove(int rank) override;

	virtual const size_t search(const T& element) override;
};

// ✅ 요소 전체 반환
template<typename T>
inline const std::vector<T> CSingleList<T>::getElements() const {
	std::vector<T> ret;
	std::shared_ptr<Node<T>> current = this->_head->_next;  // dummy node 이후부터

	while (current != nullptr) {
		ret.push_back(current->_data);
		current = current->_next;
	}

	return ret;
}

// ✅ 특정 위치 요소 반환
template<typename T>
inline const T& CSingleList<T>::get(int rank) {
	std::shared_ptr<Node<T>> ret = this->getNode(rank);
	return ret->_next->_data;
}

// ✅ 삽입
template<typename T>
inline void CSingleList<T>::append(int rank, const T& element) {
	std::shared_ptr<Node<T>> current = this->getNode(rank);
	std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(element);

	newNode->_next = current->_next;
	current->_next = newNode;
	this->_size++;
}

// ✅ 삭제
template<typename T>
inline const T& CSingleList<T>::remove(int rank) {
	if (rank < 0 || rank >= this->_size) {
		throw InvalidRankException(__func__, "Rank is out of bounds!");
	}

	std::shared_ptr<Node<T>> prev = this->getNode(rank);
	std::shared_ptr<Node<T>> target = prev->_next;
	T remove_element = target->_data;
	if (target == nullptr) {
		throw InvalidRankException(__func__, "No node to remove at given rank.");
	}

	prev->_next = target->_next; // 자동으로 target의 참조 count 감소
	this->_size--;
	return remove_element;
}

// ✅ 검색
template<typename T>
inline const size_t CSingleList<T>::search(const T& element) {
	std::shared_ptr<Node<T>> current = this->_head->_next;
	size_t index = 0;

	while (current != nullptr) {
		if (current->_data == element) {
			return index;
		}
		current = current->_next;
		index++;
	}
	throw NotFoundException(__func__, "Element not found.");
}
