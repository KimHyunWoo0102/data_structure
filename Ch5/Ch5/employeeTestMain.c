//#include<stdio.h>
//#include"CLinkedList.h"
//#include"employeeList.h"
//#include<string.h>
//
//void printNdaysAfter(List* list,char *pname,int days) {
//	Employee* tmp=NULL;
//	for (int i = 0; i < days; i++) {
//		LNext(list, &tmp);
//	}
//
//	printf("%s�� %d �� �ڿ� ������ �� ����� ", pname, days);
//	printEmployee(tmp);
//}
//
//void findNdaysAfter(List*list,char* pname, int days) {
//	Employee* tmp=NULL;
//
//	if (LFirst(list, &tmp)) {
//		if (strcmp(pname, tmp->name)==0) {
//			printNdaysAfter(&list,pname,days);
//		}
//		else {
//			while (LNext(list, &tmp)) {
//				if (strcmp(pname, tmp->name)==0) {
//					printNdaysAfter(list,pname, days);
//					break;
//				}
//			}
//		}
//	}
//}
//
//
//
//int main() {
//	List list;
//	Employee* data;
//
//	int i, nodeNum;
//	ListInit(&list);
//
//	data = makeEmployee(1, "������");
//	LInsert(&list, data);
//
//	data = makeEmployee(2, "�����");
//	LInsert(&list, data);
//
//	data = makeEmployee(3, "������");
//	LInsert(&list, data);
//
//	data = makeEmployee(4, "�����");
//	LInsert(&list, data);
//
//	data = makeEmployee(5, "��ÿ�");
//	LInsert(&list, data);
//
//
//	data = makeEmployee(6, "������");
//	LInsert(&list, data);
//
//	if (LFirst(&list, &data)) {
//		printEmployee(data);
//
//		for (i = 0; i < LCount(&list) - 1; i++)
//		{
//			if (LNext(&list, &data))
//				printEmployee(data);
//		}
//	}
//
//	printf("\n\n");
//
//	findNdaysAfter(&list, "�����", 3);
//	printf("\n");
//
//	
//	return 0;
//}