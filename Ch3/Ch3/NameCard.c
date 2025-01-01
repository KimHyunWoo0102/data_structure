#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include<string.h>
#include<stdlib.h>



NameCard* MakeNameCard(char* name, char* phone)
{
    NameCard* pcard = (NameCard*)malloc(sizeof(NameCard));
    strcpy(pcard->name, name);
    strcpy(pcard->phone, phone);
    return pcard;
}

void ShowNameCardInfo(NameCard* pcard)
{
    printf("name: %s, phone: %s \n", pcard->name, pcard->phone);
}

int NameCompare(NameCard* pcard, char* name)
{
    return strcmp(pcard->name, name);  
}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
    strcpy(pcard->phone, phone);
}
