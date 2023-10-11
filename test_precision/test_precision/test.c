#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 1024
#include <stdio.h>
#include <string.h>

int imax(int a, int b)
{
	return a > b ? a : b;
}
void scanf_num(int iNum[], int* pl)//�����ݴ���int
{
	int i = 0;
	char num[DIGITS] = { 0 };
	scanf("%s", num);
	int length = (int)strlen(num);
	for (i = 0; i < length; i++)
	{
		iNum[i] = num[length - 1 - i] - '0';
	}
	*pl = length;
	return;
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
void numTnum(const int numG[], int numR[], int lengthG, int* pLengthR)//��ǰһ���߾���int��ֵ��һ���߾���int��������intλ��
{
	int i = 0;
	int length = imax(lengthG, *pLengthR);
	for (; i < length; i++)
	{
		numR[i] = numG[i];
	}
	*pLengthR = lengthG;
	return;
}
void print_num(int iNum[], int length)//��ӡint�߾���
{
	int i = 0;
	for (i = length - 1; i >=0; i--)
	{
		printf("%d", iNum[i]);
	}
	printf("\n");
	return;
}
int Plus(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//ʵ�ָ߾��ȼӸ߾��ȣ��������������������֮ǰ���ֵģ������س���
{
	int max = imax(l1, l2);
	int this = 0, next = 0, sum = 0, numDef[DIGITS] = { 0 };
	int i = 0;
	for (i = 0; (i < max || next != 0); i++)
	{
		sum = num1[i] + num2[i] + next;
		this = sum % 10;
		next = sum / 10;
		numDef[i] = this;		
	}
	numTnum(numDef, numR, i, pL);
	return 0;
}
void Times(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//ʵ�ָ߾��ȳ��Ը߾��ȣ��������������������֮ǰ���ֵģ������س���
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
		Plus(numDef2, numDef1, dl2, dl1, numDef1, &dl1);
		numInf(numDef2, &dl2);
	}
	numTnum(numDef1, numR, dl1, pL);
	return;
}
int Compare(const int num1[], const int num2[], const int l1, const int l2)
{
	if (l1 > l2)
		return 1;
	else if (l1 < l2)
		return -1;
	else
	{
		int i = l1 - 1;
		for (; i >= 0; i--)
		{
			if (num1[i] > num2[i])
				return 1;
			else if (num1[i] < num2[i])
				return -1;
		}
		return 0;
	}
}
void Subtraction(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//ֻ�����ô�����С����doge
{
	int com = Compare(num1, num2, l1, l2);
	if (com == -1)
	{
		printf("����д����\n");
		return 0;
	}
	int i = 0, def = 0, this = 0, next = 0, numDef[DIGITS] = { 0 }, ret = 0;
	for (; i < l2 || next != 0; i++)
	{
		def = num1[i] - num2[i] + next;
		if (def >= 0)
		{
			this = def;
			next = 0;
		}
		else
		{
			this = 10 + def;
			next = -1;
		}
		numDef[i] = this;
	}
	for (i = l1 - 1; i > 0; i--)
	{

		if (numDef[i] != 0)
			break;
		ret++;
	}
	numTnum(numDef, numR, l1 - ret, pL);
	return;
}
//int LowQuotient(int num[], int l, int x, int numR[], int lR, int* pLeft)//�߾��ȳ��Ե;���
//{
//	int i = l - 1, this = 0, next = 0, def = 0, numDef[DIGITS] = { 0 }, ret = 0;
//	for (; i >= 0; i--)
//	{
//		def = num[i] + 10 * next;
//		this = def / x;
//		next = def % x;	
//		numDef[i] = this;
//	}
//	for (i = l - 1; i > 0; i--)
//	{
//		if (numDef[i] != 0)
//			break;
//		ret++;
//	}
//	*pLeft = next;
//	return numTnum(numDef, numR, l - ret, lR);
//}



int main()
{
	int num1[DIGITS] = { 0 }, num2[DIGITS] = { 0 }, length1 = 0, length2 = 0;
	scanf_num(num1, &length1);
	scanf_num(num2, &length2);
	Subtraction(num1, num2, length1, length2, num1, &length1);



	print_num(num1, length1);
}
//11 - 1���ԣ������