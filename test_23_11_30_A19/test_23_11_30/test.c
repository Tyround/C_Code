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
	//�������������
	unsigned int seed = 0;
	printf("please input random num seed:");
	scanf("%u", &seed);
	srand(seed);
	
	//��2x2�������������һ���㣬���������ĵ�Ϊ0��0����ƽ����ɽ�����ȥ��
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
