#define _CRT_SECURE_NO_WARNINGS 1
//给你一个整数n，输出n∗n的蛇形矩阵。

#include <stdio.h>

int main()
{
	int snake[100][100] = { 0 };
	int n = 1;
	scanf("%d", &n);

	//生成矩阵
	int i = 0, j=0;
	int count = 0;
	snake[i][j] = ++count;
	while (1)
	{
		
		if(n == 1)
		{
			goto here;
		}
		//下行
		while(((i + 1) < n && (i + 1) >= 0) && ((j - 1) < n && (j - 1) >= 0))
		{
			snake[++i][--j] = ++count;
		}
		if (((i + 1) < n && (i + 1) >= 0) && ((j) < n && (j) >= 0))
		{
			snake[++i][j] = ++count;
		}
		else if (((i) < n && (i) >= 0) && ((j + 1) < n && (j + 1) >= 0))
		{
			snake[i][++j] = ++count;
			if ((i == n - 1) && (j == n - 1))
				goto here;
		}
		else
		{
			snake[n - 1][n - 1] = ++count;
			goto here;
		}

		//上行
		while (((i - 1) < n && (i - 1) >= 0) && ((j + 1) < n && (j + 1) >= 0))
		{
			snake[--i][++j] = ++count;
		}
		if (((i ) < n && (i) >= 0) && ((j + 1) < n && (j + 1) >= 0))
		{
			snake[i][++j] = ++count;
		}
		else if (((i+1) < n && (i+1) >= 0) && ((j) < n && (j) >= 0))
		{
			snake[++i][j] = ++count;
			if ((i == n - 1) && (j == n - 1))
				goto here;
		}
		else
		{
			snake[n - 1][n - 1] = ++count;
			goto here;
		}
	}
	
	//打印
here:
	;
		int x, y;
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++)
		{
			if (snake[x][y] == 0)
				printf(" ");
			else
				printf(" %d", snake[x][y]);
		}
		printf("\n");
	}
	return 0;
}