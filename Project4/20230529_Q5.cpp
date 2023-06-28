#include <iostream>
#include <string>
#include <cmath>

/*
Q5. 10������ �� ������ ��ȯ�ϴ� ���α׷��� �ۼ��϶�.
	1. 10������ 2~36�������� ��ȯ�ϴ� ���α׷��� �ۼ�
		ex)
			���� �Է��Ͻÿ� : 10
			�� ������ ��ȯ : 16
			10���� 10�� 16���� A�Դϴ�.

	2. �� �������� ��ȯ ���α׷��� �ۼ�
		ex)
			�Է� �����ʹ� �� ���� : 2
			���� �Է��Ͻÿ� : 10
			��� �����ʹ� �� ���� : 10
			2���� 10�� 10���� 2�Դϴ�.
*/

using namespace std;

int main()
{
	// #1
	/*int number, method, count = 0;
	char change[100];
	char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "���� �Է��Ͻÿ� :";
	cin >> number;
	cout << "�� ������ ��ȯ? : ";
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

	cout << "10���� " << original << "�� " << method << "���� ";
	for (int i = count - 1; i >= 0; i--)
	{
		cout << change[i];
	}
	cout << "�Դϴ�." << endl;*/


	// #2
	int before, beforeNumber, after, afterNumber = 0, count = 0;
	int temp[100];
	char change[100];
	char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << "�Է� �����ʹ� �� ���� : ";
	cin >> before;
	cout << "���� �Է��Ͻÿ� :";
	cin >> beforeNumber;
	cout << "��� �����ʹ� �� ���� : ";
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

	cout << before << "���� " << original << "�� " << after << "���� ";
	for (int i = count - 1; i >= 0; i--)
	{
		cout << change[i];
	}
	cout << "�Դϴ�." << endl;

}