#include <iostream>

/*
Q4. p.42 �������� 18�� ������ n���� ���� �𷡽ð踦 ����ϴ� ���α׷��� �ۼ��϶�.
	ex) 3				2
		1 1 1 1 1		1 1 1
		  2 2 2			  2
		    3			1 1 1
		  2 2 2
		1 1 1 1 1

*/

using namespace std;

int main()
{
	int n;
	int count = 0;

	cin >> n;
	cout << endl;
	int total = 2 * n - 1;


	for (int i = 1; i <= total; i++)
	{
		if (i >= n) // ���~��
		{
			for (int k = 0; k < count; k++)
			{
				cout << " ";
			}
			for (int j = 1; j <= (total - 2*count); j++)
			{
				cout << count + 1;
			}
			count--;
			cout << endl;
		}
		else // ���κ�
		{
			for (int k = 0; k < count; k++)
			{
				cout << " ";
			}
			for (int j = 1; j <= (total - 2*count); j++)
			{
				cout << count + 1;
			}
			count++;
			cout << endl;
		}
	}
}