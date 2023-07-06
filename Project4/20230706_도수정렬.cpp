#include <iostream>
using namespace std;

const int SIZE = 7;
void Counting(int* arr, int max);

int main()
{
	int arr[SIZE] = { 5, 2, 4, 8, 9, 1, 4 };
	
	int max = arr[0];
	for (int i = 0; i < SIZE; i++)
		if (arr[i] > max)	max = arr[i];

	Counting(arr, max);

	return 0;
}

void Counting(int* arr, int max)
{
	// �ʱ�ȭ
	int* ansCount = new int[max + 1];
	for (int i = 0; i <= max; i++)
		ansCount[i] = 0;

	int ans[SIZE] = { 0 };

	// ���� ����
	for (int i = 0; i <= max; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[j] == i)	ansCount[i]++;
		}
	}
	int j = 0;
	for (int i = 0; i <= max; i++)
	{
		if (ansCount[i] != 0)
		{
			ans[j++] = i;
			ansCount[i]--;
			i--;
		}
	}

	// ���
	cout << "���� �� :" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";

	cout << "\n���� �� :" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << ans[i] << " ";

	delete[] ansCount;
}