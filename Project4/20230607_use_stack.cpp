#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "20230607_stack.h"

// main.cpp
using namespace std;

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("스택 생성에 실패했습니다.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		//printf("현재 데이터수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)클리어 (5)서치 (6)출력 (0)종료 : ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: //푸시
			printf("데이터: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류: 푸시에 실패했습니다.");
			break;
		case 2: // 팝
			if (Pop(&s, &x) == -1)
				puts("\a오류: 팝에 실패했습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;
		case 3: // 피크
			if (Peek(&s, &x) == -1)
				puts("\a오류: 피크에 실패했습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 4: // 클리어
			Clear(&s);
			break;
		case 5: // 서치
			printf("찾고 싶은 데이터: ");
			scanf("%d", &x);
			if (Search(&s, x) == -1)
				printf("서치 데이터 %d가 존재하지 않습니다.\n", x);
			else
				printf("서치 데이터 %d가 존재합니다.\n", x);
			break;
		case 6: // 출력
			Print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}