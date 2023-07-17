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

	// ���� ����
	int arr[SIZE] = {6,9,8,2,3};
	int pointing[SIZE] = {1,2,3,4,-1};
	int free[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
		free[i] = -1;

	int deleteNumber;		// �����Ϸ��� ����
	int temp = 0;	// �����Ϸ��� ���� �ε��� ����
	int count = 0;	// �����Ϸ��� ���� ���� �Ǵ�
	int k = 0;		// free �迭 �ε���

	int addNumber;	// �߰��Ϸ��� ����
	int temp2 = 0;  // �߰��Ϸ��� ���� ��ġ�� pointing ������

	//Ȯ�ο� ���
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
		// ������ ���� �κ�
		cout << "�����ϰ���� ���� : ";
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
				cout << "�����ϰ���� ���� : ";
				cin >> deleteNumber;
			}
		}

		// ������ �κ� �ε���
		for (int i = 0; i < SIZE; i++)
		{
			if (deleteNumber == arr[i])
				temp = i;
		}
		arr[temp] = NULL;

		// �ε��� ����κ�
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
	
	//Ȯ�ο� ���
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
	cout << "�߰��� ���� �Է� : ";
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

	//Ȯ�ο� ���
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


	// �� �迭 ���
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