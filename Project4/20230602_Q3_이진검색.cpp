#include <iostream>

/*
Q3. p.122 �������� Q4ó�� �����˻� ������
	�ڼ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	�����˻��� �����˻��� �ӵ��� ���϶�.

	5 7 15 28 29 31 39 58 68 72 95
*/

using namespace std;

void binarySearch(int*, int, int);
int main()
{
	const int n = 10;

	int array[n] = { 5, 7, 15, 28, 29, 31, 39, 58, 68, 72 };
	int answer;
	int check = 0;

	while (!check) // �˻��� ���ڰ� ���� ��� ����
	{
		cout << "ã�� ���� �� : ";
		cin >> answer;

		for (int i = 0; i < n; i++)
		{
			if (answer == array[i])
			{
				check = 1;
				break;
			}
		}
	}

	binarySearch(array, n, answer);


	return 0;
}

void binarySearch(int* array, int n, int answer)
{
	int find = 0;
	int range = n;
	int middle = n / 2;

	while (!find)
	{
		// ���
		cout.width(3);
		cout << " |";
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			if (range % 2 == 0)
				temp = range / 2 - 1;
			else
				temp = range / 2;

			if (i == middle)
			{
				cout.width(3);
				cout << " + ";
			}
			else if (i == middle - range / 2)
			{
				cout.width(3);
				cout << "<-";
			}
			else if (i == middle + temp)
			{
				cout.width(3);
				cout << "->";
			}
			else
			{
				cout.width(3);
				cout << "  ";
			}
		}
		cout << endl;

		cout.width(2);
		cout << middle << "|";
		for (int i = 0; i < n; i++)
		{
			cout.width(3);
			cout << array[i];
		}
		cout << endl << "  |" << endl;

		// ����Ž��
		if (range % 2 == 0)
			range /= 2;
		else
			range = range / 2 + 1;

		if (array[middle] == answer)
		{
			find = 1;
			cout << endl << answer << "�� array[" << middle << "]�� �ֽ��ϴ�." << endl;
		}
		else if (answer < array[middle]) // ���� Ž��
		{
			if (n % 2 == 0)
				middle = middle - range / 2 - 1;
			else
				middle = middle - range / 2;
		}
		else // ������ Ž��
		{
			if (n % 2 == 0)
				middle = middle + range / 2;
			else
				middle = middle + range / 2;
		}
	}
}