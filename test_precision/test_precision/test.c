#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 2048
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int imax(int a, int b)
{
	return a > b ? a : b;
}
void scanf_num(unsigned char iNum[], int* pl)//输入一串数字，存入unsigned char型高精度
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
			iNum[i] = 0;
		}
	*pl = def;
	return;
}

//void charTnum(unsigned char x, unsigned char num[], int* pL)//将unsigned char存入高精度中
//{
//	unsigned char i = 0;
//	for (; x != 0; i++)
//	{
//		num[i] = x % 10;
//		x /= 10;
//	}
//	unsigned char def = i;
//	if(*pL > i - 1)
//		for (; i < *pL; i++)
//		{
//			num[i] = 0;
//		}
//	*pL = def;
//	return;
//}
void numInf(unsigned char num[], int* pLength)
{
	int i = 0;
	for (; i < *pLength; i++)
	{
		num[i] = 0;
	}
	*pLength = 1;
	return;
}

void numTnum(unsigned char numG[], unsigned char numR[], int lengthG, int* pLengthR)//将前一个高精度unsigned char赋值后一个高精度unsigned char
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
void print_num(unsigned char iNum[], int length)//打印unsigned char高精度
{
	int i = 0;
	for (i = length -1; i >=0; i--)
	{
		printf("%d", iNum[i]);
	}
	printf("\n");
	return;
}
void Plus(unsigned char num1[], unsigned char num2[], int l1, int l2, unsigned char numR[], int* pL)//实现高精度加高精度，存入第三个数（可以是之前出现的）
{
	int max = imax(l1, l2);
	unsigned char  numDef[DIGITS] = { 0 };
	int i = 0,this = 0, next = 0, sum = 0;
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
void Times(unsigned char num1[], unsigned char num2[], int l1, int l2, unsigned char numR[], int* pL)//实现高精度乘以高精度，存入第三个数（可以是之前出现的）
{
	unsigned char numDef1[DIGITS] = { 0 }, numDef2[DIGITS] = { 0 };
	int dl1 = 0, dl2 = 0;
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
int Compare(const unsigned char num1[], const unsigned char num2[], int l1, int l2)//1>,0=,-1<
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
void Subtraction(unsigned char num1[], unsigned char num2[], int l1, int l2, unsigned char numR[], int* pL)//只考虑用大数减小数（doge
{

	int com = Compare(num1, num2, l1, l2);
	if (com == -1)
	{
		printf("不想写负数\n");
		return;
	}
	int i = 0;
	unsigned char numDef[DIGITS] = { 0 };
	int def = 0, this = 0, next = 0,ret = 0;
	for (i = 0; i < l1 || next != 0; i++)
	{

		def = (int)num1[i] - (int)num2[i] + next;
		next = 0;
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
int LowQuotient(unsigned char num[], int l, int x, unsigned char numR[], int* pL)//高精度除以低精度,返回余数
{
	int i = l - 1;
	unsigned char numDef[DIGITS] = { 0 };
	int this = 0, next = 0, def = 0,ret = 0;
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
void HighQuotient(unsigned char num[], int l, unsigned char div[], int dl, unsigned char quo[], int* lQ, unsigned char remainder[], int* lR)//高精度除以高精度
{
	unsigned char numDef[DIGITS] = { 0 }, quoDef[DIGITS] = { 0 };
	int lDef = 0, lQD = 0;
	int i = l - dl;
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
//void GreatPower(int a, unsigned char num[], int length, unsigned char numR[], int* pL)//求低精度的高精度次幂
//{
//	unsigned char numA[DIGITS] = { 0 };
//	int lA = 1;
//	charTnum(a, numA, &lA);
//
//	unsigned char numCopy[DIGITS] = { 0 };
//	int lCopy = 0;
//	numTnum(num, numCopy, length, &lCopy);
//	unsigned char numDef[DIGITS] = { 1,0 }, left = 0;
//	int lDef = 1;
//
//	for (; !(lCopy == 1 && numCopy[0] == 1);)
//	{
//		left = LowQuotient(numCopy, lCopy, 2, numCopy, &lCopy);
//		if(left == 1)
//			Times(numDef, numA, lDef, lA, numDef, &lDef);
//		
//		Times(numA, numA, lA, lA, numA, &lA);
//
//	}
//	Times(numDef, numA, lDef, lA, numA, &lA);
//	numTnum(numA, numR, lA, pL);
//
//	return;
//}
int Devisor2Extract(unsigned char num[], int length, unsigned char numR[], int* pL)//将num中的2分解出来，奇因式输入numR,返回2因子次数
{
	int count = 0,  lDef = 1;
	unsigned char numDef[DIGITS] = { 0 };
	numTnum(num, numDef, length, &lDef);
	int ass = 0;
	for(; numDef[0] % 2 != 1; count++)
	{
		LowQuotient(numDef, lDef, 2, numDef, &lDef);
	}
	numTnum(numDef, numR, lDef, pL);
	return count;
}
void GPmodP(unsigned char base[], int lBase, unsigned char index[], int lIndex, unsigned char numP[], int lP, unsigned char numR[], int* pL)//不难发现一个数的高精度次方大得可啪，需要在幂方过程中时时减去p
{
	unsigned char baseC[DIGITS] = { 0 }, indexC[DIGITS] = { 0 }; 
	int lIC = 1, lBC = 1;
	unsigned char rabbish[DIGITS] = { 0 };
	int lRabbish = 1;
	numTnum(base, baseC, lBase, &lBC);
	numTnum(index, indexC, lIndex, &lIC);
	unsigned char numDef[DIGITS] = { 1,0 };
	int left = 0;
	int lDef = 1;
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
int MRtest(unsigned char num[], int l, unsigned char base[], int lB)//输入p，及检验用的底数
{
	unsigned char numDef[DIGITS] = { 0 }, mod[DIGITS] = { 0 };
	int lDef = 1, lMod = 1;
	unsigned char pS[DIGITS] = { 0 }, num1[DIGITS] = { 1, 0 }, num2[DIGITS] = { 2, 0 };//pS用于存储n - 1， def里存放指数,mod中存放mod
	int l1 = 1, lPS = 1, l2 = 1;
	Subtraction(num, num1, l, l1, pS, &lPS);
	int k = Devisor2Extract(pS, lPS, numDef, &lDef);
	//可知k >= 1
	int i = 0, ret = 0;
	GPmodP(base, lB, numDef, lDef, num, l, mod, &lMod);
	for (;; i++, GPmodP(mod, lMod, num2, l2, num, l, mod, &lMod))
	{
		if (Compare(mod, pS, lMod, lPS) == 0)
		{
			ret = 1;
			break;
		}
		else if (Compare(mod, num1, lMod, l1) == 0)
		{
			if (i == 0)
			{
				ret = 1;
				break;
			}
			else
			{
				ret = 0;
				break;
			}
		}
		if(i == k - 1)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}
int preTest(unsigned char num[], int l)//对高精度数进行预处理，可能是质数返回1， 合数返回0
{

	if (num[0] == 0 || num[0] == 2 || num[0] == 4 || num[0] == 6 || num[0] == 8 || num[0] == 5)//去除2和5的倍数
		return 0;
	int sumOdd = 0, sumEven = 0, i = 0;
	for (; i < l; i++)//
	{
		if (i % 2 == 0)
			sumOdd += num[i];
		else
			sumEven += num[i];
	} 
	if ((sumOdd + sumEven) % 3 == 0)//去掉3倍数
		return 0;
	if ((sumOdd - sumEven) % 11 == 0)//去掉11倍数
		return 0;
	//7的倍数略微复杂，加入她的提升也是微小的，不写啦
	return 1;
}
int preLowTest(unsigned char num[], int l)//判断很小的质数
{
	if (l == 1 && (num[0] == 2 || num[0] == 5))
		return 1;
	if (l == 2 && num[0] == 1 && num[1] == 1)
		return 1;
	return 0;
}
int superMR(unsigned char num[], int l)//用多个底数进行MR检验，可能是质数则返回1，合数返回0
{
	if (preLowTest(num, l) == 1)
		return 1;
	if(preTest(num, l) == 0)
		return 0;
	
	unsigned char aGroup[10][DIGITS] = { {2},{5,2,3} ,{5,7,3,9},{8,7,1,8,2}, {5,7,7,0,5,4}, {4,0,5,0,8,7,9},{2,2,0,5,6,2,5,9,7,1}};
	int lA[10] = { 1 , 3 ,4, 5, 6, 7, 10};
	int i = 0, ret = 0;
	for (; i < 7; i++)
	{
		ret = MRtest(num, l, aGroup[i], lA[i]);
		if (ret == 0)
			return 0;
	}
	return 1;
}
void randBig(unsigned char num[], int* l)//生成不大于2^1024的大数（实际小一点doge
{
	int i = 0;
	num[308] = rand() % 2;
	num[307] = rand() % 8;
	num[306] = rand() % 9;
	for (i = 0; i < 306; i++)
	{
		num[i] = rand() % 10;
	}
	for (i = 308; i >= 0; i--)
	{
		if (num[i] != 0)
			break;
	}
	*l = i + 1;
	return;
}
void PrimeGenerate(void)//随机生成一个质数（2进制下1024位）
{
	char Cstandard[320] = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216";
	unsigned char stand[320] = { 0 };
	int lStand = 309, iStand = 0;
	unsigned char num1[DIGITS] = { 1 };
	int l1 = 1;
	for (iStand = 0; iStand < 309; iStand++)
	{
		stand[iStand] = Cstandard[308 - iStand] - '0';
	}
	unsigned char num[DIGITS] = { 0 };
	int l = 0;
	int count = 1;
	randBig(num, &l);
	Plus(num, stand, l, lStand, num, &l);
	for(;;count++)
	{		
		printf("%d ", count);
		print_num(num, l);
		
		if (superMR(num, l) == 1)
		{
			printf("great!!!");
			break;
		}
		Plus(num, num1, l, l1, num, &l);
	}
	return;
}

int main()
{
	srand((unsigned int)time(NULL));
	printf("1024bits big prime :\n");
	PrimeGenerate();


	//printf("please input n:");
	//unsigned char num[DIGITS] = { 0 };
	//int length = 0, n = 10, i = 0;
	////scanf("%d", &n);
	//for(;i < n ; i++)
	//{
	//	printf("please input big number:\n");
	//	scanf_num(num, &length);
	//	if (superMR(num, length) == 1)
	//		printf("是质数");
	//	else
	//		printf("不是质数");
	//}
	



	/*unsigned char numR[DIGITS] = { 4,2,0,1 }, numK[DIGITS] = { 4,2,0,1, 9,9,9,9,9,9,9,9};
	int lR = 4, lK = 12;
	unsigned char num2[DIGITS] = {9,9,9};
	int l2 = 3;
	unsigned char num7[DIGITS] = {1,2,3,4,5,6};
	int l7 = 6;
	
	scanf_num(numK, &lK);*/
		

		//int d2e = Devisor2Extract(numK, lK, numK, &lK);

		//GPmodP(num2, l2, numR, lR,num7, l7, numR, &lR);
		//print_num(numK, lK);
		//printf("%d\n", d2e);
	
	//print_num(numK, lK);
}