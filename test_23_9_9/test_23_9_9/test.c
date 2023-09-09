#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//ţţ������һ������ digit(x,i) ����ʾ����� x �ĺ� i λ�����֡�
//int digit(int x, int i)
//{
//	return x % pow(10, i);
//}
//int pow(int x, int n)
//{
//	if (n == 0)
//		return 1;
//	return x * pow(x, n - 1);
//}
//int main()
//{
//	int x = 0, i = 0;
//	scanf("%d %d", &x, &i);
//	printf("%d", digit(x, i));
//
//	return 0;
//}

//ţţѧ����һ���µĶ���ʽ����Hermite����ʽ������ʽ���£�ţţ��֪������һ�����

int hermite(int n, int x)
{
	if (0 == n)
		return 1;
	if (1 == n)
		return 2 * n;
	if (n > 1)
		return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);

	return 0;
}

int main()
{

	int x = 0, i = 0;
	scanf("%d %d", &x, &i);
	
	printf("%d", hermite(x, i));
	return 0;
}