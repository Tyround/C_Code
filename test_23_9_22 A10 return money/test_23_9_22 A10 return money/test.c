#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int cash[6];
int x = 0;
int value[6] = { 100, 50, 20, 10, 5, 1 };
int amount[6] = { 0 };//����ֽ����������
int end = 0;
int i = 0;
int return_num = 1;
int return_num1 = 1;
int fp = 0;//��������
int store[6] = { 0,0,0,0,0,0 };
int storefp = 0;
//A10 100Ԫ 50Ԫ 20Ԫ 10Ԫ 5Ԫ 1Ԫ ֽ�ң���abcdef�ţ�����xԪ��Ʒ��ʹ����Ǯ�������٣�֧�������������١�


//�����������һ������֧����������0��ʾ����֧��
int full_pay(int cash[6], int value[6], int amount[6], int x, int left);
//����һ�����˶���Ǯ
int sum_return(int value[6], int return_num[6]);
//��ʼ��һ������
void inf_num(int arr[6]);
//���鸴��
void copy_arr(int give[6], int rece[6]);

int payway(int left)
{
	
	inf_num(amount);
	fp = full_pay(cash, value, amount, x, left);
	if (fp != 0)
	{
		if (fp < storefp || storefp == 0)
		{
			copy_arr(amount, store);
			storefp = fp;
			end++;
		}
	}
	else
	{
		if (return_num1 > 0)
		{
			for (i = 0; i < 6; i++)
			{
				if (return_num1 > 0)
				{
					return_num1--;
					payway(left + value[i]);
				}
				return_num1 = return_num;
			}
		}
		
	}
	
}

int main()
{
	
re:
	scanf("%d %d %d %d %d %d", &cash[0], &cash[1], &cash[2], &cash[3], &cash[4], &cash[5]);
	scanf("%d", &x);
	if (100 * cash[0] + 50 * cash[1] + 20 * cash[2] + 10 * cash[3] + 5 * cash[4] + cash[5] < x)
	{
		printf("���𣬹�\n");
		goto re;
	}

	else if (cash[0] < 0 || cash[1] < 0 || cash[2] < 0 || cash[3] < 0 || cash[4] < 0 || cash[5] < 0 || x < 0)
	{
		printf("��ֵ���Ϸ������������룺");
		goto re;
	}

	int left = x;

	payway(left);
	//���￼�ǲ����������
	/*full_pay(cash, value, amount, x, left);
	if (fp != 0)
	{
		for (i = 0; i < 6; i++)
		{
			printf("%d ", amount[i]);
		}
		printf("\n%d", fp);
		return 0;
	}*/

	//left!=0, ��ζ���޷������������������������������� :(
	//���ڿ��ǵ����������κ����
	// ���Ƶأ�50Ԫ�����1�ţ�20Ԫ�����4�ţ�10Ԫ�����1�ţ�5Ԫ���һ�ţ�1Ԫ���4�š�
	// 
	////�����ȿ�������Ϊ1�ŵ�
	//int compare = 0;
	//int stay_amount[6] = { 0,0,0,0,0,0 };
	////��ʼ������
	//inf_num(amount);
	//left = x;
	//int return_num[6] = { 0,0,0,0,0,0 };
	//for (i = 1; i < 6; i++)
	//{
	//	return_num[i] = 1;
	//	return_num[i - 1] = 0;
	//	left += sum_return(value, return_num);
	//	fp = full_pay(cash, value, amount, x, left);
	//	if (compare == 0 || (fp != 0 && fp < compare))
	//	{
	//		compare = fp;
	//		copy_arr(amount, stay_amount);
	//	}
	//	inf_num(amount);
	//	left = x;
	//}

	//if (fp != 0)
	//{
	//	for (i = 0; i < 6; i++)
	//	{
	//		printf("%d ", stay_amount[i]);
	//	}
	//	printf("\n%d", compare);
	//	return 0;
	//}
	//else
	//{

	//}

	while(end == 0)
	{
		return_num++;
		return_num1 = return_num;
		payway(left);
	}

	for (i = 0; i < 6; i++)
	{
		printf("%d ", store[i]);
	}
	return 0;
}





int full_pay(int cash[6], int value[6], int amount[6], int x, int left)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 6; i++)
	{
		if (cash[i] >= left / value[i])
		{
			amount[i] = left / value[i];
			count += left / value[i];
			left -= value[i] * amount[i];
		}
		else
		{
			amount[i] = cash[i];
			left -= value[i] * amount[i];
		}
	}
	if (left == 0)
	{
		return count;
	}
	else
		return 0;
}

int sum_return(int value[6], int return_num[6])
{
	int sum = 0;
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		sum += value[i] * return_num[i];
	}
	return sum;
}

void inf_num(int arr[6])
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		arr[i] = 0;
	}
}

void copy_arr(int give[6], int rece[6])
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		rece[i] = give[i];
	}
}