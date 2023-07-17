#include <iostream>
using namespace std;


const int SIZE = 5;

typedef struct List
{
	int* arr1;
	List* next;
};

typedef struct Index
{
	List* head;
};

int main()
{
	List* aa = new List;
	Index* ii = new Index;

	// 변수 선언
	int arr[SIZE] = {6,9,8,2,3};
	int pointing[SIZE] = {1,2,3,4,-1};
	int free[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
		free[i] = -1;

	int deleteNumber;		// 삭제하려는 숫자
	int temp = 0;	// 삭제하려는 숫자 인덱스 저장
	int count = 0;	// 삭제하려는 숫자 유무 판단
	int k = 0;		// free 배열 인덱스

	int addNumber;	// 추가하려는 숫자
	int temp2 = 0;  // 추가하려는 숫자 위치에 pointing 재정의

	//확인용 출력
	cout << "BEFORE" << endl << "arr : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl << "pointing : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << pointing[i] << " ";
	cout << endl << "free : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << free[i] << " ";
	cout << endl;

	//// DELETE
	{
		// 삭제할 숫자 부분
		cout << "삭제하고싶은 숫자 : ";
		cin >> deleteNumber;
		while (1)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (deleteNumber == arr[i])
				{
					count = 1;
					break;
				}
				else
					count = 0;
			}

			if (count)
				break;
			else
			{
				cout << "삭제하고싶은 숫자 : ";
				cin >> deleteNumber;
			}
		}

		// 삭제된 부분 인덱스
		for (int i = 0; i < SIZE; i++)
		{
			if (deleteNumber == arr[i])
				temp = i;
		}
		arr[temp] = NULL;

		// 인덱스 변경부분
		if (pointing[temp] != -1)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (pointing[i] == temp)
				{
					pointing[i] = pointing[temp];
				}
			}
			//pointing[SIZE - 1] = temp;
			pointing[temp] = -1;
		}
		free[k++] = temp;
	}
	
	//확인용 출력
	cout << endl << "AFTER" << endl << "arr: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl << "pointing : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << pointing[i] << " ";
	cout << endl << "free : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << free[i] << " ";
	cout << endl;

	//// ADD
	cout << "추가할 숫자 입력 : ";
	cin >> addNumber;
	
	for (int i = 0; i < SIZE; i++)
	{
		if (free[i] != -1)
		{
			temp2 = free[i];
			arr[free[i]] = addNumber;
			free[--k] = -1;
			break;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (pointing[i] == -1)
		{
			if (i != temp)
				pointing[i] = temp2;
		}
	}

	//확인용 출력
	cout << endl << "AFTER" << endl << "arr: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl << "pointing : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << pointing[i] << " ";
	cout << endl << "free : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << free[i] << " ";
	cout << endl;


	// 찐 배열 출력
	int min = SIZE;
	for (int i = 0; i < SIZE; i++)
	{
		if (pointing[i] > -1)
		{
			if (min > pointing[i])	
				min = pointing[i];
		}
	}

	int x = min;
	cout << "\n====Real===\n";
	while (1)
	{
		cout << arr[x] << " ";
		x = pointing[x];
		if (x == -1) break;
	}


	return 0;
}