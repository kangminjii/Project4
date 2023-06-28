/*
Q3. �����Ʈ�� �����϶�.
	���� 1, 2, 3 ������ ���� ���α׷��� �ۼ��ϰ� ������ ������ ���϶�.
	p.219
*/

#include <iostream>

using namespace std;

const int SIZE = 7;
void swap(int* a, int* b);
void print(int* array, int n);

int main()
{
	int sort[SIZE] = { 1,3,9,4,7,8,6 }; // ������ �迭
	char check[SIZE];
	int isSorted = 0, count = 0, exchangeNumber = 0, compareNumber = 0;



	// ���� 1.

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = SIZE - 1; j >= i; j--)
		{
			if (sort[j] < sort[j - 1])
			{
				swap(sort[j], sort[j - 1]);
				cout << "+";
			}
			else
			{
				print(sort, SIZE);

			}
		}
		cout << endl;
	}


	cout << endl;
	cout << "�� �񱳸� " << compareNumber << "ȸ �߽��ϴ�." << endl;
	cout << "�� ��ȯ�� " << exchangeNumber << "ȸ �߽��ϴ�." << endl;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int* array, int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}