#include <iostream>

/*
Q3. 학교에 100개의 사물함과 100명의 학생이 있다.
	모든 사물함이 첫 날에는 닫혀 있다.
	학생이 교실로 들어가면서
		s1이라는 첫 번째 학생은 모든 사물함을 연다.
		s2라는 두 번째 학생은 L2부터 시작하여 1개씩 건너 뛰면서 사물함을 닫는다.
		s3라는 세 번째 학생은 L3부터 시작하여 2개씩 건너 뛰면서 사물함의 상태를 변경한다.
		s4라는 네 번째 학생은 L4부터 시작하여 3개씩 건너 뛰면서 사물함의 상태를 변경한다.
		학생 s100이 L100사물함을 변경할 때까지 계속 된다.
	모든 학생이 교실을 통과하고 난 다음, 어떤 사물함이 열려있는지, 열려있는 모든 사물함의 번호를 출력하는 프로그램을 작성하라.
*/

using namespace std;

int main()
{
	// 닫혀있다 - 0, 열려있다 - 1
	int L[100] = { 0 };

	for (int i = 0; i < 100; i++)
	{
		if ((i + 1) * i + i < 100)
		{
			if (L[(i + 1) * i + i] == 1)	L[(i + 1) * i + i] = 0;
			else							L[(i + 1) * i + i] = 1;
		}
	}

	// 출력
	for (int i = 0; i < 100; i++)
	{
		if (L[i] == 1)	cout << i+1 << "번째 사물함이 열려있습니다." << endl;
	}

	return 0;
}