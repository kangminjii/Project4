#pragma once
// hanoiTower
class Stack
{
private:
	int max;
	int ptr;
	int* stk;
public:
	int Initialize(int max);
	int Push(int x);
	int Pop(int* x);

	int getS(int x);
};
