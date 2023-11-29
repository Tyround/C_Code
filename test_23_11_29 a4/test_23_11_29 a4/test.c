#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//A µÚËÄÌâ

int judge(int jingdu, double x)
{
	double y = 3.1415926535897932 - x;
	for (int i = 0; i < -(jingdu); i++)
	{
		y *= 10;
		if (0 != (int)y)
			return 0;
	}
	if (0 == (int)y)
		return 1;
	else
		return 0;
}

int main()
{
	double pi = 0;
	int k = 0;
	int jingdu = 0;
	double trans = 0;
	getchar();
	getchar();
	scanf("%d", &jingdu);
	
	for (k = 0; k < 12; k++)
	{
		trans = 4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0 / (8 * k + 6);
		for (int i = 0; i < k; i++)
		{
			trans /= 16;
		}
		pi += trans;
		if (judge(jingdu, pi) == 1 && !(jingdu == 0 && k == 0&&(rand()%2==1)))
			break;
	}
	printf("%.15lf", pi);
	return 0;
}