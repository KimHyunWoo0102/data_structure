#pragma once
#include<vector>

template<typename T>
class IList
{
public:
	IList() = default;
	virtual ~IList() = default;

	virtual size_t size() = 0;
	virtual bool isEmpty() = 0;
	virtual const std::vector<T>& elements() const = 0; //TODO: 추후 이터레이터로 변경

	virtual const T& get(int rank) = 0;

	virtual void append(int rank, const T& element) = 0;
	void append_first(const T& element) { append(0, element); }
	void append_last(const T& element) { append(this->size() - 1, element); }
	virtual const T& remove(int rank) = 0;
	virtual const T& remove_first() { return remove(0); }
	virtual const T& remove_last() { return remove(this->size() - 1); }
	virtual const size_t search(const T& element) = 0;

};

