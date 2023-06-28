/*
Q3. 버블소트를 구현하라.
	버전 1, 2, 3 각각에 대해 프로그램을 작성하고 각각의 성능을 비교하라.
	p.219
*/

#include <iostream>

using namespace std;

const int SIZE = 7;
void swap(int* a, int* b);
void print(int* array, int n);

int main()
{
	int sort[SIZE] = { 1,3,9,4,7,8,6 }; // 정렬할 배열
	char check[SIZE];
	int isSorted = 0, count = 0, exchangeNumber = 0, compareNumber = 0;



	// 버젼 1.

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
	cout << "총 비교를 " << compareNumber << "회 했습니다." << endl;
	cout << "총 교환을 " << exchangeNumber << "회 했습니다." << endl;
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