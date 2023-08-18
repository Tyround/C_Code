#include "game.h"

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitiBoard(mine, '0');
	InitiBoard(show, '*');
	DisplayBoard(show);
	int x = 0;
	int y = 0;
	printf("开始扫雷\n请输入雷数：");
	int ran = 1;
	while (1)
	{
		scanf("%d", &ran);
		if (ran < 1 || ran >= 80)
			printf("输入不合法，请重新输入\n");
		else
			break;
	}
	//此处在第一次扫雷后再生成雷，防止第一次就扫到雷情况发生
	while (1)
	{
		printf("请输入扫雷坐标：");
		scanf("%d %d", &x, &y);
		if (x > 0 && x < 10 && y >0 && y < 10)
			;
		else
		{
			printf("坐标非法，请重新输入\n");
			continue;
		}
		mine[x][y] = '2';
		break;
	}
		create_mine(mine, ran);
		scan_super(mine, show, x, y);
		DisplayBoard(show);
		//此处用于监视雷区
		DisplayBoard(mine);

	while (1)
	{
		printf("请输入扫雷坐标：");
		scanf("%d %d", &x, &y);
		if (x > 0 && x < 10 && y >0 && y < 10)
			;
		else
		{
			printf("坐标非法，请重新输入\n");
			continue;
		}
		if (mine[x][y] == '1')
		{
			printf("\n雷炸了，游戏结束\n\n");
			break;
		}
		else if (mine[x][y] == '2' || mine[x][y] == '3')
		{
			printf("该处已被扫描，请重新输入");
				continue;
		}
		else
		{
			scan_super(mine, show, x, y);
			
			printf("该处安全，请继续扫雷\n");
			DisplayBoard(show);
		}
		int cont = 1;
		cont = End(mine);
		if (cont == 0)
		{
			printf("\n扫雷完成，游戏胜利\n\n");
			break;
		}

	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int play = 0;
	while (1)
	{
		menu();
		scanf("%d", &play);
		 if (play == 1)
		{
			game();
			printf("是否再玩一次\n");
		}
		else if (play == 0)
		{
			printf("游戏结束");
			break;
		}
		else
			printf("输入错误\n");
	}
	return 0;
}
