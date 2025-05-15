#include"ListTest.h"
#include"CArrayList.h"
#include"IList.h"

int main() {
    try {
        std::unique_ptr<IList<int>> list = std::make_unique<CArrayList<int>>(50); // �ִ� ũ�� 100 ����
        // list->append(0, 10); // ��� ����

        std::vector<int>test_case{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        ListTester::ListTester<int> test(*list, test_case);

        test.TestList();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (...) {  // ��� ���ܸ� ó��
        std::cerr << "Unknown exception occurred." << std::endl;
    }
    return 0;
}