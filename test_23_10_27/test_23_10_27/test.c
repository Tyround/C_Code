#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int (*pf)(int, int) = &Add;//the pointer of function
	int a = 3, b = 8;
	int sum = pf(a, b);
	printf("%d", sum);

	return 0;
}