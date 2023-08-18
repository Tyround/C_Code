#include "game.h"

void menu()
{
	printf("***********************************\n");
	printf("*****    1.开始     0.退出    *****\n");
	printf("***********************************\n");
	printf("请选择：");
}


void InitiBoard(char arr[ROWS][COLS], char x)
{  
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] = x;
		}
	}
}

//显示数组存储
void DisplayBoard(char board[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	int k = 0;
	printf("   ");
	for(k=0;k<ROW;k++)
	printf(" %d  ", k + 1);
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= COL; j++)
		{
			
			printf(" %c ", board[i][j]);

			if (j == COL)
			{
				printf("\n");
				break;
			}
			else
				printf("|");
		}
		if (i != ROW)
		{
			printf("   ");
			for (j = 1; j <= COL; j++)
			{
				printf("---");
				if (j == COL)
				{

					printf("\n");
					break;
				}
				else
					printf("|");
			}
		}
		else
		{
			printf("\n");
			break;
		}
	}
}

//随机创建雷
void create_mine(char arr[ROWS][COLS], int ran)
{
	int col = 0;
	int row = 0;
	int mine = 0;
	for (mine = 0; mine < ran; mine++)
	{
		while (1)
		{
			row = rand() % ROW + 1;
			col = rand() % COL + 1;
			if (arr[row][col] == '0')
			{
				arr[row][col] = '1';
				break;
			}
		}
	}
}

//计算周围雷的数量
char scan_num(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	int i = 0;
	int j = 0;
	for(i=x-1;i<=x+1;i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
				count++;
		}
	}
	return count + 0x30;
}

//判定是否结束
int End(char mine[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	for (x = 1; x <= ROW; x++)
	{
		for (y = 1; y <= COL; y++)
		{
			if (mine[x][y] == '0')
				return 1;
		}
	}
	return 0;
}

void scan_super(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (mine[x][y] != '3')
	{
		int i = 0;
		int j = 0;
		mine[x][y] = '2';
		show[x][y] = scan_num(mine, x, y);
		if (scan_num(mine, x, y) == '0')
		{
			mine[x][y] = '3';
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (i == 0 && j == 0)
						continue;
					if(x + i >0 && x + i <ROWS-1 && y+j > 0 && y + j < COLS - 1)
					scan_super(mine, show, x + i, y + j);
				}
			}
			show[x][y] = ' ';
		}
	}
}