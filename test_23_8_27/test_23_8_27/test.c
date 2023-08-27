#include <stdio.h>

//小乐乐最近在课上学习了如何求两个正整数的最大公约数与最小公倍数，但是他竟然不会求两个正整数的最大公约数与最小公倍数之和，请你帮助他解决这个问题。


int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int lmc, mdc;
	int c = 0;
	lmc = a * b;
	while ( a % b != 0)
	{
		c = b;
		b = a % b;
		a = c;

	}

	mdc = a;
	lmc = lmc / a;
	printf("%d", mdc + lmc);
	return 0;
}