#include <stdio.h>
#include <stdlib.h>
#include "20230607_stack.h"
// stack.cpp

int Initialize(IntStack* s, int max)
{
	s->ptr = 0;
	s->max = max;
	s->stk = (int*)calloc(max, sizeof(int));

	if (s->stk == NULL)		return -1; // 할당이 잘못됐다
	else return 0;
}
int Push(IntStack* s, int x)
{
	if (s->ptr >= s->max)	return -1; // 배열 사이즈를 넘었다
	else
	{
		s->stk[s->ptr] = x;
		s->ptr++;
		return 0;
	}
}
int Pop(IntStack* s, int* x)
{
	if (s->ptr <= 0)	return -1; // 배열에 저장된 값이 없다
	else
	{
		s->stk[s->ptr] = NULL;
		s->ptr--;
		*x = s->stk[s->ptr];
		return 0;
	}
}
int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)		return -1; // 배열에 저장된 값이 없다
	else
	{
		*x = s->stk[s->ptr - 1];
		return 0;
	}
}
void Clear(IntStack* s) // 가리키는 인덱스를 0으로 하면 배열 값이 모두 사라진다
{
	s->ptr = 0;
}
int Capacity(const IntStack* s)
{
	return s->max;
}
int Size(const IntStack* s)
{
	return s->ptr;
}
int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0;
}
int IsFull(const IntStack* s)
{
	return s->ptr >= s->max;
}
int Search(const IntStack* s, int x)
{
	for (int i = 0; i < s->ptr; i++)
	{
		if (s->stk[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void Print(const IntStack* s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		printf("%d ", s->stk[i]);
	}
	printf("\n");
}
void Terminate(IntStack* s)
{
	if (s->stk != NULL)	free(s->stk);
	s->max = 0;
	s->ptr = 0;
}