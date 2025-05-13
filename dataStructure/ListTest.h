#pragma once
#include "IList.h"
#include"Exception.h"

template<typename T, class ListType>
class ListTest {
public:
	ListTest(ListType &list,const std::vector<T>test_case):_list(list),_test_case(test_case){}
	~ListTest() = default;

	void TestList();
	void testListInitialization();
	void testListAppend();
	void testListRemove();
    void appendAndCheck(const T& element, bool isFront);
private:
	ListType &_list;
	std::vector<T>_test_case;
};

template<typename T, class ListType>
inline void ListTest<T, ListType>::TestList()
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

template<typename T, class ListType>
inline void ListTest<T, ListType>::testListInitialization()
try {
    if (!_list.isEmpty())
        throw InitializationFailureException(__func__, "List is not empty on initialization.");
    if (_list.size() != 0)
        throw InitializationFailureException(__func__, "List size is not zero on initialization.");
}
catch (const InitializationFailureException& e) {
    throw;  // Re-throw the exception for external handling
}

template<typename T, class ListType>
void ListTest<T, ListType>::testListAppend() {
    try {
        size_t size = _test_case.size();
        // First, append elements from the front (first)
        for (auto& element : _test_case) {
            appendAndCheck(element, true); // Append to the front and check
            ++size;
        }

        // Reverse the test_case vector
        std::vector<T> reversed_test_case = _test_case;
        std::reverse(reversed_test_case.begin(), reversed_test_case.end());

        // Then, append elements from the back (last) after reversing the vector
        for (auto& element : reversed_test_case) {
            appendAndCheck(element, false); // Append to the back and check
            ++size;
        }

        _list.append(size, _test_case[0]);
        if (_list.size() == size || _list.get(size) != _test_case[0])
            throw AppendFailureException(__func__, "Failed to append to the middle of the list.");
    }
    catch (const AppendFailureException& e) {
        throw;  // Re-throw the exception for external handling
    }
}

// Helper function to handle append operations
template<typename T, class ListType>
void ListTest<T, ListType>::appendAndCheck(const T& element, bool isFront) {
    if (isFront) {
        _list.append_first(element);  // Add to the front of the list
        if (_list.size() == 0 || _list.get(0) != element) {
            throw AppendFailureException(__func__, "Failed to append to the front of the list.");
        }
    }
    else {
        _list.append_last(element);  // Add to the end of the list
        if (_list.size() == 0 || _list.get(_list.size() - 1) != element) {
            throw AppendFailureException(__func__, "Failed to append to the back of the list.");
        }
    }
}

template<typename T, class ListType>
inline void ListTest<T, ListType>::testListRemove()
try {
    // Remove from the front (first)
    T removedFirst = _list.remove_first();
    if (removedFirst != _test_case[0]) {
        throw RemoveFailureException(__func__,"Failed to remove element from the front correctly.");
    }
    if (_list.size() != _test_case.size() - 1) {
        throw RemoveFailureException(__func__,"List size mismatch after removing element from the front.");
    }

    // Remove from the back (last)
    T removedLast = _list.remove_last();
    if (removedLast != _test_case[_test_case.size() - 1]) {
        throw RemoveFailureException(__func__, "Failed to remove element from the back correctly.");
    }
    if (_list.size() != _test_case.size() - 2) {
        throw RemoveFailureException(__func__, "List size mismatch after removing element from the back.");
    }

    // Remove from the middle (index = size/2)
    size_t middleIndex = _list.size() / 2;
    T removedMiddle = _list.remove(middleIndex);
    if (removedMiddle != _test_case[middleIndex]) {
        throw RemoveFailureException(__func__, "Failed to remove element from the middle correctly.");
    }
    if (_list.size() != _test_case.size() - 3) {
        throw RemoveFailureException(__func__, "List size mismatch after removing element from the middle.");
    }
}
catch (const RemoveFailureException& e) {
    throw;  // Re-throw the exception for external handling
}

