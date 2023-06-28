/*
Q3. 다음 함수를 사용하여 값을 역으로 화면에 출력하는 코드를 작성하라.
	재귀호출을 이용하라.
	void reverseDisplay(int value)
	void reverseDisplay(const string &s)

	ex > reverseDisplay(12345)
	결과 > 54321

	ex > reverseDisplay("abcd")
	결과 > dcba
*/

#include <iostream>
#include <string>

using namespace std;

void reverseDisplay(int);
void reverseDisplay(const string &s);

int main()
{
	reverseDisplay(12345);
	cout << endl;
	reverseDisplay("abcd");

	return 0;
}

void reverseDisplay(int value)
{
	if(value > 0)
	{
		cout << value % 10;
		value /= 10;
		reverseDisplay(value);
	}
}

void reverseDisplay(const string &s)
{
	if (s.length() > 0)
	{
		cout << s.back();
		reverseDisplay(s.substr(0, s.size() - 1));
	}
}