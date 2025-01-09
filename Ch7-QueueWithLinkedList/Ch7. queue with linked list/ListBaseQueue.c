#include "ListBaseQueue.h"
#include<stdio.h>
#include<stdlib.h>

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
	return pq->front == NULL ? TRUE : FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data rdata;

	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	rdata = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return rdata;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}
