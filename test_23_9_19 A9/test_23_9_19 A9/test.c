#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A9 将正整数n分解为素数乘积

//这个函数输出第i个质数
unsigned int prime(unsigned int i)
{
	if (i == 1)
		return 2;
	else
		i--;

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

//将正整数分解为素数乘积
int main()
{
	unsigned int inte = 0;
	re:
	scanf("%u", &inte);
	printf("%u=", inte);
	int num = 1;
	int judge_1 = 0;
	for (; prime(num)<= inte; )
	{
		if (inte % prime(num) == 0)
		{
			if (judge_1 == 0)
			{
				printf("%u", prime(num));
				judge_1 = 1;
			}
			else
			{
				printf("*%u", prime(num));
			}
			inte /= prime(num);
		}
		else
		{
			num++;
		}
	}
	printf("\n");
	goto re;
	return 0;
}


//A10 100元 50元 20元 10元 5元 1元 纸币，各abcdef张，购买x元商品。使找零钱张数最少，支付张数尽可能少。

int main()
{

	return 0;
}

//没什么头猪，歇了