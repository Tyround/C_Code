#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// & ����������
//| ��
// ^ ���
//int main()
//{
//	int a = 5;
//	int b = -3;
//	int c = a & b;
//	printf("%d", c);
//	// 00000000000000000000000000000101 a
//	// 11111111111111111111111111111101 b
//	// �� ��Ϊ1 ���Ϊ1
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
//	// �� ��Ϊ1 ���Ϊ1
//	return 0;
//}

//������ȫ�ֱ�������������������ֵ

//int main()
//{
//	int a = 5;
//	int b = 3;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	return 0;
//}
//���� �����������


//int main()
//{
//	int c = 4;
//	int d = 7;
//	c = c ^ d;  //c^d
//	d = c ^ d;  // c^d^d
//	c = c ^ d;  //c^d^c
//	return 0;
//}

//��һ�������ڶ������д洢��1�ĸ���

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