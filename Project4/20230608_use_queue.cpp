#define _CRT_SECURE_NO_WARNINGS
#include "20230608_queue.h"
#include <iostream>

int main()
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}

	while (1)
	{
		int m, x;
		printf("현재 데이터 수 : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)인큐  (2)디큐  (3)피크  (4)클리어  (5)서치  (6)출력  (0)종료: ");
		scanf("%d", &m);

		if (m == 0)		break;
		switch (m)
		{
		case 1:
			printf("데이터: ");
			scanf("%d", &x);
			if (Enque(&que, x) == -1)
			{
				puts("\a오류: 인큐에 실패하였습니다.");
			}
			break;
		case 2:
			if (Deque(&que, &x) == -1)
			{
				puts("\a오류: 디큐에 실패하였습니다.");
			}
			else
			{
				printf("디큐한 데이터는 %d입니다.\n", x);
			}
			break;
		case 3:
			if (Peek(&que, &x) == -1)
			{
				puts("\a오류: 피크에 실패하였습니다.");
			}
			else
			{
				printf("피크한 데이터는 %d입니다.\n", x);
			}
			break;
		case 4:
			Clear(&que);
			break;
		case 5:
			printf("찾고 싶은 데이터: ");
			scanf("%d", &x);
			if (Search(&que, x) == -1)
				printf("서치 데이터 %d가 존재하지 않습니다.\n", x);
			else
				printf("서치 데이터 %d가 존재합니다.\n", x);
			break;
		case 6:
			printf("데이터: ");
			Print(&que);
			break;
		}
	}

	Terminate(&que);

	return 0;
}