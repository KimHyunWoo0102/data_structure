#pragma once
#include<vector>
#include<iostream>
#include<sstream>

template<typename T>
class IList
{
public:
	IList() = default;
	virtual ~IList() = default;

	virtual size_t size() const= 0;
	virtual bool isEmpty() const= 0;
	virtual const std::vector<T> getElements() const = 0; //TODO: 추후 이터레이터로 변경

	virtual const T& get(int rank) = 0;

	virtual void append(int rank, const T& element) = 0;
	void append_first(const T& element) { append(0, element); }
	void append_last(const T& element) { append(this->size(), element); }
	virtual const T& remove(int rank) = 0;
	virtual const T& remove_first() { return remove(0); }
	virtual const T& remove_last() { return remove(this->size() - 1); }
	virtual const size_t search(const T& element) = 0;
	
	virtual void print(std::ostream& os) const;

	// friend << 연산자 정의
	friend std::ostream& operator<<(std::ostream& os, const IList<T>& list) {
		list.print(os);  // 자식 클래스가 구현한 print() 호출됨
		return os;
	}
};

template<typename T>
inline void IList<T>::print(std::ostream& os) const
{
	const auto elements = this->getElements();
	os << "[";
	for (const auto& it : elements) {
		os << it << ", ";
	}
	os << "]";
}