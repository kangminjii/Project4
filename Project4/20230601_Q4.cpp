#include <iostream>

/*
Q4. ���� �˻��� �ϱ� ���� �⺻ �������� �̸� ��������
	���� �˻� ���α׷��� �ۼ��϶�.
	ex) ������ �Է� : 6 5 2 1 8 9 7 4
		�˻� ������ : 9
		 �ڷ� �߿� 9�� �ֽ��ϴ�.
		�˻� ������ : 3
		 �ڷ� �߿� 3�� �����ϴ�.
	1) ���� �˻� ������
	2) ���ʹ� ����
	3) p.120 Q2.�� ���� ���·� ��� 

*/

using namespace std;

int main()
{
	int arr[100];
	int find = 0, length = 0, valid = 0;
	
	cout << "�迭 ��� ���� : ";
	cin >> length;
	cout << "������ �Է� : ";

	for(int i = 0; i < length; i++)
	{
		cin >> arr[i];
	}

	cout << "�˻� ������ : ";
	cin >> find;


	//// #1
	//for (int i = 0; i < length; i++)
	//{
	//	if(i == length - 1)
	//	{
	//		valid = 0;
	//	}
	//	if (find == arr[i])
	//	{
	//		valid = 1;
	//		cout << "�ڷ� �߿� " << find << "�� �ֽ��ϴ�." << endl;
	//		break;
	//	}
	//}
	//if(!valid) cout << "�ڷ� �߿� " << find << "�� �����ϴ�." << endl;


	// #2
	/*arr[length] = find;
	int i = 0;
	while (1)
	{
		if (find == arr[i])
		{
			valid = 1;
			cout << "�ڷ� �߿� " << find << "�� �ֽ��ϴ�." << endl;
			break;
		}
		i++;
	}
	if (i == length || valid == 0) cout << "�ڷ� �߿� " << find << "�� �����ϴ�." << endl;*/


	// #3
	cout << "\t|\t";
	for (int i = 0; i < length; i++)
	{
		cout << i << "\t";
	}
	cout << "\n--------+";
	for (int i = 0; i < length; i++)
	{
		cout << "--------";
	}
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "\t|\t";
		for (int k = 0; k < i; k++)
		{
			cout << "\t";
		}
		cout << "*" << endl;
		cout << "       " << i << "|";
		for (int j = 0; j < length; j++)
		{
			cout << "\t" << arr[j];
		}
		cout << endl << "\t|" << endl;

		if (find == arr[i])
		{
			valid = 1;
			cout << "�ڷ� �߿� " << find << "�� �ֽ��ϴ�." << endl;
			break;
		}
	}
	if (!valid) cout << "�ڷ� �߿� " << find << "�� �����ϴ�." << endl;


	return 0;
}