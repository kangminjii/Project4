#pragma once

typedef struct
{
	int max; // ť�� �ִ� �뷮
	int num; // ���� ��� ����
	int front; // ����Ʈ
	int rear;  // ����
	int* que; // ť�� �� �� ��� ������
}IntQueue;

int Initialize(IntQueue* q, int max); // �ʱ�ȭ
int Enque(IntQueue* q, int x); // ť�� �����͸� ��ť
int Deque(IntQueue* q, int* x); // ť���� �����͸� ��ť
int Peek(const IntQueue* q, int* x); // ť���� �����͸� ��ũ
void Clear(IntQueue* q); // ��� ������ ����
int Capacity(const IntQueue* q); // ť�� �ִ� �뷮
int Size(const IntQueue* q); // ť�� ����� ������ ����
int IsEmpty(const IntQueue* q); // ť�� ����°�?
int IsFull(const IntQueue* q); // ť�� ����á�°�?
int Search(const IntQueue* q, int x); // ť���� �˻�
void Print(const IntQueue* q); // ��� ������ ���
void Terminate(IntQueue* q);