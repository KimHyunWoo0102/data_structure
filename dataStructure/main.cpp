#include"ListTest.h"
#include"CArrayList.h"
#include"IList.h"

#include"CSingleList.h"

int main() {
    try {
        std::shared_ptr<IList<int>> list =std::make_shared<CSingleList<int>>(); // 최대 크기 100 지정
        // list->append(0, 10); // 사용 예시

        std::vector<int>test_case{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        ListTester::ListTester<int> test(*list, test_case);
    
        IList<int>& ref_list = *list;

        ref_list.isEmpty();
        test.TestList();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (...) {  // 모든 예외를 처리
        std::cerr << "Unknown exception occurred." << std::endl;
    }
    return 0;
}