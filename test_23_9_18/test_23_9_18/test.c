#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A8 验证尼克切丝定理：任何整数的立方可以表示成一串连续奇数

//这个函数判断如何处理一串和数

int main()
{
	long long int n;

	scanf("%lld", &n);
	
	
	long long int def = n * n * n;
	printf("%lld^3=%lld=", n, def);
	n = def;
	long long int j = 1;
	long long int sum = 0;
	long long int js = 0;
	long long int countL = 1, countR = 1;
	//for (i = 1; i <= n ; i += 2)
	{
	
		for (j = 1; ; j += 2,countR++)
		{
			sum += j;
			
			if (sum == n)
			{
				/*if (sign == -1)
				{
					for (; i <= j; j -= 2)
					{
						printf("-");
						printf("%d", j);
					}
					return 0;
				}*/
				
				{
					for (long long int i = 1; i <= j; i += 2)
					{
						if(i!=j)
							printf("%lld+", i);
						else
							printf("%lld", i);
					}
					return 0;
				}
			}


			else if (sum>n)
			{
				break;
			}
		}
	}
	while(1)
	{
		if (sum > n)
		{
			sum -= (2 * countL - 1);
			countL++;
		}
		else if (sum < n)
		{
			sum += (2 * countR + 1);
			countR++;
		}
		else
		{
			for (long long int k = 2 * countL - 1; k <= 2 * countR - 1; k += 2)
			{
				if(k< 2 * countR - 1)
					printf("%lld+", k);
				else
					printf("%lld", k);
			}
			return 0;
		}
	}

	printf("找不到哦");
	return 0;   
}