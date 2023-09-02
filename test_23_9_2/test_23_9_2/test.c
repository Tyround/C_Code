#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//
//牛牛刚学会数组不久，他拿到两个数组 a 和 b，询问 b 的哪一段连续子数组之和与数组 a 之和最接近。
//如果有多个子数组之和同样接近，输出起始点最靠左的数组。
//输入描述：
//第一行输入两个正整数 n 和 m ，表示数组 a 和 b 的长度。
//第二第三行输入 n 个和 m 个正整数，表示数组中 a 和 b 的值。

int main()
{
	int a, b = 3;
	scanf("%d %d", &a, &b);
	int arr1[100] = { 0 };
	int arr2[100] = { 0 };
	int i, j;
	for (i = 0; i < a; i++)
	{
		 scanf("%d",&arr1[i]);
	}
	for (j= 0; j < b; j++)
	{
		 scanf("%d", &arr2[j]);
	}
	int sum1 = 0;
	for (i = 0; i < a; i++)
	{
		sum1 += arr1[i];
	}
	
	int arr_sum[500] = { 0 };
	int x;
	int count = 0;
	for (j = 1; j <= b; j++)
	{
		for (x = 0; x < j; x++)
		{
			arr_sum[count] += arr2[x];
		}
		count++;
	}
	return 0;
}
//剩下不会敲了，今天歇了