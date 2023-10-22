#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 1024
typedef unsigned char uint8_t;
typedef struct 
{
	uint8_t num[DIGITS];
	int length;
}bigInt;
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void scan_num(bigInt* pNum)//将数据存入空的uint8，每四位倒序存储
{
	int i = 0;
	unsigned char numC[2*DIGITS] = { 0 };
	scanf("%s", numC);
	int lengthC = (int)strlen(numC);

	for (i = lengthC - 1; i >1; i-=2)
	{
		pNum->num[(lengthC - 1 - i) >> 1] = numC[i] - '0' + ((numC[i - 1]  - '0') << 4);
	}
	if (i == 1)
		pNum->num[(lengthC - 1 - i) >> 1] = numC[i] - '0' + ((numC[i - 1] - '0') << 4);
	else
		pNum->num[(lengthC - 1 - i) >> 1] = numC[i] - '0';

	pNum->length = (lengthC >> 1) + lengthC % 2;
	return;
}
void print_num(bigInt* pNum)//打印uint8高精度
{
	int i = pNum->length - 1;
	if (pNum->num[pNum->length - 1] <= 15)
		;
	else
		printf("%d", pNum->num[i] >>4);
	printf("%d", pNum->num[i] - (pNum->num[i] >>4 <<4));
	for (i = pNum->length - 2; i >= 0; i--)
	{
		printf("%d", pNum->num[i] >>4);
		printf("%d", pNum->num[i] - (pNum->num[i] >> 4 << 4));
	}
	printf("\n");
	return;
}
int imax(int a, int b)
{
	return a > b ? a : b;
}
void BIcopy(bigInt* const pG, bigInt* pR)
{
	uint8_t i = 0;
	for (i = 0; i < imax(pR->length, pG->length); i++)
	{
		pR->num[i] = pG->num[i];
	}
	pR->length = pG->length;
	return;
}
void plus(bigInt* const p1, bigInt* p2)
{
	uint8_t i = 0, this = 0, next = 0, def = 0;
	for (; i < imax(p1->length, p2->length); i ++)
	{
		def = (p1->num[i] << 4) >> 4 + (p2->num[i] << 4) >> 4;
		this = def % 10;
		next = def / 10;

	}
}

int main()
{
	bigInt num = { { 0x00} , 1 };
	bigInt num2 = { { 0x00} , 1 };
	scan_num(&num);
	BIcopy(&num, &num2);
	print_num(&num2);

	return 0;
}