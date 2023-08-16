#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("*****    1.��ʼ     0.�˳�    *****\n");
	printf("***********************************\n");
	printf("��ѡ��");
}

void game()
{
	
	char board[ROW][COL] = {0};
	InitiBoard(board);
	int x = 1;
	int y = 1;
	char judge = 'C';

	int hand = 0;
	printf("�����Ҫ���ֻ��Ǻ��֣����֣�1�����֣�0��\n�����룺");
		while (1)
		{
			scanf("%d", &hand);
			if (hand == 1)
			{

				DisplayBoard(board);
				while (1)
				{

					PlayerMove(board);
					judge = WinLoseEnd(board);
					if (judge != 'C')
						break;
					ComputerMove(board);
					judge = WinLoseEnd(board);
					if (judge != 'C')
						break;

				}
				if (judge == 'P')
					printf("��һ�ʤ�ˣ���ϲ\n");
				else if (judge == 'E')
					printf("���Ի�ʤ��\n");
				else
					printf("δ�ֳ�ʤ��\n");
				break;
			}
			else if (hand == 0)
			{

				
				while (1)
				{

					ComputerMove(board);
					judge = WinLoseEnd(board);
					if (judge != 'C')
						break;
					PlayerMove(board);
					judge = WinLoseEnd(board);
					if (judge != 'C')
						break;

				}
				if (judge == 'P')
					printf("��һ�ʤ�ˣ���ϲ\n");
				else if (judge == 'E')
					printf("���Ի�ʤ��\n");
				else
					printf("δ�ֳ�ʤ��\n");
				break;
			}
			else
			{
				printf("�������������\n");

			}
		}
	

}

int main()
{
	srand((unsigned int)time(NULL));
	int i = 1;
	while (1)
	{
		menu();
		scanf("%d", &i);
		if (i == 1)
		{
			game();
			printf("�Ƿ�����һ��\n");
		}
		else if (i == 0)
		{
			printf("��Ϸ����");
			break;
		}
			
		else
			printf("�������\n");
	}
	return 0;
}