#include <iostream>
#include "StopWatch.h"
using namespace std;

const int SIZE = 10;
static int exchangeNumber = 0;
static int compareNumber = 0;

void swap(int*, int*);
void maxNumber(int*, int*, int*);
void HeapSort(int*);
void BubbleSort3(int*);
void SelectionSort2(int*);
void QuickSort(int arr[], int pl, int pivot, int pr);

int main()
{
	StopWatch s;

	// heap sort
	s.start();
	for (int z = 0; z < 1000000; z++)
	{
		int arr[SIZE] = { 4,7,6,3,1,7,8,3,1,10};
		HeapSort(arr);
	}
	s.stop();
	
	cout << "Heap sort : " << s.getElapsedTime() << "ms" << endl;
	cout << "��ȯ Ƚ�� : " << exchangeNumber << endl;
	cout << "�� Ƚ�� : " << compareNumber << endl << endl;
	

	// bubble sort
	s.start();
	for (int z = 0; z < 1000000; z++)
	{
		int arr[SIZE] = { 4,7,6,3,1,7,8,3,1,10 };
		BubbleSort3(arr);
	}
	s.stop();

	cout << "Bubble sort : " << s.getElapsedTime() << "ms" << endl;
	cout << "��ȯ Ƚ�� : " << exchangeNumber << endl;
	cout << "�� Ƚ�� : " << compareNumber << endl << endl;

	// selection sort
	s.start();
	for (int z = 0; z < 1000000; z++)
	{
		int arr[SIZE] = { 4,7,6,3,1,7,8,3,1,10 };
		SelectionSort2(arr);
	}
	s.stop();

	cout << "Selection sort : " << s.getElapsedTime() << "ms" << endl;
	cout << "��ȯ Ƚ�� : " << exchangeNumber << endl;
	cout << "�� Ƚ�� : " << compareNumber << endl << endl;

	// quick sort
	s.start();
	for (int z = 0; z < 1000000; z++)
	{
		compareNumber = 0;
		exchangeNumber = 0;
		int arr[SIZE] = { 4,7,6,3,1,7,8,3,1,10 };
		QuickSort(arr, 0, SIZE / 2, SIZE - 1);
	}
	s.stop();

	cout << "Quick sort : " << s.getElapsedTime() << "ms" << endl;
	cout << "��ȯ Ƚ�� : " << exchangeNumber << endl;
	cout << "�� Ƚ�� : " << compareNumber << endl << endl;
	

	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxNumber(int* top, int* left, int* right)
{
	compareNumber++;
	if (*top < *left)
	{
		if (*left < *right) // top < left < right
		{
			swap(top, right);
			exchangeNumber++;
		}
		else // top, right < left
		{
			swap(top, left);
			exchangeNumber++;
		}
	}
	else
	{
		if (*top < *right) // left <= top < right
		{
			swap(top, right);
			exchangeNumber++;
		}
	}
}

void HeapSort(int* arr)
{
	exchangeNumber = 0;
	compareNumber = 0;
	int j = 0;
	int temp = SIZE;

	// ������ �����
	for (int k = 0; k <= SIZE / 2 - 1; k++)
	{
		for (int i = 0; i <= (temp / 2) - 1; i++)
		{
			if (temp > i * 2 + 2)
				maxNumber(&arr[i], &arr[i * 2 + 1], &arr[i * 2 + 2]);
			else
			{
				if (arr[i] < arr[i * 2 + 1])
					swap(arr[i], arr[i * 2 + 1]);
				exchangeNumber++;
			}
		}
	}

	while (j != SIZE)
	{
		for (int i = 0; i <= (temp / 2) - 1; i++)
		{
			if (temp > i * 2 + 2)
				maxNumber(&arr[i], &arr[i * 2 + 1], &arr[i * 2 + 2]);
			else
			{
				if (arr[i] < arr[i * 2 + 1])
					swap(arr[i], arr[i * 2 + 1]);
				exchangeNumber++;
			}
		}

		/*for (int k = 0; k < SIZE; k++)
			cout << arr[k] << " ";
		cout << endl;*/

		swap(arr[0], arr[SIZE - 1 - j]);
		exchangeNumber++;
		j++;
		temp -= 1;
	}
}

void BubbleSort3(int* arr)
{
	int count = 0;
	int temp = 0;
	exchangeNumber = 0;
	compareNumber = 0;
	int location = 0;
	int symbol = 0;

	while (temp < SIZE - 1)
	{
		int last = SIZE - 1; // ������ �ε��� ��

		for (int j = SIZE - 1; j > temp; j--)
		{
			if (arr[j] < arr[j - 1])  // ���� ����
			{
				last = j;
				symbol = 1;
				swap(arr[j], arr[j - 1]);
				exchangeNumber++;
				compareNumber++;
			}
			else
			{
				symbol = -1;
				compareNumber++;
			}
		}
		temp = last;
	}
}

void SelectionSort2(int* arr)
{
	compareNumber = 0;
	exchangeNumber = 0;
	for (int i = 0; i < SIZE; i++)
	{
		// ����
		int min = arr[i];
		int temp2 = 0;
		for (int j = i + 1; j < SIZE; j++)
		{
			compareNumber++;
			if (arr[j] < min)
			{
				min = arr[j];
				temp2 = j;
				swap(arr[i], arr[j]);
				exchangeNumber++;
			}
		}
	}
}

void QuickSort(int arr[], int pl, int pivot, int pr)
{
	// ó�� �ε��� �� ����
	int left = pl;
	int right = pr;

	while (1)
	{
		//  pl�� pr �����̱�
		while (arr[pivot] > arr[pl])
		{
			compareNumber++;
			pl++;
		}
		while (arr[pivot] < arr[pr])
		{
			compareNumber++;
			pr--;
		}
		//  swap
		if (pl <= pr)
		{
			swap(arr[pl], arr[pr]);
			compareNumber++;
			exchangeNumber++;
			pl++;
			pr--;
		}
		// ��������
		if (pr <= pl)      break;
	}

	if (left < pr) QuickSort(arr, left, (left + pr) / 2, pr);         // pr�� 0�� �ɶ����� ����
	if (pl < right) QuickSort(arr, pl, (pl + right) / 2, right);  // pl�� NUM-1�� �ɶ����� ����
}