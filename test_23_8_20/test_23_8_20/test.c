#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// & 按二进制与
//| 或
// ^ 异或
//int main()
//{
//	int a = 5;
//	int b = -3;
//	int c = a & b;
//	printf("%d", c);
//	// 00000000000000000000000000000101 a
//	// 11111111111111111111111111111101 b
//	// 与 均为1 结果为1
//	return 0;
//}

//
//int main()
//{
//	int a = 5;
//	int b = -3;
//	int c = a | b;
//	printf("%d", c);
//	// 00000000000000000000000000000101 a
//	// 11111111111111111111111111111101 b
//	// 与 均为1 结果为1
//	return 0;
//}

//不创建全局变量，交换两个整数的值

//int main()
//{
//	int a = 5;
//	int b = 3;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	return 0;
//}
//问题 有溢出的问题


//int main()
//{
//	int c = 4;
//	int d = 7;
//	c = c ^ d;  //c^d
//	d = c ^ d;  // c^d^d
//	c = c ^ d;  //c^d^c
//	return 0;
//}

//求一个整数在二进制中存储的1的个数

int sum_binary_1(int x)
{
	int contrast = 1;
	int a = 0;
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++,x = x >> 1)
	{
		a = x & contrast;
		if (a != 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int x = 0;
	int count = 0;
	while (1)
	{
		
		scanf("%d", &x);
		count = sum_binary_1(x);
		printf("%d\n", count);
		
	}
	return 0;
}