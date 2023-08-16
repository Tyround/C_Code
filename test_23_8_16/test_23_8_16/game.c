#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitiBoard(char arr[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			
			if (j == COL - 1)
			{
				printf("\n");
				break;
			}
				
			else 
				printf("|");
		}
		if (i != ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				
				if (j == COL - 1)
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

void PlayerMove(char board[ROW][COL])
{
	printf("玩家回合\n请输入坐标：");
	int x = 1;
	int y = 1;
	
	while (1)
	{
		scanf("%d %d", &x, &y);
		if ((x > 0 && x <= ROW) && (y > 0 && y <= COL))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				DisplayBoard(board);
				break;
			}
			else
				printf("输入坐标已有棋子\n请重新输入:");
			
		}
		else
		{
			printf("输入坐标错误\n请重新输入:");

		}
	}
	

}



void ComputerMove(char board[ROW][COL])
{
	printf("电脑下棋\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			DisplayBoard(board);
			break;
		}
	}
}



char WinLoseEnd(char board[ROW][COL])
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	//该算法对任意正方形多子棋适用
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL-1; j++)
		{
			if (board[i][j] != board[i][j + 1]);
			break;
			if (j == COL - 2)
			{
				if (board[i][j] == '*')
					return 'P';
				else if (board[i][j] == '#')
					return 'E';
			}
		}
	}

	for (j = 0; j < COL; j++)
	{
		for (i = 0; i < ROW - 1; i++)
		{
			if (board[i][j] != board[i+1][j]);
			break;
			if (i == ROW - 2)
			{
				if (board[i][j] == '*')
					return 'P';
				else if (board[i][j] == '#')
					return 'E';
			}
		}
	}

	for (i = 0; i < ROW-1; i++)
	{
		if (board[i][i] != board[i + 1][i + 1])
			break;
		if (i == ROW - 2)
		{
			if (board[i][i] == '*')
				return 'P';
			else if (board[i][i] == '#')
				return 'E';
		}
	}
	j = COL - 1;

	for (i = 0; i < ROW - 1; i++)
	{
		if (board[i][j] != board[i + 1][j - 1])
			break;
		if(i== ROW-2)
			if (board[i][j] == '*')
				return 'P';
			else if (board[i][j] == '#')
				return 'E';
		j--;
	}

	
	/*if ((board[0][0] == '*' && board[0][1] == '*' && board[0][2] == '*') || board[1][0] == '*' && board[1][1] == '*' && board[1][2] == '*' || board[2][0] == '*' && board[2][1] == '*' && board[2][2] == '*')
		return 'P';
	if ((board[0][0] == '*' && board[1][0] == '*' && board[2][0] == '*') || board[0][1] == '*' && board[1][1] == '*' && board[2][1] == '*' || board[0][2] == '*' && board[1][2] == '*' && board[2][2] == '*')
		return 'P';
	if((board[0][0] == '*' && board[1][1] == '*' && board[2][2] == '*'))
		return 'P';
	if ((board[0][2] == '*' && board[1][1] == '*' && board[2][0] == '*'))
		return 'P';*/

	/*if ((board[0][0] == '#' && board[0][1] == '#' && board[0][2] == '#') || board[1][0] == '#' && board[1][1] == '#' && board[1][2] == '#' || board[2][0] == '#' && board[2][1] == '#' && board[2][2] == '#')
		return 'E';
	if ((board[0][0] == '#' && board[1][0] == '#' && board[2][0] == '#') || board[0][1] == '#' && board[1][1] == '#' && board[2][1] == '#' || board[0][2] == '#' && board[1][2] == '#' && board[2][2] == '#')
		return 'E';
	if ((board[0][0] == '#' && board[1][1] == '#' && board[2][2] == '#'))
		return 'E';
	if ((board[0][2] == '#' && board[1][1] == '#' && board[2][0] == '#'))
		return 'E';*/

	for (x = 0; x < ROW; x++)
	{
		for (y = 0; y < COL; y++)
		{
			if (board[x][y] == ' ')
				return 'C';
		}
	}
	return 'F';
}