/*
Q2. �ܼ� ���� ���� p.226 Q.8ó��
*/

#include <iostream>

using namespace std;

void insertion(int*, int);

int main()
{
	int number;
	cout << "��� ����: ";
	cin >> number;

	int* array = new int[number];

	for (int i = 0; i < number; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
	}
	cout << endl << "���� ����: " << endl;

	insertion(array, number);


	delete[] array;
	return 0;
}

void insertion(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		int end = i;

		for (int j = i - 1; j >= 0; j--)
		{
			if (array[j] > array[i])
			{
				count++;
			}
		}

		// ȭ��ǥ ǥ��
		for (int j = 0; j <= end; j++)
		{
			if (!count && i != 0)
			{
				if (j == end)	cout << " +";
				else			cout << "  ";

			}
			else if (i != 0)
			{
				if (j == end)	cout << "-+";
				else if (j == end - count)	cout << "^-";
				else if (j > i - count - 1)	cout << "--";
				else cout << "  ";
			}
		}
		cout << endl;

		// swap
		for (int j = 0; j < count; j++)
		{
			int temp = array[i - j];
			array[i - j] = array[i - 1 - j];
			array[i - 1 - j] = temp;
		}
		
		// �迭 ���
		for (int j = 0; j < n; j++)
		{
			cout << " " << array[j];
		}
		cout << endl;
	}
}

