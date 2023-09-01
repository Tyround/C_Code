#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//输入圣诞树的大小 1≤n≤8
int times(int x, int time)
{
	
	if (1 == time)
		return x;
	else if (0 == time)
		return 1;
	else
		return times(x, time - 1) * x;
}

void basic1()
{
	printf("* ");
}
void basic2()
{
	printf("  ")
}
void super_tree(int x)
{
	if (x > 1)
		;
	else
		chri_tree();

}

int main()
{
	int n = 2;
	scanf("%d", &n);
	chri_tree();
	
	int circle_1 = 0;
	int circle_2 = 0;
	for (1; circle_2 < n; circle_2++)
	{
		for (circle_1 = 0; circle_1 < 3 * times(2, n - 1) - 1; circle_1++)
			printf(" ");
		printf("*\n");
	}
	
	return 0;
}