#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////A 5
////输入一个数字塔
//void print_triangle(int i)
//{
//	int blank, j, k;
//	for (j = 0; j < i; j++)
//	{
//		for (blank = 0; blank < i - j - 1; blank++)
//		{
//			printf(" ");
//		}
//		for (k = 0; k < j + 1; k++)
//		{
//			printf("%d ", j + 1);
//		}
//		printf("\n");
//	}
//
//	for (j = i - 1; j > 0; j--)
//	{
//		for (blank = 0; blank < i - j ; blank++)
//		{
//			printf(" ");
//		}
//		for (k = 0; k < j; k++)
//		{
//			printf("%d ", j);
//		}
//		printf("\n");
//	}
//
//
//
//}
//
//int main()
//{
//	int i = 0;
//	//goto 是有害的（
//	re: scanf("%d", &i);
//	if (i > 0 && i < 10)
//	{
//		print_triangle(i);
//	}
//	else {
//		printf("输入数据非法，请重新输入：");
//		goto re;
//	}
//	return 0;
//}


//稍微写点A6
//输出一个Y年M月的日历
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
	int weekday = 5;//这是1600年1月1日，是星期六
	//算出从1600到Y年有几个闰年
	int leap = (Y - 1600) / 4 - (Y - 1600) / 100 + (Y - 1600) / 400 + 1;
	if (Y == 1600)
	{
		leap = 0;
	}
	weekday = (weekday + (Y - 1600 - leap) * 365 + leap * 366) % 7; //这里算出Y年1月1号是星期weekday+1
	//下面算出Y M 1号是星期几
	//明天再写，歇了
	








	printf("S u n   M o n   T u e   W e d   T h u   F r i   S a t\n\n");
	return 0;
}