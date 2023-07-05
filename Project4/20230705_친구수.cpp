// SNS���� �� �̿����� ģ�� ���� �м�
#include <iostream>
#include "StopWatch.h"
using namespace std;

// N���� �̿���, 2<= N <=100
const int N = 5; 
// ģ�� ���� (a,b) 1<= a,b <= N, a!=b
// �ѱ��� N(N-1)/2 ����
const int relation[10][2] =
{
	{1, 2}, {1, 3}, {2, 4}, {4, 5}, {2,3}, {1,4}
};

int main()
{
	StopWatch s;
	const int max = N * (N - 1) / 2;

	int answer[max] = { 0 };
	int friends[N + 1][N - 1] = { 0 }; // ������ ģ������ ���� �迭

	s.start();
	// ������ ģ��
	for (int j = 0; j < 10; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (relation[j][0] == i)
			{
				answer[i] += 1;
				friends[i][answer[i]] = relation[j][1];
			}
			else if (relation[j][1] == i)
			{
				answer[i] += 1;
				friends[i][answer[i]] = relation[j][0];
			}
		}
	}
	
	// �Ѵٸ� �ǳ� ģ��
	int bestfriend, signal, count;
	for (int k = 1; k <= N; k++)
	{
		for (int j = 0; j < max; j++)
		{
			if (relation[j][0] == k)
			{
				signal = 0;
				bestfriend = relation[j][1];
			}
			else if (relation[j][1] == k)
			{
				signal = 1;
				bestfriend = relation[j][0];
			}
			else
				signal = 2;

			for (int i = 0; i < max; i++)
			{
				if (signal == 0) // a�� k�϶� (k = �ڱ� ��ȣ)
				{
					if (i != j)
					{
						if (relation[i][0] == bestfriend )
						{
							if (answer[k] >= N - 1) // ��ο� ģ����
								continue;
							
							count = 0;
							for (int z = 0; z < N - 1; z++)
							{
								if (friends[k][z] != relation[i][1])
									count++;
								else
								{
									count = 0;
									break;
								}
							}
							if (count > 0)
							{
								if (friends[k][0] == 0)
									friends[k][0] = relation[i][1];

								answer[k] += 1;
							}
						}
						else if (relation[i][1] == bestfriend)
						{
							if (answer[k] >= N - 1) // ��ο� ģ����
								continue;

							count = 0;
							for (int z = 0; z < N - 1; z++)
							{
								if (friends[k][z] != relation[i][0])
									count++;
								else
								{
									count = 0;
									break;
								}
							}
							if (count > 0)
							{
								if (friends[k][0] == 0)
									friends[k][0] = relation[i][0];

								answer[k] += 1;
							}
						}
					}
				}
				if (signal == 1) // b�� k�϶� (k = �ڱ� ��ȣ)
				{
					if (i != j)
					{
						if (relation[i][0] == bestfriend)
						{
							if (answer[k] >= N - 1) // ��ο� ģ����
								continue;

							count = 0;
							for (int z = 0; z < N - 1; z++)
							{
								if (friends[k][z] != relation[i][1])
									count++;
								else
								{
									count = 0;
									break;
								}
							}

							if (count > 0)
							{
								if (friends[k][0] == 0)
									friends[k][0] = relation[i][1];

								answer[k] += 1;
							}
						}
						else if (relation[i][1] == bestfriend)
						{
							if (answer[k] >= N - 1) // ��ο� ģ����
								continue;

							count = 0;
							for (int z = 0; z < N - 1; z++)
							{
								if (friends[k][z] != relation[i][0])
									count++;
								else
								{
									count = 0;
									break;
								}
							}

							if (count > 0)
							{
								if (friends[k][0] == 0)
									friends[k][0] = relation[i][0];

								answer[k] += 1;
							}
						}
					}
				}
			}
		}
	}
	s.stop();

	//cout << "�ð� : " << s.getElapsedTime() << "ms" << endl;

	for (int i = 1; i <= N; i++)
		cout << i << "�� ģ�� : " << answer[i] << "��" << endl;


	return 0;
}