#pragma once

#define FALSE 0
#define TRUE 1

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _lQueue {
	Node* front;
	Node* rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);