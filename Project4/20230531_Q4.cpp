#include <iostream>

/*
Q4. p.78 5�� ����
*/

using namespace std;

void swap(int array[], int n);

int main()
{
	int n;
	int *array = new int[sizeof(array)];

	cout << "�迭 ��� ���� : ";
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
		cout << "a[" << i << "]�� a[" << n - 1 - i << "]�� ��ȯ�մϴ�." << endl;
		for (int j = 0; j < n; j++)
			cout << array[j] << " ";
		cout << endl;
	}

	cout << "���� ������ �����մϴ�." << endl;
}