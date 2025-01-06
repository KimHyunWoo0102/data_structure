#include<stdio.h>
#include<stdlib.h>
#include"DLinkedList.h"

/*
int main() {

	List list;
	Point compPos;
	Point* ppos;

	//int data;
	ListInit(&list);

	
	LInsert(&list, 11); LInsert(&list, 22); LInsert(&list, 33);
	LInsert(&list, 44); LInsert(&list, 55);
	

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		//printf("%d ", data);

		while (LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}

	printf("\n\n");

	compPos.xpos = 2;
	compPos.ypos = 0;
	//22인 데이터 찾아서 삭제
	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	

	}

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터의 수: %d\n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}


}

*/