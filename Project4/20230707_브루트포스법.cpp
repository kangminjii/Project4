#include <iostream>
#include <string>
using namespace std;

void Print(string s, string a, int counts);
void SearchString(string s, string a);

static int counts = 0;
static int temp = 0;
static int different = 0;

int main()
{
	string search = "ABABCDEFGHA";
	string answer = "ABC";

	SearchString(search, answer);

	return 0;
}

void Print(string search, string answer, int counts)
{
	// search 문자열
	for (int i = 0; i < search.size(); i++)
		cout << search[i];
	cout << endl;

	if (counts > 0)
	{
		// 부호
		// temp = 틀렸을 때 카운팅되는 수
		for (int i = 0; i < temp; i++)
			cout << " ";
		for (int i = 0; i < counts - 1; i++)
			cout << " ";
		cout << "+" << endl;

		// answer 문자열
		for (int i = 0; i < temp; i++)
			cout << " ";
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i];
		cout << endl << endl;
	}
	else
	{
		// 부호
		for (int i = 0; i < temp; i++)
			cout << " ";
		for (int i = 0; i < counts; i++)
			cout << " ";
		cout << "|" << endl;

		// answer 문자열
		for (int i = 0; i < temp; i++)
			cout << " ";
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i];
		cout << endl << endl;
	}
}

void SearchString(string search, string answer)
{
	for (int i = 0; i < search.size(); i++)
	{
		if (search[temp + i] == answer[i])
		{
			counts++;
			Print(search, answer, counts);
		}
		else
		{
			counts = 0;
			i = -1;
			Print(search, answer, counts);
			temp++;
		}
		if (answer.size() == counts)	break;
	}
}