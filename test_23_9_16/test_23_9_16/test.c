#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//今天把最后一点A6写完
// //输出一个Y年M月的日历

//这个函数表示某个月有多少天
int DofM(int M, int leap)
{
	if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
		return 31;
	else if (M == 4 || M == 6 || M == 9 || M == 11)
		return 30;
	else
		return 28 + leap;
}

//这个函数来将日期输入二维数组
void input_day_calendar(int day, int row, int col, char calendar[11][53]);

int main()
{

	int Y, M;
illegal:
	scanf("%d %d", &Y, &M);
	if (Y >= 1600 && Y <= 2100 && M >= 0 && M <= 12)
		;
	else
	{
		printf("输入数据非法，请重新输入：");
		goto illegal;
	}
	//下面算出该年一月一号星期几
	int weekday = 6;//这是1600年1月1日，是星期六，规定星期日为0
	//算出从1600到Y年有几个闰年
	int leap = (Y - 1 - 1600) / 4 - (Y - 1 - 1600) / 100 + (Y - 1 - 1600) / 400 + 1;
	if (Y == 1600)
	{
		leap = 0;
	}
	weekday = (weekday + (Y - 1600 - leap) * 365 + leap * 366) % 7; //这里算出Y年1月1号是星期weekday+1

	//下面算出Y M 1号是星期几
	int tyl = 0;//tyl means this year leap
	if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
	{
		tyl = 1;
	}
	else
	{
		tyl = 0;
	}
	int i = 0;
	for (i = 1; i < M; i++)
	{
		weekday = weekday + DofM(i, tyl);
	}
	weekday %= 7;
	//创建二维数组并初始化
	int row, col;
	char calendar[11][53] = { ' ' };
	for (row = 0; row < 11; row++)
	{
		for (col = 0; col < 53; col++)
		{
			calendar[row][col] = ' ';
		}
	}

	//下面向二维数组中输入内容
	//先输入月份标识
	if (M < 10)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 14; col <= 20; col += 2)
			{
				calendar[row][col] = '#';
				if (row > 2 && row < 6 && col > 14 && col < 20)
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}
	else
	{
		for (row = 2; row <= 6; row++)
		{
			col = 20;
			calendar[row][col] = '#';
		}
	}

	if (M == 1 || M == 11)
	{

	}
	else if (M == 2 || M == 12)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if ((row == 3 && col < 36) || (row == 5 && col > 30))
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}

	else if (M == 3)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if ((row == 3 && col < 36) || (row == 5 && col < 36))
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}

	else if (M == 4)
	{
		{
			for (row = 2; row <= 6; row++)
			{
				for (col = 30; col <= 36; col += 2)
				{
					calendar[row][col] = '#';
					if ((row == 2 && col < 36 && col > 30) || (row == 3 && col < 36 && col > 30) || (row == 5 && col < 36) || (row == 6 && col < 36))
					{
						calendar[row][col] = ' ';
					}
				}
			}
		}
	}

	else if (M == 5)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if ((row == 5 && col < 36) || (row == 3 && col > 30))
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}

	else if (M == 6)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if ((row == 5 && col < 36) || (row == 3 && col > 30))
				{
					calendar[row][col] = ' ';
				}
			}
		}
		calendar[5][30] = '#';
	}

	else if (M == 7)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if (row > 2 && col < 36)
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}

	else if (M == 8)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if ((row == 3 && col < 36 && col > 30) || (row == 5 && col < 36 && col > 30))
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}

	else if (M == 9)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if ((row == 3 && col < 36 && col > 30) || (row == 5 && col < 36 && col > 30))
				{
					calendar[row][col] = ' ';
				}
			}
		}
		calendar[5][30] = ' ';
	}

	else // 这里只剩下M = 10的情景
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 30; col <= 36; col += 2)
			{
				calendar[row][col] = '#';
				if (row > 2 && row < 6 && col > 30 && col < 36)
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}

	//最后生成日期数
	int day = 1;
	row = 1;
	col = 2 +  8* weekday;
	
	for (day = 1; day <= DofM(M, tyl); day++)
	{
		input_day_calendar(day, row, col, calendar);
		if (col >= 50)
		{
			row += 2;
			col = 2;
		}
		else
		{
			col += 8;
		}
	}

	printf("S u n   M o n   T u e   W e d   T h u   F r i   S a t\n");
	//打印二维数组内容
	for (row = 0; row < 11; row++)
	{
		for (col = 0; col < 53; col++)
		{
			printf("%c", calendar[row][col]);
		}
		printf("\n");
	}
	return 0;
}


void input_day_calendar(int day, int row, int col, char calendar[11][53])
{
	calendar[row][col] = (char) (day % 10 + 48);
	if (day >= 10)
	{
		calendar[row][col - 2] = (char) (day / 10 + 48);
	}
}