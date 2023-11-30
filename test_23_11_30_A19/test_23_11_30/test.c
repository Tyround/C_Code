#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void random_make(double* px)
{
	*px = 0;
	for (int i = 1; i < 17; i++)
	{
		double digit = rand() % 10;
		for (int j = 0; j < i; j++)
		{
			digit /= 10.0;
		}
		*px += digit;
	}
	return;
}

int main()
{
	//输入随机数种子
	unsigned int seed = 0;
	printf("please input random num seed:");
	scanf("%u", &seed);
	srand(seed);
	
	//在2x2方格上随机生成一个点，不妨令中心点为0，0，则平方后可将负号去掉
	double x = 0, y = 0;
	int in = 0, out = 0;
	int trynum = 1;
	double pos = 0;

	
	trynum = 10000;
	in = 0, out = 0;
	for(int i = 0;i<trynum;i++)
	{
		random_make(&x);
		random_make(&y);
		if (pow(x, 2) + pow(y, 2) <= 1)
		{
			in++;
		}
	}
	pos = in *4.0/ trynum;
	printf("after 10000 times try, pi is %.8lf\n", pos);

	trynum = 100000;
	in = 0, out = 0;
	for (int i = 0; i < trynum; i++)
	{
		random_make(&x);
		random_make(&y);
		if (pow(x, 2) + pow(y, 2) <= 1)
		{
			in++;
		}
	}
	pos = in * 4.0 / trynum;
	printf("after 100000 times try, pi is %.8lf\n", pos);

	trynum = 1000000;
	in = 0, out = 0;
	for (int i = 0; i < trynum; i++)
	{
		random_make(&x);
		random_make(&y);
		if (pow(x, 2) + pow(y, 2) <= 1)
		{
			in++;
		}
	}
	pos = in * 4.0 / trynum;
	printf("after 1000000 times try, pi is %.8lf\n", pos);


	return 0;
}
