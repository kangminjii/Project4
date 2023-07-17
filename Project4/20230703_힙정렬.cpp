#include <iostream>
#include "StopWatch.h"
using namespace std;

const int SIZE = 10;
static int exchangeNumber = 0;
static int compareNumber = 0;

void swap(int*, int*);
void maxNumber(int*, int*, int*);
void HeapSort(int*);


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
	cout << "±³È¯ È½¼ö : " << exchangeNumber << endl;
	cout << "ºñ±³ È½¼ö : " << compareNumber << endl << endl;
	
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

	// ÈüÀ¸·Î ¸¸µé±â
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