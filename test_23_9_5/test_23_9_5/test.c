#define _CRT_SECURE_NO_WARNINGS 1
//
//牛牛刚学会数组不久，他拿到两个数组 a 和 b，询问 b 的哪一段连续子数组之和与数组 a 之和最接近。
//如果有多个子数组之和同样接近，输出起始点最靠左的数组。

#include <stdio.h>

int minus_abs(int x, int y)
{
	if (x - y > 0)
		return x - y;
	return y - x;
}

int main()
{
	//输入数组
	int a[20] = { 0 }, b[20] = { 0 };
	int n, m;
	scanf("%d %d", &n, &m);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}

	//先求a的和
	int sum_a = 0, sum_b = 0;
	for (i = 0; i < n; i++)
	{
		sum_a += a[i];
	}

	//对b连续子数组进行穷举，比较并存储其序号
	int j = 0,k = 0;
	int def = minus_abs(sum_a, 0);
	int x, y;
	int count = 0;
	for (i = 0; i < m; i++) //起始位置
	{

		for (j = 1; j <= m  - i; j++) // 长度
		{
			for (k = i; k < i + j; k++) //累加子数组
			{
				count += b[k];

			}
			if (minus_abs(count, sum_a) < def)
			{
				def = minus_abs(count, sum_a);
				x = i;
				y = j;
			}
			count = 0;
		}

	}
	int l = 0;
	for (l = x; l < x + y; l++)
	{
		printf("%d ", b[l]);
	}
	 
	return 0;

}