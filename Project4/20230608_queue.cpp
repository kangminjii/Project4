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
int Enque(IntQueue* q, int x) // 큐에 데이터를 인큐
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
int Deque(IntQueue* q, int* x) // 큐에서 데이터를 디큐
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
int Peek(const IntQueue* q, int* x) // 큐에서 데이터를 피크
{
	if (q->num <= 0)	return -1;
	else
	{
		*x = q->que[q->front];
		return 0;
	}
}
void Clear(IntQueue* q) // 모든 데이터 삭제
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}
int Capacity(const IntQueue* q) // 큐의 최대 용량
{
	return q->max;
}
int Size(const IntQueue* q) // 큐에 저장된 데이터 개수
{
	return q->num;
}
int IsEmpty(const IntQueue* q) // 큐가 비었는가?
{
	return q->num <= 0;
}
int IsFull(const IntQueue* q) // 큐가 가득찼는가?
{
	return q->max <= q->num;
}
int Search(const IntQueue* q, int x) // 큐에서 검색
{
	for (int i = 0; i < q->num; i++)
	{
		if (q->que[(i + q->front) % q->max] == x)	return i;
	}
	
	return -1;
}
void Print(const IntQueue* q) // 모든 데이터 출력
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
