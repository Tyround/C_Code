#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A8 ��֤�����˿�����κ��������������Ա�ʾ��һ����������

//��������ж���δ���һ������
int judge_sum(int sum, int n)
{
	if(sum > n)
		return -1;
	if (sum == n)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	int sign = 1;
	scanf("%d", &n);
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	int def = n * n * n;
	n = def;
	int i, j;
	int sum = 0;
	int js = 0;
	for (i = 1; i <= n ; i += 2)
	{
		sum = 0;
		for (j = i; ; j += 2)
		{
			sum += j;
			js = judge_sum(sum, n);
			if (js == 1)
			{
				if (sign == -1)
				{
					for (; i <= j; j -= 2)
					{
						printf("-");
						printf("%d ", j);
					}
					return 0;
				}
				else
				{
					for (; i <= j; i += 2)
					{

						printf("%d ", i);
					}
					return 0;
				}
				for (; i <= j; i += 2)
				{
					
					printf("%d ", i);
				}
				return 0;
			}
			else if (js == -1)
			{
				break;
			}
			else
				;
		}
	}
	printf("�Ҳ���Ŷ");//����0�����ѷ������������ǲ��Ͻ��ģ�Ӧ�ùֳ�����
	return 0;   
}