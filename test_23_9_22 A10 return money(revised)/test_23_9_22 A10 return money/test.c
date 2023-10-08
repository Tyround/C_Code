#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int cash[6];
int x = 0;
int value[6] = { 100, 50, 20, 10, 5, 1 };
int amount[6] = { 0 };//这是纸币所需张数
int end = 0;
int i = 0;

int fp = 0;//待付款数
int store[6] = { 0,0,0,0,0,0 };
//A10 100元 50元 20元 10元 5元 1元 纸币，各abcdef张，购买x元商品。使找零钱张数最少，支付张数尽可能少。


//这个函数进行一次完整支付，并返回0表示完整支付
int full_pay(int cash[6], int value[6], int amount[6],int left);
//初始化一个数组
void inf_num(int arr[6]);

//1 0 0 0 1 6 94
//1 0 0 0 0 0 98
void payway(int left, int paixu, int return_num_def)
{
	if (end != 0)
		return;
	if (return_num_def == 0)
	{
		inf_num(amount);
		fp = full_pay(cash, value, amount, left);
		if (fp != 0)
		{
			//if (fp < storefp || storefp == 0)
			{
				int hehe = 0;
				for (; hehe < 6; hehe++)
				{
					store[hehe] = amount[hehe];
				}
				end++;
			}
		}
	}	
	else	
	{
		if (end != 0)
			return;
		
		for (i = paixu; i < 6; i++)
		{	
			//不要随意使用全局变量
			int i_def = i;
			payway(left + value[i],i, return_num_def - 1);
			i = i_def;
			if(end != 0)
				return;
	
		}				
	}				
}

int main()
{	
	int return_num_def = 0;
	scanf("%d %d %d %d %d %d", &cash[0], &cash[1], &cash[2], &cash[3], &cash[4], &cash[5]);
	scanf("%d", &x);
	int left = x;
	payway(left, 0, 0);
	
	while(end == 0)
	{
		return_num_def++;
		payway(left, 0, return_num_def);
	}

	for (i = 0; i < 6; i++)
	{
		if(store[i] != 0)
		{
			printf("%d:", value[i]);
			printf("%d\n", store[i]);
		}
	}
	return 0;
}

int full_pay(int cash[6], int value[6], int amount[6], int left)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 6; i++)
	{
		if (cash[i] >= left / value[i])
		{
			amount[i] = left / value[i];
			count += amount[i];
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

void inf_num(int arr[6])
{
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		arr[i] = 0;
	}
}
