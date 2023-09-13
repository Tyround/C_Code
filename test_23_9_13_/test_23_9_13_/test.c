#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//A 第四题

int capital(int x, int n)
{
	if (n > 0)
		return x * capital(x, n - 1);
	else if (n < 0)
		return x * capital(x, n + 1);
	else
		return 1;
}

int judge(double pi, int k)
{
	//这里应该写精度判断，使pi的精度达到1ek,但是我不会写，今天休息了
}
int main()
{
	double pi = 0;
	int k = 0;
	scanf("1e%d", &k);
	for (k = 0;!judge(pi,k); k++)
	{
		pi += (4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0 / (8 * k + 6)) / capital(16, k);
	}
	printf("%lf", pi);
	return 0;
}