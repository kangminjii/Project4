#include <iostream>

using namespace std;

/*
Q3. p.20 �������� Q1. max4 �Լ� �ۼ� & ������ �׸���
*/

int max4(int, int, int, int);

int main()
{
	int answer = max4(9, 3, 5, 2);
	cout << "max = " << answer << endl;
}

int max4(int a, int b, int c, int d)
{
	int max = a;

	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;
	
	return max;
}