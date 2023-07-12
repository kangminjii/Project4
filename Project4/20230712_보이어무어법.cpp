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
	
	// table�� �����
	for (int i = 0; i < pattern.size(); i++)
	{
		table[i] = pattern.size() - i - 1;
		for (int j = 0; j < i; j++)
		{
			if (pattern[i] == pattern[j])
			{	// �ּڰ��� ����ֱ�
				if (table[i] < table[j])
					table[j] = table[i];
			}
		}
	}
	table[pattern.size() - 1] = pattern.size(); // ������ table��

	
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

			if (i == temp + jump) // ���ϰ� ���� ���ڰ� ����
			{
				jump += pattern.size();
				i += pattern.size() + 1;
			}
			else // pattern[i-temp]�� ���� ���ڰ� �ִ�
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

		// ������ ã���� ��
		if (count == pattern.size())
		{
			location = i;
			// ���
			for (int k = 0; k < location; k++)
				cout << " ";

			cout << pattern << endl;
			break;
		}
		// ������ ��ã���� ��
		if (i == question.size() + pattern.size())
		{
			cout << pattern << endl;
			cout << "ã�� �ܾ �����ϴ�." << endl;
			break;
		}
	}

	delete [] table;
}