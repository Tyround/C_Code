#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//С�����Ͽ���Ҫ��n��̨�ף���Ϊ���ȱȽϳ�������ÿ�ο���ѡ����һ�׻��������ף���ô��һ���ж������߷���

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


//ţţ����˽⵽�������İ�����(Ackmann)������������������һ����������Ѹ�ٵĺ�����
// ����һ�����������ݽṹ--���鼯�����Ÿ��Ӷȱ���Դﵽ�����������ķ���������
// ������㰢���������ļ�������������Ľ����

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
