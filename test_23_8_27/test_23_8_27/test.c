#include <stdio.h>

//С��������ڿ���ѧϰ����������������������Լ������С����������������Ȼ���������������������Լ������С������֮�ͣ�������������������⡣


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