#include <iostream>
#include <time.h>
using namespace std;

/*
Q4. p.23 연습문제 Q4. 프로그램 작성... Q5와 효율성을 비교하라
*/

int med3(int, int, int);
int med3_Q5(int a, int b, int c);
//int experiment(int a, int b, int c);

int main()
{
	int middle = med3(1, 2, 3);

	cout << "세 숫자의 중앙값은 : " << middle << endl;

	cout << "== 효율 비교 ==" << endl;

	double start1 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		med3(1, 2, 3);
	}
	double end1 = clock();

	cout << "내 코드 시간 : " << (end1 - start1) / CLOCKS_PER_SEC << "초" << endl;

	clock_t start2 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		med3_Q5(1, 2, 3);
	}
	clock_t end2 = clock();

	cout << "Q5 시간 : " << (double(end2) - double(start2)) / CLOCKS_PER_SEC << "초" << endl;

	/*clock_t start3 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		experiment(3, 2, 1);
	}
	clock_t end3 = clock();

	cout << "실험 : " << (double(end3) - double(start3)) / CLOCKS_PER_SEC << "초" << endl;*/

}

int med3(int a, int b, int c)
{
	if (a >= b)
	{
		if (b >= c)			return b;
		else if (a <= c)	return a;
		else return c;
	}
	else if (a > c)			return a;
	else if (b > c)			return c;
	else					return b;	
}

int med3_Q5(int a, int b, int c)
{
	if ((b >= a && c <= a) || (b <= a && c >= a))
		return a;
	else if ((a > b && c < b) || (a < b && c > b))
		return b;
	return c;
}

//int experiment(int a, int b, int c)
//{
//	if (a >= b)
//	{
//		if (b >= c)			return b;
//		else if (a >= c)	return c; // a<=c 대신 쓴 부분
//		else				return a;
//	}
//	else if (a > c)			return a;
//	else if (b > c)			return c;
//	else					return b;
//}