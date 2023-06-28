#include <iostream>

/*
Q3. p.122 연습문제 Q4처럼 이진검색 과정을
	자세히 출력하는 프로그램을 작성하시오.
	선형검색과 이진검색의 속도를 비교하라.

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

	while (!check) // 검색할 숫자가 없는 경우 방지
	{
		cout << "찾고 싶은 수 : ";
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
		// 출력
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

		// 이진탐색
		if (range % 2 == 0)
			range /= 2;
		else
			range = range / 2 + 1;

		if (array[middle] == answer)
		{
			find = 1;
			cout << endl << answer << "은 array[" << middle << "]에 있습니다." << endl;
		}
		else if (answer < array[middle]) // 왼쪽 탐색
		{
			if (n % 2 == 0)
				middle = middle - range / 2 - 1;
			else
				middle = middle - range / 2;
		}
		else // 오른쪽 탐색
		{
			if (n % 2 == 0)
				middle = middle + range / 2;
			else
				middle = middle + range / 2;
		}
	}
}