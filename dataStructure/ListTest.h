#pragma once
#include "IList.h"
#include "Exception.h"
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
class ListTest {
public:
    ListTest(IList<T>& list, const std::vector<T>& test_case)
        : _list(list), _test_case(test_case) {
    }
    ~ListTest() = default;

    void TestList();
    void testListInitialization();
    void testListAppend();
    void testListRemove();

private:
    void appendAndCheck(const T& element, bool isFront);

    IList<T>& _list;
    std::vector<T> _test_case;
};

// 전체 테스트 수행
template<typename T>
inline void ListTest<T>::TestList()
try {
    testListInitialization();
    testListAppend();
    testListRemove();
}
catch (const InitializationFailureException& e) {
    std::cerr << "Initialization test failed: " << e.what() << std::endl;
}
catch (const AppendFailureException& e) {
    std::cerr << "Append test failed: " << e.what() << std::endl;
}
catch (const RemoveFailureException& e) {
    std::cerr << "Remove test failed: " << e.what() << std::endl;
}
catch (const std::exception& e) {
    std::cerr << "Unexpected error: " << e.what() << std::endl;
}

// 리스트 초기화 테스트
template<typename T>
inline void ListTest<T>::testListInitialization()
{
    if (!_list.isEmpty())
        throw InitializationFailureException(__func__, "List is not empty on initialization.");
    if (_list.size() != 0)
        throw InitializationFailureException(__func__, "List size is not zero on initialization.");
}

// append 테스트
template<typename T>
void ListTest<T>::testListAppend() {
    size_t size = 0;

    for (auto& element : _test_case) {
        appendAndCheck(element, true);
        ++size;
    }

    std::vector<T> reversed = _test_case;
    std::reverse(reversed.begin(), reversed.end());

    for (auto& element : reversed) {
        appendAndCheck(element, false);
        ++size;
    }

    _list.append(size, _test_case[0]);
    if (_list.size() == size || _list.get(size) != _test_case[0])
        throw AppendFailureException(__func__, "Failed to append to the middle of the list.");
}

// append 보조 함수
template<typename T>
void ListTest<T>::appendAndCheck(const T& element, bool isFront) {
    if (isFront) {
        _list.append_first(element);
        if (_list.size() == 0 || _list.get(0) != element)
            throw AppendFailureException(__func__, "Failed to append to the front of the list.");
    }
    else {
        _list.append_last(element);
        if (_list.size() == 0 || _list.get(_list.size() - 1) != element)
            throw AppendFailureException(__func__, "Failed to append to the back of the list.");
    }
}

// remove 테스트
template<typename T>
inline void ListTest<T>::testListRemove()
{
    T removedFirst = _list.remove_first();
    if (removedFirst != _test_case[0])
        throw RemoveFailureException(__func__, "Failed to remove element from the front correctly.");

    if (_list.size() != _test_case.size() - 1)
        throw RemoveFailureException(__func__, "List size mismatch after removing element from the front.");

    T removedLast = _list.remove_last();
    if (removedLast != _test_case[_test_case.size() - 1])
        throw RemoveFailureException(__func__, "Failed to remove element from the back correctly.");

    if (_list.size() != _test_case.size() - 2)
        throw RemoveFailureException(__func__, "List size mismatch after removing element from the back.");

    size_t middleIndex = _list.size() / 2;
    T removedMiddle = _list.remove(middleIndex);
    if (removedMiddle != _test_case[middleIndex])
        throw RemoveFailureException(__func__, "Failed to remove element from the middle correctly.");

    if (_list.size() != _test_case.size() - 3)
        throw RemoveFailureException(__func__, "List size mismatch after removing element from the middle.");
}
