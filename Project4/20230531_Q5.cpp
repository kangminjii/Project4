#include <iostream>
#include <cmath>

/*
Q5. �Ҽ� �Ǻ��ϴ� ���α׷� �ۼ��ϰ� �����϶�.
	1. 1�� �����ϸ鼭 �Ҽ� �Ǵ�
	2. Ȧ���θ� ����ϱ�
	3. ���� ���� �Ҽ��� ������ ���� �ʴ� �� (Ȧ���θ� ���)
	4. ������ n ������ ��� �Ҽ��� �������� �� ������ �������� �ʴ� ��
		ex) n = 100, sqrt(100) -> 10
			10 ������ �Ҽ� 2,3,5,7�� ������ �������� �ʴ� �� -> �Ҽ�
		4.1 ���� ���� �Ҽ��� ������ ���� �ʴ� ��

	�������� ������ ȸ���� ī��Ʈ �ؼ� ���
*/

using namespace std;

int main()
{
	// #1 1�� �����ϸ鼭 �Ҽ� �Ǵ�
	int n1, performance1 = 0;

	cout << "n1�� �Է����ּ��� : ";
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

	cout << "1. �������� ������ Ƚ�� : " << performance1 << endl << endl;

	// #2 Ȧ���θ� ����ϱ�

	int n2, performance2 = 0;

	cout << "n2�� �Է����ּ��� : ";
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

	cout << "2. �������� ������ Ƚ�� : " << performance2 << endl << endl;

	// #3 ���� ���� �Ҽ��� ������ ���� �ʴ� ��

	int n3, performance3 = 0, total3 = 1;

	cout << "n3�� �Է����ּ��� : ";
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

	cout << "3. �������� ������ Ƚ�� : " << performance3 << endl << endl;

	// #4 ������ n ������ ��� �Ҽ��� �������� �� ������ �������� �ʴ� ��

	int n4, performance4 = 0, total4 = 1;

	cout << "n4�� �Է����ּ��� : ";
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

	cout << "4. �������� ������ Ƚ�� : " << performance4 << endl << endl;

}