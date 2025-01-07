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
//	printf("%sÀÇ %d ÀÏ µÚ¿¡ ´çÁ÷À» ¼³ »ç¶÷Àº ", pname, days);
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
//	data = makeEmployee(1, "±èÇö¿ì");
//	LInsert(&list, data);
//
//	data = makeEmployee(2, "±è½ÃÇÑ");
//	LInsert(&list, data);
//
//	data = makeEmployee(3, "±èÁö¿ì");
//	LInsert(&list, data);
//
//	data = makeEmployee(4, "±è¹ÎÁ¤");
//	LInsert(&list, data);
//
//	data = makeEmployee(5, "±è½Ã¿ì");
//	LInsert(&list, data);
//
//
//	data = makeEmployee(6, "ÀåÇöÁ¤");
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
//	findNdaysAfter(&list, "±è¹ÎÁ¤", 3);
//	printf("\n");
//
//	
//	return 0;
//}