#include <iostream>

/*
Q4. p.42 연습문제 18를 응용해 n단의 숫자 모래시계를 출력하는 프로그램을 작성하라.
	ex) 3				2
		1 1 1 1 1		1 1 1
		  2 2 2			  2
		    3			1 1 1
		  2 2 2
		1 1 1 1 1

*/

using namespace std;

int main()
{
	int n;
	int count = 0;

	cin >> n;
	cout << endl;
	int total = 2 * n - 1;


	for (int i = 1; i <= total; i++)
	{
		if (i >= n) // 가운데~끝
		{
			for (int k = 0; k < count; k++)
			{
				cout << " ";
			}
			for (int j = 1; j <= (total - 2*count); j++)
			{
				cout << count + 1;
			}
			count--;
			cout << endl;
		}
		else // 윗부분
		{
			for (int k = 0; k < count; k++)
			{
				cout << " ";
			}
			for (int j = 1; j <= (total - 2*count); j++)
			{
				cout << count + 1;
			}
			count++;
			cout << endl;
		}
	}
}