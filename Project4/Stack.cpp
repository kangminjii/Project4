#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
// hanoiTower

int Stack::Initialize(int max1)
{
	ptr = 0;
	max = max1;
	stk = (int*)calloc(max, sizeof(int));
	
	if (stk == NULL)		return -1; // �Ҵ��� �߸��ƴ�
	else return 0;
}
int Stack::Push(int x)
{
	if (ptr >= max)	return -1; // �迭 ����� �Ѿ���
	else
	{
		stk[ptr] = x;
		ptr++;
		return 0;
	}
}
int Stack::Pop(int* x)
{
	if (ptr <= 0)	return -1; // �迭�� ����� ���� ����
	else
	{
		stk[ptr] = 0;
		ptr--;
		*x = stk[ptr];
		return 0;
	}
}
int Stack::getS(int x)
{
	if (x > ptr - 1)
		return 0;
	
	return stk[x];
}