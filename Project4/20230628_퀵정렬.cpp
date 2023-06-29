/*
퀵정렬 알고리즘을 구현하라.
*/

#include <iostream>

const int NUM = 7;
using namespace std;

void swap(int* a, int* b);

int main()
{
	int array[NUM] = { 5,8,4,2,6,1,3 };
	//int array[NUM] = { 5,8,4,2,6,1,3,9,7 };
	// 초기 설정
	
	int Left[NUM], Right[NUM];

	for (int i = 0; i < NUM/2; i++)
	{
		Left[i] = array[i];
		Right[i] = array[NUM - 1 - i];
	}

	int* pivot = &array[NUM / 2];
	int* pr = array;
	int* pl = array + NUM - 1;

	int prIndex = NUM - 1;
	int plIndex = 0;

	while (1)
	{
		if (pr < pivot) // pivot 이하값이 오른쪽에 있을때
		{
			if (pl >= pivot)
			{
				swap(pl, pr);
				pr--;
				pl++;

				prIndex--;
				plIndex++;
			}
			else
			{
				pl++;
				plIndex++;
			}
		}
		else if (pl > pivot) // pivot 이상값이 왼쪽에 있을때
		{
			if (pr <= pivot)
			{
				swap(pl, pr);
				pr--;
				pl++;

				prIndex--;
				plIndex++;
			}
			else
			{
				prIndex--;
				pr--;
			}
		}
		else if (pr == pl) // pl과 pr이 만날때
			{
				swap(pl, pr);
				pr--;
				pl++;

				prIndex--;
				plIndex++;
			}
				
		if (pr < pl)	break;
	}

	for (int i = 0; i < NUM; i++)
		cout << array[i] << " ";

	cout << endl;
		
		
	//if(pr > array)



	int i = 0;
	while (0< prIndex)
	{
		i++;
		Left[i] = array[i];
	} 





}

void swap(int* a, int* b)
{
	int* temp = a;
	a = b;
	b = temp;
}