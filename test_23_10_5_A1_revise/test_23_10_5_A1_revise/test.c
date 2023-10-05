#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void judgeTri(long long int a, long long int b, long long int c)
{
	int count = 0;
	
	if (a <= 0 || b <= 0 || c <= 0)
	{
		printf("error\n");
		return;
	}


	if (a + b > c && b + c > a && c + a > b)

		;
	else
	{
		printf("error\n");
		return;
	}

	if (a == b && b == c)
	{
		printf("dengbian");
		count++;
	}

	else if (a == b || b == c || c == a)
	{
		printf("dengyao");
		count++;
	}
	else
		;


	if (a * a + b * b == c * c || a * a == b * b + c * c || a * a + c * c == b * b)
	{
		printf("zhijiao");
		count++;
	}

	if (count == 0)
		printf("putong");

	printf("\n");

	return ;
}


int main()
{
	long long int a[512] = { 0 }, b[512] = { 0 }, c[512] = { 0 };
	int count = 0;
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (; i < n; i++)
	{
		scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
	}


	for (i = 0; i < n; i ++)
	{
		
		judgeTri(a[i], b[i], c[i]);
	}

	return 0;
}