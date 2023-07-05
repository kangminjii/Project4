// SNS에서 각 이용자의 친구 수를 분석
#include <iostream>
#include "StopWatch.h"
using namespace std;

// N명의 이용자, 2<= N <=100
const int N = 5; 
// 친구 관계 (a,b) 1<= a,b <= N, a!=b
// 총길이 N(N-1)/2 이하
const int relation[10][2] =
{
	{1, 2}, {1, 3}, {2, 4}, {4, 5}, {2,3}, {1,4}
};

int main()
{
	StopWatch s;
	const int max = N * (N - 1) / 2;

	int answer[max] = { 0 };
	int friends[N + 1][N - 1] = { 0 }; // 인접한 친구들을 담은 배열

	s.start();
	// 인접한 친구
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
	
	// 한다리 건너 친구
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
				if (signal == 0) // a가 k일때 (k = 자기 번호)
				{
					if (i != j)
					{
						if (relation[i][0] == bestfriend )
						{
							if (answer[k] >= N - 1) // 모두와 친구다
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
							if (answer[k] >= N - 1) // 모두와 친구다
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
				if (signal == 1) // b가 k일때 (k = 자기 번호)
				{
					if (i != j)
					{
						if (relation[i][0] == bestfriend)
						{
							if (answer[k] >= N - 1) // 모두와 친구다
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
							if (answer[k] >= N - 1) // 모두와 친구다
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

	//cout << "시간 : " << s.getElapsedTime() << "ms" << endl;

	for (int i = 1; i <= N; i++)
		cout << i << "의 친구 : " << answer[i] << "명" << endl;


	return 0;
}