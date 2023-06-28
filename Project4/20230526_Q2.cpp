#include <iostream>
/*
Q2. p.33 연습문제 8, 9 순서도 + 코드
*/

using namespace std;

int sum(int n);
int sumof(int a, int b);

int main()
{
	// #8
	int answer = sum(10);
	int answer2 = sum(11);

	cout << answer << endl;
	cout << answer2 << endl << endl;

	// #9
	int answer3 = sumof(3, 7);
	int answer4 = sumof(3, 8);

	cout << answer3 << endl;
	cout << answer4 << endl;
}

int sum(int n)
{
	return (1 + n) * (n / 2);
}

int sumof(int a, int b)
{
	if (a >= b)
		return (a + b) * (a - b + 1) / 2;
	else
		return (a + b) * (b - a + 1) / 2;

}