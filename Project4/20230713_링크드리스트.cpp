/*
Q1. �л������ϴ� ����ü�� �����ϰ� ��ȣ, �̸��� ����� ���� / ����ü ����Ʈ �����
	
	1. �Է�
		> ��ȣ, �̸��޾� ����Ʈ�� �߰�
	2. ����
		> ��ȣ �Է¹޾� ����Ʈ���� ����
	3. ��ü ���
		> ����Ʈ�� �ִ� ��� �л��� ��ȣ, �̸� ���
*/

#include <iostream>
#include <string>
using namespace std;


struct Student
{
	double number;
	string name;
	Student* next;
};


int main()
{
	Student stu[10];

	int number = 1, i = 0, eraseNumber = 0;

	while (number != 0)
	{
		cout << "1. �Է�  2. ����  3. ��ü ���  (0. ����)" << endl;
		cin >> number;

		switch (number)
		{
		case 1:
			cout << "��ȣ�� �̸��� �Է����ּ���." << endl; 
			cout << "��ȣ : ";
			cin >> stu[i].number;
			cout << "�̸� : ";
			cin >> stu[i++].name;
			break;

		case 2:
			cout << "�����ϰ���� ��ȣ�� �Է����ּ���." << endl;
			cout << "��ȣ : ";
			cin >> eraseNumber;


			break;

		case 3:
			for (int j = 0; j < i; j++)
			{
				cout << j + 1 << "��" << endl;
				cout << "��ȣ: " << stu[j].number << endl;
				cout << "�̸�: " << stu[j].name << endl;
			}
			break;

		default:
			break;
		}
		
		//i++;
	} 
	

	return 0;
}
