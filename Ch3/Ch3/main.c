#include<stdio.h>
#include<stdlib.h>

#include "ArrayList.h"
#include "Point.h"
/*
* void ListInit(List *plist);
* 
*/

//void question_3_1() {
//	List list;
//	LData data, ret = 0;
//	ListInit(&list);
//
//	for (int i = 1; i <= 9; i++)
//		LInsert(&list, i);
//
//	if (LFirst(&list, &data)) {
//		ret += data;
//
//		while (LNext(&list, &data))
//			ret += data;
//	}
//
//	printf("list�� ��� ���� ��: %d \n", ret);
//	if (LFirst(&list, &data)) {
//		if (data % 2 == 0 || data % 3 == 0)
//			LRemove(&list);
//
//		while (LNext(&list, &data))
//			if (data % 2 == 0 || data % 3 == 0)
//				LRemove(&list);
//	}
//	if (LFirst(&list, &data)) {
//		printf("%d ", data);
//
//		while (LNext(&list, &data))
//			printf("%d ", data);
//	}
//}

void question_3_2() {
	List list;
	NameCard *pcard;

	ListInit(&list);

	pcard = MakeNameCard("������","01052557689");
	LInsert(&list, pcard);

	pcard = MakeNameCard("�����", "01056232262");
	LInsert(&list, pcard);

	pcard = MakeNameCard("������", "01037748853");
	LInsert(&list, pcard);

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������")) {
			ShowNameCardInfo(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "������")) {
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "������")) {
			ChangePhoneNum(pcard, "01038888853");
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "������")) {
					ChangePhoneNum(pcard, "01038888853");
					break;
				}
			}
		}
	}

	if (LFirst(&list, &pcard)) {
		if (!NameCompare(pcard, "�����")) {
			pcard=LRemove(&list);
			free(pcard);
		}
		else {
			while (LNext(&list, &pcard)) {
				if (!NameCompare(pcard, "�����")) {
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	if (LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		
		while (LNext(&list, &pcard)) 
			ShowNameCardInfo(pcard);
				
	}
}
int main() {
	question_3_2();
	//List list;
	//Point compPos;
	//Point* ppos;

	////int data;
	//ListInit(&list);

	///*
	//LInsert(&list, 11); LInsert(&list, 22); LInsert(&list, 33);
	//LInsert(&list, 44); LInsert(&list, 55);
	//*/

	//ppos = (Point*)malloc(sizeof(Point));
	//SetPointPos(ppos, 2, 1);
	//LInsert(&list, ppos);

	//ppos = (Point*)malloc(sizeof(Point));
	//SetPointPos(ppos, 2, 2);
	//LInsert(&list, ppos);

	//ppos = (Point*)malloc(sizeof(Point));
	//SetPointPos(ppos, 3, 1);
	//LInsert(&list, ppos);

	//ppos = (Point*)malloc(sizeof(Point));
	//SetPointPos(ppos, 3, 2);
	//LInsert(&list, ppos);

	//printf("���� �������� ��: %d\n", LCount(&list));

	//if (LFirst(&list, &ppos))
	//{
	//	ShowPointPos(ppos);
	//	//printf("%d ", data);

	//	while (LNext(&list, &ppos)) {
	//		ShowPointPos(ppos);
	//	}
	//}

	//printf("\n\n");

	//compPos.xpos = 2;
	//compPos.ypos = 0;
	////22�� ������ ã�Ƽ� ����
	//if (LFirst(&list, &ppos)) {
	//	if (PointComp(ppos, &compPos) == 1)
	//	{
	//		ppos = LRemove(&list);
	//		free(ppos);
	//	}

	//	while (LNext(&list, &ppos)) {
	//		if (PointComp(ppos, &compPos) == 1) {
	//			ppos = LRemove(&list);
	//			free(ppos);
	//		}
	//	}
	//

	//}

	//// ���� �� ���� ������ ��ü ���
	//printf("���� �������� ��: %d\n", LCount(&list));

	//if (LFirst(&list, &ppos)) {
	//	ShowPointPos(ppos);

	//	while (LNext(&list, &ppos))
	//		ShowPointPos(ppos);
	//}


	return 0;
}