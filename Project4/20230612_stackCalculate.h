#pragma once
#include <string>
using namespace std;

class stackCalculate
{
private:
	// 큐와 스택 전체 용량
	int max;
	// 스택
	int ptr;
	char* stk;
	// 큐
	int num;
	int front;
	int rear;
	char* que;
public:
	// 스택
	string InitializeStack(int max);
	string Push(char c);
	string Pop(char* c);
	string Peek(char* c);
	int IsEmptyStack();
	// 큐
	string InitializeQueue(int max);
	string Enque(char c);
	string Deque(char* c);
	int IsEmptyQueue();
	// 출력
	void PrintStack();
	void PrintQueue();
};