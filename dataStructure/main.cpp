#include"ListTest.h"
#include"CArrayList.h"
#include"IList.h"

#include"CSingleList.h"

int main() {
    try {
        IList<int>* list =new CSingleList<int>(); // �ִ� ũ�� 100 ����
        // list->append(0, 10); // ��� ����

        std::vector<int>test_case{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        ListTester::ListTester<int> test(*list, test_case);
      
        auto* ptr_list = list;
        IList<int>& ref_list = *list;

        ref_list.isEmpty();
        test.TestList();
       delete list;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (...) {  // ��� ���ܸ� ó��
        std::cerr << "Unknown exception occurred." << std::endl;
    }
    return 0;
}