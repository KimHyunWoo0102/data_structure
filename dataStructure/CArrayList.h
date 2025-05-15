#pragma once
#include "IList.h"
#include "Exception.h"
#include <vector>

constexpr size_t NOT_FOUND = -1;

template<typename T>
class CArrayList : public IList<T>
{
public:
    explicit CArrayList(const size_t& max_allocation)
        : _max_allocation(max_allocation), _current_index(0)
    {
        _arr = new T[max_allocation];
    }
    ~CArrayList() { delete[] _arr; }

    size_t size() override { return _current_index; }
    bool isEmpty() override { return _current_index == 0; }

    const std::vector<T> getElements() const override;
    const T& get(int rank) override;

    void append(int rank, const T& element) override;
    const T& remove(int rank) override;
    const size_t search(const T& element) override;
private:
    size_t _max_allocation;
    size_t _current_index;
    T* _arr;
};

template<typename T>
const std::vector<T> CArrayList<T>::getElements() const
{
    std::vector<T> ret;
    for (size_t i = 0; i < _current_index; ++i) {
        ret.push_back(_arr[i]);
    }
    return ret;
}

template<typename T>
const T& CArrayList<T>::get(int rank)
{
    if (rank < 0 || rank >= static_cast<int>(_current_index))
        throw InvalidRankException(__func__);
    return _arr[rank];
}

template<typename T>
void CArrayList<T>::append(int rank, const T& element)
{
    if (_current_index >= _max_allocation)
        throw FullListException(__func__);

    if (rank < 0 || rank > static_cast<int>(_current_index))
        throw InvalidRankException(__func__);

    for (int i = static_cast<int>(_current_index) - 1; i >= rank; --i) {
        _arr[i + 1] = _arr[i];
    }

    _arr[rank] = element;
    _current_index++;
}

template<typename T>
const T& CArrayList<T>::remove(int rank)
{
    if (rank < 0 || rank >= static_cast<int>(_current_index))
        throw InvalidRankException(__func__);

    const T e = _arr[rank];

    for (size_t i = rank; i < _current_index - 1; ++i) {
        _arr[i] = _arr[i + 1];
    }
    _current_index--;

    return e;
}

template<typename T>
const size_t CArrayList<T>::search(const T& element)
{
    if (isEmpty())
        return NOT_FOUND;

    for (size_t i = 0; i < _current_index; ++i) {
        if (_arr[i] == element)
            return i;
    }

    return NOT_FOUND; // Not found
}

