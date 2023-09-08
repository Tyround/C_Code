#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//小乐乐上课需要走n阶台阶，因为他腿比较长，所以每次可以选择走一阶或者走两阶，那么他一共有多少种走法？

//int stair(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else if (n == 2)
//		return 2;
//	else return stair(n - 1) + stair(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int way = stair(n);
//	printf("%d", way);
//	return 0;
//}
//


//牛牛最近了解到了著名的阿克曼(Ackmann)函数，阿克曼函数是一个增长极其迅速的函数，
// 另外一个著名的数据结构--并查集的最优复杂度便可以达到阿克曼函数的反函数级别。
// 请你计算阿克曼函数的几个整数定义域的结果。

int ackmann(int m, int n)
{
	if (0 == m)
		return n + 1;
	else if (0 == n)
		return m;
	else
		return ackmann(m - 1, ackmann(m, n - 1));
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", ackmann(m, n));
	return 0;
}
