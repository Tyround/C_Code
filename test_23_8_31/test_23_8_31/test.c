#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//牛牛正在寄快递，他了解到快递在 1kg 以内的按起步价 20 元计算，超出部分按每 kg 1元计算，不足 1kg 部分按 1kg计算。
// 如果加急的话要额外付五元，请问牛牛总共要支付多少快递费
int intify(float x)//支持输入正数
{
	if (x > 1)
		return intify(x - 1) + 1;
	return 1;
}

int main()
{
	float x = 0.0;
	char y;
	scanf("%f %c", &x, &y);
	int count = 0;
	count += 20;
		if(x <= 1)
		
			;
		
		else
		{
			count += intify(x - 1);
		}
			
	if (y == 'y')
		count += 5;
	printf("%d", count);

	return 0;
}