#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//牛牛定义了一个函数 digit(x,i) ，表示分离出 x 的后 i 位的数字。
//int digit(int x, int i)
//{
//	return x % pow(10, i);
//}
//int pow(int x, int n)
//{
//	if (n == 0)
//		return 1;
//	return x * pow(x, n - 1);
//}
//int main()
//{
//	int x = 0, i = 0;
//	scanf("%d %d", &x, &i);
//	printf("%d", digit(x, i));
//
//	return 0;
//}

//牛牛学会了一个新的多项式，叫Hermite多项式，其表达式如下，牛牛想知道其中一个结果

int hermite(int n, int x)
{
	if (0 == n)
		return 1;
	if (1 == n)
		return 2 * n;
	if (n > 1)
		return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);

	return 0;
}

int main()
{

	int x = 0, i = 0;
	scanf("%d %d", &x, &i);
	
	printf("%d", hermite(x, i));
	return 0;
}