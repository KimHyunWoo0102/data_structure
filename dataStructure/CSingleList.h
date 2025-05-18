#pragma once

#include"ILinkedList.h"
#include "Exception.h"

template<typename T>
class CSingleList :public ILinkedList<T> {
public:
	explicit CSingleList():ILinkedList<T>(){}
	virtual ~CSingleList();

	virtual const std::vector<T> getElements() const; //TODO: 추후 이터레이터로 변경
	virtual const T& get(int rank);

	virtual void append(int rank, const T& element);
	virtual const T& remove(int rank);

	virtual const size_t search(const T& element);
private:

};

template<typename T>
inline CSingleList<T>::~CSingleList()
{
	Node<T>* current = this->_head;
	while (current != nullptr) {
		Node<T>* next = current->_next;
		delete current;
		current = next;
	}
	this->_head = nullptr;
	this->_size = 0;
}

template<typename T>
inline const std::vector<T> CSingleList<T>::getElements() const
{
	std::vector<T> ret;
	Node<T>* current = this->_head->_next;  // assuming _head is a dummy/sentinel node

	while (current != nullptr) {
		ret.push_back(current->_data); // assuming Node has member 'data'
		current = current->_next;
	}

	return ret;
}


template<typename T>
inline const T& CSingleList<T>::get(int rank)
try{
	const Node<T>* ret = this->getNode(rank);
	return ret->_data;
	// TODO: 여기에 return 문을 삽입합니다.
}
catch (InvalidRankException& e) {
	throw;
}

template<typename T>
inline void CSingleList<T>::append(int rank, const T& element)
{
	Node<T>* current = this->getNode(rank);
	Node<T>* newNode = new Node<T>(element);

	newNode->_next = current->_next;
	current->_next = newNode;
	this->_size++;
}

template<typename T>
inline const T& CSingleList<T>::remove(int rank)
{
	// TODO: 여기에 return 문을 삽입합니다.
	return rank;
}

template<typename T>
inline const size_t CSingleList<T>::search(const T& element)
{
	return size_t();
}
