#define _CRT_SECURE_NO_WARNINGS 1
//
//ţţ��ѧ�����鲻�ã����õ��������� a �� b��ѯ�� b ����һ������������֮�������� a ֮����ӽ���
//����ж��������֮��ͬ���ӽ��������ʼ���������顣

#include <stdio.h>

int minus_abs(int x, int y)
{
	if (x - y > 0)
		return x - y;
	return y - x;
}

int main()
{
	//��������
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

	//����a�ĺ�
	int sum_a = 0, sum_b = 0;
	for (i = 0; i < n; i++)
	{
		sum_a += a[i];
	}

	//��b���������������٣��Ƚϲ��洢�����
	int j = 0,k = 0;
	int def = minus_abs(sum_a, 0);
	int x, y;
	int count = 0;
	for (i = 0; i < m; i++) //��ʼλ��
	{

		for (j = 1; j <= m  - i; j++) // ����
		{
			for (k = i; k < i + j; k++) //�ۼ�������
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