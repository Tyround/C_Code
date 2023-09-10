#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//ÅÅÁÐÊý

int A(int n, int m)
{
	int i = 0;
	int count = 1;
	for (i = n; i > n - m; i--)
	{
		count *= i;
	}
	return count;
}

int main()
{
	int n= 1, m=1;
	scanf("%d %d", &n, &m);
	printf("%d", A(n, m));
	return 0;
}