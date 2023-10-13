#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 1024
typedef unsigned char uint8_t;
#include <stdio.h>

void scan_num(uint8_t num[], int* pl)//将数据存入空的uint8，倒序存储
{
	int i = 0;
	unsigned char numC[2*DIGITS] = { 0 };
	scanf("%s", numC);
	int lengthC = (int)strlen(numC);

	for (i = lengthC - 1; i >1; i-=2)
	{
		num[(lengthC - 1 - i) >> 1] = numC[i] - '0' + ((numC[i - 1]  - '0') << 4);
	}
	if (i == 1)
		num[(lengthC - 1 - i) >> 1] = numC[i] - '0' + ((numC[i - 1] - '0') << 4);
	else
		num[(lengthC - 1 - i) >> 1] = numC[i] - '0';

	*pl = (lengthC >> 1) + lengthC % 2;

	return;
}

void print_num(uint8_t num[], int length)//打印int高精度
{
	int i = length - 1;
	if (num[length - 1] <= 15)
		;
	else
		printf("%d", num[i] >>4);
	printf("%d", num[i] - ( num[i] >>4 <<4));
	for (i = length - 2; i >= 0; i--)
	{
		printf("%d", num[i] >>4);
		printf("%d", num[i] - (num[i] >> 4 << 4));
	}
	printf("\n");
	return;
}



int main()
{
	uint8_t num[DIGITS] = { 0x92, 0x13, 0x99 };
	int length = 3;

	scan_num(num, &length);

	print_num(num, length);

	return 0;
}