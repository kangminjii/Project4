#include <iostream>
#include <string>
#include <cmath>

/*
Q5. 10진수를 각 진수로 변환하는 프로그램을 작성하라.
	1. 10진수를 2~36진수까지 변환하는 프로그램을 작성
		ex)
			값을 입력하시오 : 10
			몇 진수로 변환 : 16
			10진수 10은 16진수 A입니다.

	2. 각 진수끼리 변환 프로그램을 작성
		ex)
			입력 데이터는 몇 진수 : 2
			값을 입력하시오 : 10
			출력 데이터는 몇 진수 : 10
			2진수 10은 10진수 2입니다.
*/

using namespace std;

int main()
{
	// #1
	/*int number, method, count = 0;
	char change[100];
	char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "값을 입력하시오 :";
	cin >> number;
	cout << "몇 진수로 변환? : ";
	cin >> method;
	
	int original = number;

	for (int i = 0; i < original; i++)
	{
		count++;

		if (number < method)
		{
			for (int j = 0; j < 37; j++)
			{
				if (number == j)	change[i] = alphabet[j];
			}
			break;
		}

		change[i] = alphabet[number % method];

		number /= method;
	}

	cout << "10진수 " << original << "은 " << method << "진수 ";
	for (int i = count - 1; i >= 0; i--)
	{
		cout << change[i];
	}
	cout << "입니다." << endl;*/


	// #2
	int before, beforeNumber, after, afterNumber = 0, count = 0;
	int temp[100];
	char change[100];
	char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "입력 데이터는 몇 진수 : ";
	cin >> before;
	cout << "값을 입력하시오 :";
	cin >> beforeNumber;
	cout << "출력 데이터는 몇 진수 : ";
	cin >> after;

	for (int i = 0; i < 10; i++)
	{
		temp[i] = beforeNumber % 10;
		beforeNumber /= 10;
	}
	
	for (int i = 0; i < 10; i++)
	{
		afterNumber += temp[i] * pow(before, i);
	}

	int original = afterNumber;

	for (int i = 0; i < original; i++)
	{
		count++;

		if (afterNumber < after)
		{
			for (int j = 0; j < 37; j++)
			{
				if (afterNumber == j)	change[i] = alphabet[j];
			}
			break;
		}

		change[i] = alphabet[afterNumber % after];

		afterNumber /= after;
	}

	cout << before << "진수 " << original << "은 " << after << "진수 ";
	for (int i = count - 1; i >= 0; i--)
	{
		cout << change[i];
	}
	cout << "입니다." << endl;

}