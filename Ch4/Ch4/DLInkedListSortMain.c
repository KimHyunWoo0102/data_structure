#include<stdio.h>
#include"DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	if (d1 > d2)
		return 0;
	else
		return 1;
}

int main() {
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list,WhoIsPrecede);

	LInsert(&list, 22); LInsert(&list, 11);
	LInsert(&list, 33); LInsert(&list, 55);
	LInsert(&list, 11);

	printf("현재 데이터의 수:%d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}

	printf("\n\n");

	return 0;
}