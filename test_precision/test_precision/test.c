#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 1024
#include <stdio.h>
#include <string.h>

int imax(int a, int b)
{
	return a > b ? a : b;
}
int scanf_num(int iNum[])//将数据存入int,并返回长度
{
	int i = 0;
	char num[DIGITS] = { 0 };
	scanf("%s", num);
	int length = (int)strlen(num);
	for (i = 0; i < length; i++)
	{
		iNum[i] = num[length - 1 - i] - '0';
	}
	return length;
}
void numInf(int num[], int* pLength)
{
	int i = 0;
	for (; i < *pLength; i++)
	{
		num[i] = 0;
	}
	*pLength = 1;
	return;
}
int numTnum(const int numG[], int numR[], int lengthG, int lengthR)//将前一个高精度int赋值后一个高精度int，并返回int位数
{
	int i = 0;
	int length = imax(lengthG, lengthR);
	for (; i < length; i++)
	{
		numR[i] = numG[i];
	}
	return lengthG;
}
void print_preNum(int iNum[], int length)//打印int高精度
{
	int i = 0;
	for (i = length - 1; i >=0; i--)
	{
		printf("%d", iNum[i]);
	}
	printf("\n");
	return;
}
int Plus(int num1[], int num2[], int l1, int l2, int numR[])//实现高精度加高精度，存入第三个数（可以是之前出现的），返回长度
{
	int max = imax(l1, l2);
	int this = 0, next = 0, sum = 0;
	int i = 0;
	for (i = 0; (i < max || next != 0); i++)
	{
		sum = num1[i] + num2[i] + next;
		this = sum % 10;
		next = sum / 10;
		numR[i] = this;		
	}
	return i;
}
int Times(int num1[], int num2[], int l1, int l2, int numR[], int lR)//实现高精度乘以高精度，存入第三个数（可以是之前出现的），返回长度
{
	int numDef1[DIGITS] = { 0 }, numDef2[DIGITS] = { 0 }, dl1 = 0, dl2 = 0;
	int this = 0, next = 0, sum = 0;
	int i = 0, j = 0;
	for(j = 0; j < l1; j++)
	{
		for (i = 0; (i < l2|| next !=0); i++)
		{
			sum = num1[j] * num2[i] + next;
			this = sum % 10;
			next = sum / 10;
			numDef2[i + j] = this;			
		}
		dl2 = i + j;
		dl1 = Plus(numDef2, numDef1, dl2, dl1, numDef1);
		numInf(numDef2, &dl2);
	}
	return numTnum(numDef1, numR, dl1, lR);
}
int Subtraction(int num1[], int num2[], int l1, int l2, int numR[], int lR)
{

}




int main()
{
	int iNum1[DIGITS] = { 0 }, iNum2[DIGITS] = {0};
	int length1 = scanf_num(iNum1), length2 = scanf_num(iNum2);

	//length1 = numTnum(iNum2, iNum1, length2, length1);
	length1 = Times(iNum2, iNum1, length2, length1, iNum1, length1);

	print_preNum(iNum1, length1);

	return 0;
}
