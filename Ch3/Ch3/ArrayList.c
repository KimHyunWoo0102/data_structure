#include<stdio.h>
#include "ArrayList.h"


void ListInit(List* plist)
{
	(plist)->numOfData = 0;
	(plist)->curPosition = -1;//���� ��ġ
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN) {
		puts("������ �Ұ����մϴ�.");
		return;
	}

	(plist)->arr[(plist)->numOfData] = data;

	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->curPosition = 0;
	*pdata=plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if ((plist->numOfData)-1 <= plist->curPosition)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	LData tmp = plist->arr[plist->curPosition];

	for (int i = plist->curPosition; i < plist->numOfData-1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;

	return tmp;
}

int LCount(List* plist)
{
	return plist->numOfData;
}