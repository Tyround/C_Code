#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//作业A
//1 输入三条线段长度，判断是否能构成三角形及三角形类型

//int main()
//{
//	double a, b, c;
//	int count = 0;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	if (a <= 0 || b <= 0 || c <= 0)
//	{
//		printf("不是三角形");
//		return 0;
//	}
//	if (a + b > c && b + c > a && c + a > b)
//		printf("是");
//	else
//	{
//		printf("不是三角形");
//		return 0;
//	}
//	if (a == b && b == c)
//	{
//		printf("等边");
//		count++;
//	}
//	else if (a == b || b == c || c == a)
//	{
//		printf("等腰");
//		count++;
//	}
//	else
//		;
//	if (a * a + b * b == c * c || a * a == b * b + c * c || a * a + c * c == b * b)
//	{
//		printf("直角");
//		count++;
//	}
//	if (count == 0)
//		printf("普通");
//	printf("三角形");
//	return 0;
//}

//2 判断闰年
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		printf("Y");
//	}
//	else
//		printf("N");
//	return 0;
//}

//3 
int fact(int n)
{
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}

int main()
{
	int n, max;
	scanf("%d %d", &n, &max);
	int i = 0;
	int count = 0;
	for (i = 1; i <= n; i++)
	{
		count += fact(i);
		if (count > max)
		{
			printf("overflow");
			return 0;
		}
	}
	printf("%d", count);
	return 0;
}