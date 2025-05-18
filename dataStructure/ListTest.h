#pragma once
#include "IList.h"
#include "Exception.h"
#include <vector>
#include <iostream>
#include <algorithm>

namespace ListTester {
    template<typename T>
    class ListTester {
    public:
        ListTester(IList<T>& list, const std::vector<T>& test_case)
            : _list(list), _test_case(test_case) {
        }
        ~ListTester() = default;

        void TestList();
        void testListInitialization();
        void testListAppend();
        void testListRemove();

    private:
        void appendAndCheck(const T& element, bool isFront);

        IList<T>& _list;
        std::vector<T> _test_case;
    };

    // ��ü �׽�Ʈ ����
    template<typename T>
    inline void ListTester<T>::TestList()
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

    // ����Ʈ �ʱ�ȭ �׽�Ʈ
    template<typename T>
    inline void ListTester<T>::testListInitialization()
    {
        if (!_list.isEmpty()) // _list�� ���۷����̹Ƿ� -> ��� . ���
            throw InitializationFailureException(__func__, "List is not empty on initialization.");
        if (_list.size() != 0) // _list�� ���۷����̹Ƿ� -> ��� . ���
            throw InitializationFailureException(__func__, "List size is not zero on initialization.");
    }

    // append �׽�Ʈ
    template<typename T>
    void ListTester<T>::testListAppend() {
        size_t size = 0;

        for (auto& element : _test_case) {
            appendAndCheck(element, true);
            ++size;
        }
        std::cout << _list << "\n"; // _list�� ���۷����̹Ƿ� . ���

        std::vector<T> reversed = _test_case;
        std::reverse(reversed.begin(), reversed.end());

        for (auto& element : reversed) {
            appendAndCheck(element, false);
            ++size;
        }
        std::cout << _list << "\n"; // _list�� ���۷����̹Ƿ� . ���

        _list.append(size / 2, _test_case[0]); // _list�� ���۷����̹Ƿ� . ���
        size++;
        if (_list.size() != size || _list.get(size/2) != _test_case[0]) // _list�� ���۷����̹Ƿ� . ���
            throw AppendFailureException(__func__, "Failed to append to the middle of the list.");
        std::cout << _list << "\n"; // _list�� ���۷����̹Ƿ� . ���
    }

    // append ���� �Լ�
    template<typename T>
    void ListTester<T>::appendAndCheck(const T& element, bool isFront) {
        if (isFront) {
            _list.append_first(element); // _list�� ���۷����̹Ƿ� . ���
            if (_list.size() == 0 || _list.get(1) != element) // _list�� ���۷����̹Ƿ� . ���
                throw AppendFailureException(__func__, "Failed to append to the front of the list.");
        }
        else {
            _list.append_last(element); // _list�� ���۷����̹Ƿ� . ���
            if (_list.size() == 0 || _list.get(_list.size()) != element) // _list�� ���۷����̹Ƿ� . ���
                throw AppendFailureException(__func__, "Failed to append to the back of the list.");
        }
    }

    // remove �׽�Ʈ
    template<typename T>
    inline void ListTester<T>::testListRemove()
    {
        // ����Ʈ�� ���纻�� �̸� �����α�
        std::vector<T> listCopy = _list.getElements(); // _list�� ���۷����̹Ƿ� . ���

        // ù ��° �׸� ����
        T removedFirst = _list.remove_first(); // _list�� ���۷����̹Ƿ� . ���
        if (removedFirst != listCopy[0])
            throw RemoveFailureException(__func__, "Failed to remove element from the front correctly.");
        std::cout << _list << "\n"; // _list�� ���۷����̹Ƿ� . ���

        // ���纻���� ù ��° ��� ����
        listCopy.erase(listCopy.begin());

        if (_list.size() != listCopy.size()) // _list�� ���۷����̹Ƿ� . ���
            throw RemoveFailureException(__func__, "List size mismatch after removing element from the front.");
        if (_list.get(0) != listCopy[0]) // _list�� ���۷����̹Ƿ� . ���
            throw RemoveFailureException(__func__, "List elements mismatch after removing from the front.");

        // ������ �׸� ����
        T removedLast = _list.remove_last(); // _list�� ���۷����̹Ƿ� . ���
        if (removedLast != listCopy[listCopy.size() - 1])
            throw RemoveFailureException(__func__, "Failed to remove element from the back correctly.");
        std::cout << _list << "\n"; // _list�� ���۷����̹Ƿ� . ���

        // ���纻���� ������ ��� ����
        listCopy.pop_back();

        if (_list.size() != listCopy.size()) // _list�� ���۷����̹Ƿ� . ���
            throw RemoveFailureException(__func__, "List size mismatch after removing element from the back.");
        if (_list.get(_list.size() - 1) != listCopy[listCopy.size() - 1]) // _list�� ���۷����̹Ƿ� . ���
            throw RemoveFailureException(__func__, "List elements mismatch after removing from the back.");

        // �߰� �׸� ����
        size_t middleIndex = _list.size() / 2; // _list�� ���۷����̹Ƿ� . ���
        T removedMiddle = _list.remove(middleIndex); // _list�� ���۷����̹Ƿ� . ���
        if (removedMiddle != listCopy[middleIndex])
            throw RemoveFailureException(__func__, "Failed to remove element from the middle correctly.");
        std::cout << _list << "\n"; // _list�� ���۷����̹Ƿ� . ���

        // ���纻���� �߰� ��� ����
        listCopy.erase(listCopy.begin() + middleIndex);

        if (_list.size() != listCopy.size()) // _list�� ���۷����̹Ƿ� . ���
            throw RemoveFailureException(__func__, "List size mismatch after removing element from the middle.");
        if (_list.get(middleIndex) != listCopy[middleIndex]) // _list�� ���۷����̹Ƿ� . ���
            throw RemoveFailureException(__func__, "List elements mismatch after removing from the middle.");
    }
}
