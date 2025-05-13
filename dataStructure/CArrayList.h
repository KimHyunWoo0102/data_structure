#pragma once
#include"IList.h"

template<typename T>
class CArrayList :public IList<T>
{
public:

private:
	size_t _size;
	T* _arr;
};

