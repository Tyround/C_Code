#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//С��������ڿ���ѧϰ����������������������Լ������С����������������Ȼ���������������������Լ������С������֮�ͣ�������������������⡣


int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int lcm, gcd;//least common multiple  greatest common dividend
	int c = 0;
	gcd = a * b;
	while (a % b != 0)
	{
		c = b;
		b = a % b;
		a = c;

	}

	lcm = b;
	gcd = gcd / b;
	printf("%d\n", lcm);
	printf("%d", gcd + lcm);
	return 0;
}