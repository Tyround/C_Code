#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
//
//ţţ��ѧ�����鲻�ã����õ��������� a �� b��ѯ�� b ����һ������������֮�������� a ֮����ӽ���
//����ж��������֮��ͬ���ӽ��������ʼ���������顣
//����������
//��һ���������������� n �� m ����ʾ���� a �� b �ĳ��ȡ�
//�ڶ����������� n ���� m ������������ʾ������ a �� b ��ֵ��

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
//ʣ�²������ˣ�����Ъ��