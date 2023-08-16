#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("*****    1.开始     0.退出    *****\n");
	printf("***********************************\n");
	printf("请选择：");
}

void game()
{
	
	char board[ROW][COL] = {0};
	InitiBoard(board);
	int x = 1;
	int y = 1;
	char judge = 'C';

	int hand = 0;
	printf("玩家想要先手还是后手（先手：1，后手：0）\n请输入：");
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
					printf("玩家获胜了，恭喜\n");
				else if (judge == 'E')
					printf("电脑获胜了\n");
				else
					printf("未分出胜负\n");
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
					printf("玩家获胜了，恭喜\n");
				else if (judge == 'E')
					printf("电脑获胜了\n");
				else
					printf("未分出胜负\n");
				break;
			}
			else
			{
				printf("输入错误，请重试\n");

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
			printf("是否再玩一次\n");
		}
		else if (i == 0)
		{
			printf("游戏结束");
			break;
		}
			
		else
			printf("输入错误\n");
	}
	return 0;
}