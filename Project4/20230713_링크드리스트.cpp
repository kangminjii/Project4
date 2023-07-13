/*
Q1. 학생관리하는 구조체를 생성하고 번호, 이름을 멤버로 포함 / 구조체 리스트 만들고
	
	1. 입력
		> 번호, 이름받아 리스트에 추가
	2. 삭제
		> 번호 입력받아 리스트에서 삭제
	3. 전체 출력
		> 리스트에 있는 모든 학생의 번호, 이름 출력
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
		cout << "1. 입력  2. 삭제  3. 전체 출력  (0. 종료)" << endl;
		cin >> number;

		switch (number)
		{
		case 1:
			cout << "번호와 이름을 입력해주세요." << endl; 
			cout << "번호 : ";
			cin >> stu[i].number;
			cout << "이름 : ";
			cin >> stu[i++].name;
			break;

		case 2:
			cout << "삭제하고싶은 번호를 입력해주세요." << endl;
			cout << "번호 : ";
			cin >> eraseNumber;


			break;

		case 3:
			for (int j = 0; j < i; j++)
			{
				cout << j + 1 << "번" << endl;
				cout << "번호: " << stu[j].number << endl;
				cout << "이름: " << stu[j].name << endl;
			}
			break;

		default:
			break;
		}
		
		//i++;
	} 
	

	return 0;
}
