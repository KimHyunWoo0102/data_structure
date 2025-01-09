#pragma once

typedef int BTData;
typedef void (*VisitFuncPtr)(BTData data);

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);



void PreOrderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InOrderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostOrderTraverse(BTreeNode* bt, VisitFuncPtr action);

void DeleteTree(BTreeNode* bt);