#define _CRT_SECURE_NO_WARNINGS
#include "20230608_queue.h"
#include <iostream>

int main()
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("ť�� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1)
	{
		int m, x;
		printf("���� ������ �� : %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť  (2)��ť  (3)��ũ  (4)Ŭ����  (5)��ġ  (6)���  (0)����: ");
		scanf("%d", &m);

		if (m == 0)		break;
		switch (m)
		{
		case 1:
			printf("������: ");
			scanf("%d", &x);
			if (Enque(&que, x) == -1)
			{
				puts("\a����: ��ť�� �����Ͽ����ϴ�.");
			}
			break;
		case 2:
			if (Deque(&que, &x) == -1)
			{
				puts("\a����: ��ť�� �����Ͽ����ϴ�.");
			}
			else
			{
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			}
			break;
		case 3:
			if (Peek(&que, &x) == -1)
			{
				puts("\a����: ��ũ�� �����Ͽ����ϴ�.");
			}
			else
			{
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			}
			break;
		case 4:
			Clear(&que);
			break;
		case 5:
			printf("ã�� ���� ������: ");
			scanf("%d", &x);
			if (Search(&que, x) == -1)
				printf("��ġ ������ %d�� �������� �ʽ��ϴ�.\n", x);
			else
				printf("��ġ ������ %d�� �����մϴ�.\n", x);
			break;
		case 6:
			printf("������: ");
			Print(&que);
			break;
		}
	}

	Terminate(&que);

	return 0;
}