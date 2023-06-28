/*
Q3. ���� �Լ��� ����Ͽ� ���� ������ ȭ�鿡 ����ϴ� �ڵ带 �ۼ��϶�.
	���ȣ���� �̿��϶�.
	void reverseDisplay(int value)
	void reverseDisplay(const string &s)

	ex > reverseDisplay(12345)
	��� > 54321

	ex > reverseDisplay("abcd")
	��� > dcba
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