#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 512
#include <stdio.h>


int imax(int a, int b)
{
	return a > b ? a : b;
}
void scanf_num(int iNum[], int* pl)//将数据存入int
{
	int i = 0;
	char num[DIGITS] = { 0 };
	scanf("%s", num);
	for (;num[i] != '\0'; i++)
	{
	}
	int length = i;
	for (i = 0; i < length; i++)
	{
		iNum[i] = num[length - 1 - i] - '0';
	}
	int def = i;
	if (*pl > i - 1)
		for (; i < *pl; i++)
		{
			num[i] = 0;
		}
	*pl = def;
	return;
}
void intTnum(int x, int num[], int* pL)//将int存入高精度中
{
	int i = 0;
	for (; x != 0; i++)
	{
		num[i] = x % 10;
		x /= 10;
	}
	int def = i;
	if(*pL > i - 1)
		for (; i < *pL; i++)
		{
			num[i] = 0;
		}
	*pL = def;
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
void numTnum(int numG[], int numR[], int lengthG, int* pLengthR)//将前一个高精度int赋值后一个高精度int
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
void print_num(int iNum[], int length)//打印int高精度
{
	int i = 0;
	for (i = length - 1; i >=0; i--)
	{
		printf("%d", iNum[i]);
	}
	printf("\n");
	return;
}
void Plus(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//实现高精度加高精度，存入第三个数（可以是之前出现的）
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
	return;
}
void Times(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//实现高精度乘以高精度，存入第三个数（可以是之前出现的）
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
int Compare(const int num1[], const int num2[], const int l1, const int l2)//1>,0=,-1<
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
void Subtraction(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//只考虑用大数减小数（doge
{
	int com = Compare(num1, num2, l1, l2);
	if (com == -1)
	{
		printf("不想写负数\n");
		return;
	}
	int i = 0, def = 0, this = 0, next = 0, numDef[DIGITS] = { 0 }, ret = 0;
	for (; i < l1 || next != 0; i++)
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
int LowQuotient(int num[], int l, int x, int numR[], int* pL)//高精度除以低精度,返回余数
{
	int i = l - 1, this = 0, next = 0, def = 0, numDef[DIGITS] = { 0 }, ret = 0;
	for (; i >= 0; i--)
	{
		def = num[i] + 10 * next;
		this = def / x;
		next = def % x;	
		numDef[i] = this;
	}
	for (i = l - 1; i > 0; i--)
	{
		if (numDef[i] != 0)
			break;
		ret++;
	}
	numTnum(numDef, numR, l - ret, pL);
	return next;
}
void HighQuotient(int num[], int l, int div[], int dl, int quo[], int* lQ, int remainder[], int* lR)//高精度除以高精度
{
	int i = l - dl, numDef[DIGITS] = { 0 }, lDef = 0, quoDef[DIGITS] = { 0 }, lQD = 0;
	numTnum(num, numDef, l, &lDef);
	int lDefDef = 0;
	for (;i >= 0; i--)
	{
		while (-1 != Compare(numDef + i, div, lDef - i, dl))
		{
			lDefDef = lDef - i;
			Subtraction(numDef + i, div, lDefDef, dl, numDef + i, &lDefDef);
			lDef = lDefDef + i;

			quoDef[i]++;
			if (lQD == 0)
			{
				lQD = i + 1;
			}
		}
	}
	if (lQD == 0)
		lQD++;
	numTnum(numDef, remainder, lDef, lR);
	numTnum(quoDef, quo, lQD, lQ);
	return;
}
void GreatPower(int a, int num[], int length, int numR[], int* pL)//求低精度的高精度次幂
{
	int numA[DIGITS] = { 0 }, lA = 1;
	intTnum(a, numA, &lA);

	int numCopy[DIGITS] = { 0 }, lCopy = 0;
	numTnum(num, numCopy, length, &lCopy);
	int numDef[DIGITS] = { 1,0 }, lDef = 1, left = 0;

	for (; !(lCopy == 1 && numCopy[0] == 1);)
	{
		left = LowQuotient(numCopy, lCopy, 2, numCopy, &lCopy);
		if(left == 1)
			Times(numDef, numA, lDef, lA, numDef, &lDef);
		
		Times(numA, numA, lA, lA, numA, &lA);

	}
	Times(numDef, numA, lDef, lA, numA, &lA);
	numTnum(numA, numR, lA, pL);

	return;
}
int Devisor2Extract(int num[], int length, int numR[], int* pL)//将num中的2分解出来，奇因式输入numR,返回2因子次数
{
	int remainder = 0, count = 0, numDef[DIGITS] = {0}, lDef = 0;
	numTnum(num, numDef, length, &lDef);
	for(; numDef[0] % 2 != 1; count++)
	{
		LowQuotient(numDef, lDef, 2, numDef, &lDef);
	}
	numTnum(numDef, numR, lDef, pL);
	return count;
}
void GPmodP(int base[], int lBase, int index[], int lIndex, int numP[], int lP, int numR[], int* pL)//不难发现一个数的高精度次方大得可啪，需要在幂方过程中时时减去p
{
	int baseC[DIGITS] = { 0 }, lBC = 1, indexC[DIGITS] = { 0 }, lIC = 1;
	int rabbish[DIGITS] = { 0 }, lRabbish = 1;
	numTnum(base, baseC, lBase, &lBC);
	numTnum(index, indexC, lIndex, &lIC);
	int numDef[DIGITS] = { 1,0 }, lDef = 1, left = 0;
	if (-1 != Compare(baseC, numP, lBC, lP))
	{
		//Subtraction(baseC, numP, lBC, lP, baseC, &lBC);
		HighQuotient(baseC, lBC, numP, lP, rabbish, &lRabbish, baseC, &lBC);
	}
	for (; !(lIC == 1 && indexC[0] == 1);)
	{
		
		left = LowQuotient(indexC, lIC, 2, indexC, &lIC);
		if (left == 1)
		{
			Times(numDef, baseC, lDef, lBC, numDef, &lDef);
			if (-1 != Compare(numDef, numP, lDef, lP))
			{
				HighQuotient(numDef, lDef, numP, lP, rabbish, &lRabbish, numDef, &lDef);
			}
		}
		Times(baseC, baseC, lBC, lBC, baseC, &lBC);
		if (-1 != Compare(baseC, numP, lBC, lP))
		{
			HighQuotient(baseC, lBC, numP, lP, rabbish, &lRabbish, baseC, &lBC);
		}
	}
	Times(numDef, baseC, lDef, lBC, baseC, &lBC);
	if (-1 != Compare(baseC, numP, lBC, lP))
	{
		HighQuotient(baseC, lBC, numP, lP, rabbish, &lRabbish, baseC, &lBC);
	}
	numTnum(baseC, numR, lBC, pL);
	return;
}



int main()
{
	int num1[DIGITS] = { 0 }, num2[DIGITS] = { 0 }, length1 = 0, length2 = 0;
	scanf_num(num1, &length1);
	scanf_num(num2, &length2);

	int numQ[DIGITS] = { 1,2 }, lQ = 2, numR[DIGITS] = { 0 }, lR = 1;
	scanf_num(numQ, &lQ);

	//GPmodP(num1, length1, num2, length2, numP, lP, numR, &lR);
	//Subtraction(num1, num2, length1, length2, numQ, &lQ);
	//HighQuotient(num1, length1, num2, length2, numQ, &lQ, numR, &lR);
	GPmodP(num1, length1, num2, length2, numQ, lQ, numR, &lR);
	//print_num(numQ, lQ);
	print_num(numR, lR);
}