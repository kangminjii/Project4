/*
 Q1. Merge Sort를 구현하고 
	 이전 알고리즘과 속도를 비교하라.
*/

#include <iostream>

using namespace std;
const int NUM = 12;

int main()
{
	int arr[NUM] = { 5,6,4,8,3,7,9,0,1,5,2,3 };
	int answer[NUM];
	int divided[12][12];
	
	int temp = NUM;
	//while (1)
	//{
		for (int j = 0; j < NUM; j += 2)
		{
			for (int i = 0; i < temp / 2; i++)
			{
				divided[j][i] = arr[i];
				divided[j + 1][i] = arr[temp - 1 - i];
			}
			temp /= 2;

			if (temp < 1)
			{
				divided[j][0] = arr[0];
				divided[j+1][0] = arr[1];
				break;
			}
		}
	//}

		int j = 0;
	for (int i = 0; i < NUM; i++)
	{
		cout << divided[j][i];
	}






	return 0;
}