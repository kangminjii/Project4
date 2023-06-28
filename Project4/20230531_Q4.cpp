#include <iostream>

/*
Q4. p.78 5번 문제
*/

using namespace std;

void swap(int array[], int n);

int main()
{
	int n;
	int *array = new int[sizeof(array)];

	cout << "배열 요소 개수 : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	
	swap(array, n);
}

void swap(int array[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		int temp = array[i];
		array[i] = array[n - 1 - i];
		array[n - 1 - i] = temp;
		cout << "a[" << i << "]와 a[" << n - 1 - i << "]를 교환합니다." << endl;
		for (int j = 0; j < n; j++)
			cout << array[j] << " ";
		cout << endl;
	}

	cout << "역순 정렬을 종료합니다." << endl;
}