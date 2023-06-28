#include <iostream>
#include <cmath>

/*
Q5. 소수 판별하는 프로그램 작성하고 개선하라.
	1. 1씩 증가하면서 소수 판단
	2. 홀수로만 계산하기
	3. 이전 계산된 소수로 나누어 지지 않는 수 (홀수로만 계산)
	4. 제곱근 n 이하의 모든 소수로 나누었을 때 나누어 떨어지지 않는 수
		ex) n = 100, sqrt(100) -> 10
			10 이하의 소수 2,3,5,7로 나누어 떨어지지 않는 수 -> 소수
		4.1 이전 계산된 소수로 나누어 지지 않는 수

	나눗셈을 실행한 회수를 카운트 해서 출력
*/

using namespace std;

int main()
{
	// #1 1씩 증가하면서 소수 판단
	int n1, performance1 = 0;

	cout << "n1을 입력해주세요 : ";
	cin >> n1;

	for (int i = 2; i <= n1; i++)
	{
		int count1 = 0;

		for (int j = 2; j < i; j++)
		{
			performance1++;
			if (i % j == 0)
			{
				count1++;
				break;
			}
		}
	}

	cout << "1. 나눗셈을 실행한 횟수 : " << performance1 << endl << endl;

	// #2 홀수로만 계산하기

	int n2, performance2 = 0;

	cout << "n2을 입력해주세요 : ";
	cin >> n2;

	for (int i = 3; i <= n2; i += 2)
	{
		int count2 = 0;

		for (int j = 3; j < i; j+=2)
		{
			performance2++;
			if (i % j == 0)
			{
				count2++;
				break;
			}
		}
	}

	cout << "2. 나눗셈을 실행한 횟수 : " << performance2 << endl << endl;

	// #3 이전 계산된 소수로 나누어 지지 않는 수

	int n3, performance3 = 0, total3 = 1;

	cout << "n3을 입력해주세요 : ";
	cin >> n3;

	int *primeNumber = new int[sizeof(primeNumber)];
	primeNumber[0] = 2;

	for (int i = 3; i <= n3; i += 2)
	{
		int count3 = 0;

		for (int j = 1; j < total3; j++)
		{
			performance3++;
			if (i % primeNumber[j] == 0)
			{
				count3++;
				break;
			}
		}
		if (count3 == 0)
		{
			primeNumber[total3++] = i;
		}
	}

	cout << "3. 나눗셈을 실행한 횟수 : " << performance3 << endl << endl;

	// #4 제곱근 n 이하의 모든 소수로 나누었을 때 나누어 떨어지지 않는 수

	int n4, performance4 = 0, total4 = 1;

	cout << "n4을 입력해주세요 : ";
	cin >> n4;

	int* primeNumber2 = new int[sizeof(primeNumber2)];
	primeNumber2[0] = 2;

	for (int i = 3; i <= n4; i += 2)
	{
		int count4 = 0;

		for (int j = 1; j < total4; j++)
		{
			if (primeNumber2[j] <= sqrt(i))
			{
				performance4++;

				if (i % primeNumber2[j] == 0)
				{
					count4++;
					break;
				}
			}
			
		}
		if (count4 == 0)
		{
			primeNumber2[total4++] = i;
		}
	}

	cout << "4. 나눗셈을 실행한 횟수 : " << performance4 << endl << endl;

}