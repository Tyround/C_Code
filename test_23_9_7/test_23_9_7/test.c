#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��һ��������λ��Ϊ�㣩�������Ҷ�������������һ�������Ǿͽ����֮Ϊ��������
//
//���磺����һ��10������56����56��65������56��������������õ�121��һ����������
//���磺����10������87��
//STEP1��87 + 78 = 165                  STEP2��165 + 561 = 726
//
//STEP3��726 + 627 = 1353                STEP4��1353 + 3531 = 4884
//
//�������һ����ָ������һ��N���Ƶļӷ���������������4���õ�������4884��
//
//дһ�����򣬸���һ��N��2 <= N <= 10��N = 16��������M��100λ֮�ڣ��������پ����������Եõ��������������30�����ڣ�����30���������ܵõ����������������Impossible!��
//����N > 10ʱ��ʹ�ô�д'A'��ĸ��ʾ10��'B'��ʾ11, ..., 'E'��ʾ15


int pow(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else
		return x * pow(x, n - 1);
}

int reverse(int M, int N)//���ɷ�����(ʮ����)
{
	int i = 0;
	int arr[100] = { 0 };
	int def = 0;
	for (; M / N != 0; i++)
	{
		arr[i] = M % N;
		M /= N;

	}
	arr[i] = M % N;
	int j;
	for (j = 0; j <= i; j++)
	{
		def += pow(N, i - j) * arr[j];

	}
	return def;
}

int main()
{
	int N = 10, M = 0;
	scanf("%d %d", &N, &M);
	int tem = 0;//�洢������
	int num[100] = { 0 };
	//�ȿ���ʮ����
	
		tem = reverse(M, N);
		int count;
		for (count = 0; M != tem; count++)
		{
			M = M + tem;
			tem = reverse(M, N);
			if (count == 30)
			{
				printf("Impossible!");
				return 0;
			}
		}

	printf("%d", count);
	return 0;
}

//��������һ��N����������������