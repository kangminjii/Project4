#include <iostream>
#include <string>
using namespace std;

void Boyer_Moore(string question, string pattern);
int main()
{
	Boyer_Moore("ABCXDEZCABACABAC", "ABAC");
	Boyer_Moore("HEYHIBYE", "BYE");
	Boyer_Moore("ABCDDDEEEDDD", "DDD");
	Boyer_Moore("ABCDDDEEEDDD", "ZZ");

	return 0;
}

void Boyer_Moore(string question, string pattern)
{
	cout << question << endl;

	int* table = new int[pattern.size() + 1];
	
	// table값 만들기
	for (int i = 0; i < pattern.size(); i++)
	{
		table[i] = pattern.size() - i - 1;
		for (int j = 0; j < i; j++)
		{
			if (pattern[i] == pattern[j])
			{	// 최솟값을 집어넣기
				if (table[i] < table[j])
					table[j] = table[i];
			}
		}
	}
	table[pattern.size() - 1] = pattern.size(); // 마지막 table값

	
	int jump = 0, count = 0, temp = 0, location = 0;

	for (int i = pattern.size() - 1; i >= 0; i--)
	{
		temp = 0;

		if (question[i] != pattern[i - jump - count])
		{
			while (question[i] != pattern[i - temp - jump])
			{
				if (i - temp - jump == 0)	break;
				else						temp++;
			}

			if (i == temp + jump) // 패턴과 같은 문자가 없다
			{
				jump += pattern.size();
				i += pattern.size() + 1;
			}
			else // pattern[i-temp]에 같은 문자가 있다
			{
				int a = jump;
				jump += table[i - temp - jump];
				i += table[i - temp - a] + 1;
			}

			count = 0;
		}
		else
		{
			count++;
			jump -= 1;
		}

		// 패턴을 찾았을 때
		if (count == pattern.size())
		{
			location = i;
			// 출력
			for (int k = 0; k < location; k++)
				cout << " ";

			cout << pattern << endl;
			break;
		}
		// 패턴을 못찾았을 때
		if (i == question.size() + pattern.size())
		{
			cout << pattern << endl;
			cout << "찾는 단어가 없습니다." << endl;
			break;
		}
	}

	delete [] table;
}