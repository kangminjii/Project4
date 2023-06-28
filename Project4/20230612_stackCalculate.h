#pragma once
#include <string>
using namespace std;

class stackCalculate
{
private:
	// ť�� ���� ��ü �뷮
	int max;
	// ����
	int ptr;
	char* stk;
	// ť
	int num;
	int front;
	int rear;
	char* que;
public:
	// ����
	string InitializeStack(int max);
	string Push(char c);
	string Pop(char* c);
	string Peek(char* c);
	int IsEmptyStack();
	// ť
	string InitializeQueue(int max);
	string Enque(char c);
	string Deque(char* c);
	int IsEmptyQueue();
	// ���
	void PrintStack();
	void PrintQueue();
};