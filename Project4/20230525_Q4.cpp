#include <iostream>
#include <time.h>
using namespace std;

/*
Q4. p.23 �������� Q4. ���α׷� �ۼ�... Q5�� ȿ������ ���϶�
*/

int med3(int, int, int);
int med3_Q5(int a, int b, int c);
//int experiment(int a, int b, int c);

int main()
{
	int middle = med3(1, 2, 3);

	cout << "�� ������ �߾Ӱ��� : " << middle << endl;

	cout << "== ȿ�� �� ==" << endl;

	double start1 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		med3(1, 2, 3);
	}
	double end1 = clock();

	cout << "�� �ڵ� �ð� : " << (end1 - start1) / CLOCKS_PER_SEC << "��" << endl;

	clock_t start2 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		med3_Q5(1, 2, 3);
	}
	clock_t end2 = clock();

	cout << "Q5 �ð� : " << (double(end2) - double(start2)) / CLOCKS_PER_SEC << "��" << endl;

	/*clock_t start3 = clock();
	for (int i = 0; i < 10000000; i++)
	{
		experiment(3, 2, 1);
	}
	clock_t end3 = clock();

	cout << "���� : " << (double(end3) - double(start3)) / CLOCKS_PER_SEC << "��" << endl;*/

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
//		else if (a >= c)	return c; // a<=c ��� �� �κ�
//		else				return a;
//	}
//	else if (a > c)			return a;
//	else if (b > c)			return c;
//	else					return b;
//}