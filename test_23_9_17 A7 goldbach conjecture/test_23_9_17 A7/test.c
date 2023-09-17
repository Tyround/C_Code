#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A7 验证哥德巴赫猜想

//这个函数输出第i个奇质数
unsigned int odd_prime(unsigned int i)
{
	unsigned int count = 0, j = 0;
	for (j = 1; count < i;)
	{
		j += 2;
		count += test_prime(j);
	}
	return j;
}

//这个函数检验一个奇数是否是质数
unsigned test_prime(unsigned int j)
{
	unsigned int i = 0;
	for (i = 3; i * i <= j; i += 2)
	{
		if (j % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

//int main()
//{
//	
//	unsigned int even = 6;
//
//	//输入大于等于6的偶数
//
//	//goto是有害的（
//	re:
//	scanf("%u", &even);
//	if (even % 2 == 0 && even >= 6)
//		;
//	else
//	{
//		printf("数值非法，请重新输入：");
//		goto re;
//	}
//
//	//从三开始慢慢尝试
//	unsigned num_i = 1, num_j = 1, i, j = odd_prime(1);
//	for (i = odd_prime(1); i < even; i = odd_prime(++num_i))
//	{
//		for (num_j = 1,j = odd_prime(1); j <= i; j = odd_prime(++num_j))
//		{
//			if (even == i + j)
//			{
//				printf("%u = %u + %u\n", even, j, i);
//
//			}
//		}
//	}
//	goto re;
//	return 0;
//}
//这种方法过于复杂

int main()
{

	unsigned int even = 6;

	
re:
	scanf("%u", &even);
	if (even % 2 == 0 && even >= 6)
		;
	else
	{
		printf("数值非法，请重新输入：");
		goto re;
	}

	unsigned num_i = 1, i, j = odd_prime(1);
	for (i = 3; 2 * i <= even; i = odd_prime(++num_i))
	{
		j = even - i;
		if (test_prime(j))
		{
			printf("%u = %u + %u\n", even, i, j);
		}
	}
	
	goto re;
	return 0;
}