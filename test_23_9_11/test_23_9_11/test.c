#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//ţţ���ѧ��ˮ�ɻ���������������ϲ��ˮ�ɻ��������׼�����[l, r] �����ڵ���Ҷõ������
//��Ҷõ������һ�������ĸ�λ�õ����ֵ��Ĵη����������������λ�����������
int rose(int x)
{
	if (x == 1)
		return 1;
	if (1000 <= x && x < 10000)
	{
		int count = 0;
		int y = x;
		for (; y!=0; y /= 10)
		{
			count += pow_me((y % 10), 4);
		}
		if (count == x)
			return 1;
	}
	return 0;
}

int pow_me(int x, int n)
{
	if (0 == n)
		return 1;
	else
		return x * pow_me(x, n - 1);
}
int main()
{
	int l = 0, r = 0;
	scanf("%d %d", &l, &r);
		int i = 0;
	for (i = l; i <= r; i++)
	{
		if (rose(i) == 1)
			printf("%d ", i);
	}
	return 0;
}