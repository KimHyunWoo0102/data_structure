#include<stdio.h>
#include "DBLinkedList.h"

int main() {
	List list;
	int data;
	ListInit(&list);

	ListInsert(&list, 1); ListInsert(&list, 2);
	ListInsert(&list, 3); ListInsert(&list, 4);
	ListInsert(&list, 5); ListInsert(&list, 6);
	ListInsert(&list, 7); ListInsert(&list, 8);

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}

		while (LPrevious(&list, &data)) {
			printf("%d ", data);
		}

		printf("\n\n");
	}
	return 0;
}