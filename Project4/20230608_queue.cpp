#include "20230608_queue.h"
#include <stdlib.h>
#include <stdio.h>

int Initialize(IntQueue* q, int max)
{
	q->max = max;
	q->num = 0;
	q->front = 0;
	q->rear = 0;

	q->que = (int*)calloc(max, sizeof(int));
	if (q->que == NULL)	return -1;
	else return 0;
}
int Enque(IntQueue* q, int x) // ť�� �����͸� ��ť
{
	if (q->num >= q->max)		return -1;
	else
	{
		q->que[q->rear] = x;
		q->num++;
		q->rear++;
		if (q->rear == q->max)	q->rear = 0;
		return 0;
	}
}
int Deque(IntQueue* q, int* x) // ť���� �����͸� ��ť
{
	if (q->num <= 0)	return -1;
	else
	{
		q->num--;
		*x = q->que[q->front];
		q->que[q->front] = NULL;
		q->front++;
		if (q->front == q->max)	q->front = 0;
		return 0;
	}
}
int Peek(const IntQueue* q, int* x) // ť���� �����͸� ��ũ
{
	if (q->num <= 0)	return -1;
	else
	{
		*x = q->que[q->front];
		return 0;
	}
}
void Clear(IntQueue* q) // ��� ������ ����
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}
int Capacity(const IntQueue* q) // ť�� �ִ� �뷮
{
	return q->max;
}
int Size(const IntQueue* q) // ť�� ����� ������ ����
{
	return q->num;
}
int IsEmpty(const IntQueue* q) // ť�� ����°�?
{
	return q->num <= 0;
}
int IsFull(const IntQueue* q) // ť�� ����á�°�?
{
	return q->max <= q->num;
}
int Search(const IntQueue* q, int x) // ť���� �˻�
{
	for (int i = 0; i < q->num; i++)
	{
		if (q->que[(i + q->front) % q->max] == x)	return i;
	}
	
	return -1;
}
void Print(const IntQueue* q) // ��� ������ ���
{
	for (int i = 0; i < q->num; i++)
	{
		printf("%d ", q->que[(i + q->front) % q->max]);
	}
	printf("\n\n");
}
void Terminate(IntQueue* q)
{
	if (q->que != NULL)	free(q->que);
	q->max = 0;
	q->num = 0;
}
