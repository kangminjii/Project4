#include <iostream>

/*
Q4. 선형 검색을 하기 위한 기본 순서도와 이를 바탕으로
	선형 검색 프로그램을 작성하라.
	ex) 데이터 입력 : 6 5 2 1 8 9 7 4
		검색 데이터 : 9
		 자료 중에 9가 있습니다.
		검색 데이터 : 3
		 자료 중에 3은 없습니다.
	1) 선형 검색 만으로
	2) 보초법 적용
	3) p.120 Q2.와 같은 형태로 출력 

*/

using namespace std;

int main()
{
	int arr[100];
	int find = 0, length = 0, valid = 0;
	
	cout << "배열 요소 개수 : ";
	cin >> length;
	cout << "데이터 입력 : ";

	for(int i = 0; i < length; i++)
	{
		cin >> arr[i];
	}

	cout << "검색 데이터 : ";
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
	//		cout << "자료 중에 " << find << "가 있습니다." << endl;
	//		break;
	//	}
	//}
	//if(!valid) cout << "자료 중에 " << find << "은 없습니다." << endl;


	// #2
	/*arr[length] = find;
	int i = 0;
	while (1)
	{
		if (find == arr[i])
		{
			valid = 1;
			cout << "자료 중에 " << find << "가 있습니다." << endl;
			break;
		}
		i++;
	}
	if (i == length || valid == 0) cout << "자료 중에 " << find << "은 없습니다." << endl;*/


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
			cout << "자료 중에 " << find << "가 있습니다." << endl;
			break;
		}
	}
	if (!valid) cout << "자료 중에 " << find << "은 없습니다." << endl;


	return 0;
}