#include <iostream>
#include "StopWatch.h"
using namespace std;

const int SIZE = 10;
static int exchangeNumber = 0;
static int compareNumber = 0;

void swap(int*, int*);
void maxNumber(int*, int*, int*);

int main()
{
	StopWatch s;

	//int arr[SIZE] = { 10,9,5,8,3,2,4,6,7,1 };
	// 10,9,5,8,3,2,4,6,7,1

	/*cout << "BEFORE : " << endl;
	for (int k = 0; k < SIZE; k++)
		cout << arr[k] << " ";
	cout << endl;*/

	int j = 0;
	int temp = SIZE;

	s.start();
	for (int z = 0; z < 1000000; z++)
	{
		int arr[SIZE] = { 4,7,6,3,1,7,8,3,1,10};

		/*for (int k = 0; k < SIZE; k++)
			cout << arr[k] << " ";
		cout << endl;*/

		// 힙으로 만들기
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
				}
			}
			/*for (int k = 0; k < SIZE; k++)
				cout << arr[k] << " ";
			cout << endl;*/
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
				}
			}

			for (int k = 0; k < SIZE; k++)
				cout << arr[k] << " ";
			cout << endl;

			swap(arr[0], arr[SIZE - 1 - j]);
			j++;
			temp -= 1;
		}
	}
	s.stop();
	
	/*cout << "AFTER : " << endl;
	for (int k = 0; k < SIZE; k++)
		cout << arr[k] << " ";
	cout << endl;*/

	cout << "교환 횟수 : " << exchangeNumber << endl;
	cout << "비교 횟수 : " << compareNumber << endl;
	cout << "heap sort : " << s.getElapsedTime() << "ms" << endl;

	//// 버블소트

	//int count, temp1;
	//int exchangeNumber, compareNumber;

	//int location, symbol;
	//s.start();
	//for (int z = 0; z < 1000000; z++)
	//{
	//	int arr[SIZE] = { 6,4,8,3,1,9,7 }; // 정렬할 배열
	//	count = 0;
	//	temp1 = 0;
	//	exchangeNumber = 0, compareNumber = 0;
	//	location = 0;

	//	while (temp1 < SIZE - 1)
	//	{
	//		int last = SIZE - 1; // 마지막 인덱스 값

	//		for (int j = SIZE - 1; j > temp1; j--)
	//		{
	//			if (arr[j] < arr[j - 1])  // 정렬 시행
	//			{
	//				last = j;
	//				swap(arr[j], arr[j - 1]);
	//			}
	//		}
	//		temp1 = last;
	//	}
	//}
	//s.stop();

	//cout << "bubble sort : " << s.getElapsedTime() << "ms" << endl;

	//// selection sort
	//s.start();
	//for (int z = 0; z < 1000000; z++)
	//{
	//	int array[SIZE] = { 6,4,8,3,1,9,7 };
	//	for (int i = 0; i < SIZE; i++)
	//	{
	//		int min = array[i];
	//		int temp2 = 0;
	//		int swapIndex = 0;
	//		for (int j = i + 1; j < SIZE; j++)
	//		{
	//			if (array[j] < min)
	//			{
	//				min = array[j];
	//				temp2 = j;
	//				swapIndex = j;
	//			}
	//		}
	//		swap(array[i], array[swapIndex]);
	//	}
	//}
	//s.stop();
	//cout << "selection sort : " << s.getElapsedTime() << "ms" << endl;
	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	exchangeNumber++;
}

void maxNumber(int* top, int* left, int* right)
{
	compareNumber++;
	if (*top < *left)
	{
		if (*left < *right) // top < left < right
		{
			swap(top, right);
		}
		else // top, right < left
		{
			swap(top, left);
		}
	}
	else
	{
		if (*top < *right) // left <= top < right
		{
			swap(top, right);
		}
	}
}