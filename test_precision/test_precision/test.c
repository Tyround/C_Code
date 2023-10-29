#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 626
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//这个数帮助进入蒙哥马利域
unsigned char MontNumSq[DIGITS] = { [618] = 1 };
int lMNS = 619;

////返回x的负逆元，在蒙哥马利算法中，这里输入的x是该进制下1位数，而考虑到取的是一个可能的质数，尾数只可能是1379
unsigned char antiMod10(unsigned char x)
{
	int ret = 0;
	if (x == 1)
		ret = 9;
	else if (x == 3)
		ret = 3;
	else if (x == 7)
		ret = 7;
	else if (x == 9)
		ret = 1;
	return ret;		
}
//输入一个高精度数
void scanf_num(unsigned char iNum[], int* pl)
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
//将高精度数右移一位
void digitRight(unsigned char num[], int* pL)
{
	for (int i = 0; i < *pL; i++)
	{
		num[i] = num[i + 1];
	}
	if(*pL > 1)
		(*pL)--;
}
//初始化一个高精度数组
void numInf(unsigned char num[], int* pLength)
{
	int i = 0;
	for (; i < DIGITS; i++)
	{
		num[i] = 0;
	}
	*pLength = 1;
	return;
}
//将一个高精度数组传给另一个
void numTnum(unsigned char numG[], unsigned char numR[], int lengthG, int* pLengthR)
{
	int i = 0;
	int length = lengthG > *pLengthR ? lengthG : *pLengthR;
	for (; i < length; i++)
	{
		numR[i] = numG[i];
	}
	*pLengthR = lengthG;
	return;
}
//打印一个高精度数
void print_num(unsigned char iNum[], int length)
{
	int i = 0;
	for (i = length -1; i >=0; i--)
	{
		printf("%d", iNum[i]);
	}
	printf("\n");
	return;
}
//高精度加法
void Plus(unsigned char num1[], unsigned char num2[], int *l1, int l2)
{
	if (l2 == 1 && num2[0] == 0)
		return;
	int max = *l1 > l2 ? *l1 : l2;
	int i = 0,this = 0, next = 0, sum = 0;
	for (i = 0; (i < max || next != 0); i++)
	{
		sum = num1[i] + num2[i] + next;
		this = sum % 10;
		next = sum / 10;
		num1[i] = this;		
	}
	*l1 = i;
	return;
}
//高精度乘法
void Times(unsigned char num1[], unsigned char num2[], int l1, int l2, unsigned char numR[], int* pL)
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
		Plus( numDef1,numDef2,  &dl1,dl2);
		numInf(numDef2, &dl2);
	}
	numTnum(numDef1, numR, dl1, pL);
	return;
}
//高精度数比较大小
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
//高精度减法（仅支持大数减小数
void Subtraction(unsigned char num1[], unsigned char num2[], int *l1, int l2)//只考虑用大数减小数（doge
{
	int com = Compare(num1, num2, *l1, l2);
	if (com == -1)
	{
		printf("不想写负数\n");
		return;
	}
	int i = 0;
	int def = 0, this = 0, next = 0,ret = 0;
	for (i = 0; i < *l1 || next != 0; i++)
	{
		
		def = num1[i] - num2[i] + next;
		//考虑用按位操作符代替减法
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
		num1[i] = this;

	}
	for (i = *l1 - 1; i > 0; i--)
	{

		if (num1[i] != 0)
			break;
		ret++;
	}
	*l1 = *l1 - ret;
	return;
}
//高精度除以低精度,返回余数
int LowQuotient(unsigned char num[], int* l, int x)
{
	int i = *l - 1;
	int this = 0, next = 0, def = 0,ret = 0;
	for (; i >= 0; i--)
	{
		def = num[i] + 10 * next;
		this = def / x;
		next = def % x;	
		num[i] = this;
	}
	for (i = *l - 1; i > 0; i--)
	{
		if (num[i] != 0)
			break;
		ret++;
	}
	*l = *l - ret;
	return next;
}
//高精度除以高精度
void HighQuotient(unsigned char num[], int* l, unsigned char div[], int dl)
{
	int i = *l - dl;
	int lDefDef = 0;
	for (;i >= 0; i--)
	{
		while (-1 != Compare(num + i, div, *l - i, dl))
		{
			lDefDef = *l - i;
			Subtraction(num + i, div, &lDefDef, dl);
			*l = lDefDef + i;		
		}
	}
	return;
}
//将高精度数中含2因子分解出来，返回2的次数
int Devisor2Extract(unsigned char num[], int length, unsigned char numR[], int* pL)
{
	int count = 0,  lDef = 1;
	unsigned char numDef[DIGITS] = { 0 };
	numTnum(num, numDef, length, &lDef);
	int ass = 0;
	for(; numDef[0] % 2 != 1; count++)
	{
		LowQuotient(numDef, &lDef, 2);
	}
	numTnum(numDef, numR, lDef, pL);
	return count;
}


//低乘高
void LowTimes(unsigned char num[],int l, int x, unsigned char numR[], int* pL)
{
	/*if (x == 0)
	{
		numInf(numR, pL);
	}
	else
	{
		unsigned char numDef[DIGITS] = { 0 };
		int lDef = 1, i = 0;
		for (; x; i++)
		{
			numDef[i] = x % 10;
			x /= 10;
		}
		lDef = i;
		Times(num, numDef, l, lDef, numR, pL);
	}*/

	numInf(numR, pL);
	if (x != 0)
	{

		{
			int this = 0, next = 0, prod = 0, j = 0;
			for (j = 0; j < l || next != 0; j++)
			{
				prod = num[j] * x + next;
				next = prod / 10;
				this = prod % 10;
				numR[j] = this;
			}
			for (; numR[j - 1] == 0; j--)
			{
				if (j == 1)
					break;
			}
			*pL = j;
		}
	}
	return;
}
//(a*b/R^k) mod N
void RommelTimesMod(unsigned char num1[], int* pL, unsigned char num2[], int l2, unsigned char mod[], int lM)
{
	unsigned char numDef[DIGITS] = { 0 }, trans[DIGITS] = { 0 };
	int i = 0, lDef = 1, lTra = 1, q = 0, anti = antiMod10(mod[0]);
	for (i = 0;i<309;i++)
	{
		q =(( (numDef[0] + num1[0] * num2[i])%10) * anti) % 10;//q是令a*b 被r整除的增量
		LowTimes(num1, *pL, num2[i], trans, &lTra);
		Plus(numDef, trans, &lDef, lTra);
		LowTimes(mod, lM, q, trans, &lTra);
		Plus(numDef, trans, &lDef, lTra);
		//这里我们要写十进制下的移位操作符（
		digitRight(numDef, &lDef);
		//if (Compare(numDef, mod, lDef, lM) == 1)
		//	//Subtraction(numDef, mod, &lDef, lM);
		//	HighQuotient(numDef, &lDef, mod, lM);
	}

	if (Compare(numDef, mod, lDef, lM) != -1)
		Subtraction(numDef, mod, &lDef, lM);
		//HighQuotient(numDef, &lDef,mod,  lM);
	numTnum(numDef, num1, lDef, pL);
	return;
}
//计算a*b mod n
void QuickTimesModMont(unsigned char num1[], int* pl1, unsigned char num2[], int l2, unsigned char mod[], int lM)
{

	/*numInf(MontNumSq, &lMNS);
	MontNumSq[618] = 1;
	lMNS = 619;
	HighQuotient(MontNumSq, &lMNS, mod, lM);*/


	//unsigned char MontNum[DIGITS] = { 0 };

	unsigned char num2Cop[DIGITS] = { 0 };
	int l2C = 1;
	unsigned char single1[DIGITS] = { 1 };
	int lS1 = 1;

	numTnum(num2, num2Cop, l2, &l2C);
	RommelTimesMod(num1, pl1, MontNumSq, lMNS, mod, lM);
	RommelTimesMod(num1, pl1, num2Cop, l2C, mod, lM);

	/*RommelTimesMod(num2Cop, &l2C, MontNumSq, lMNS, mod, lM);
	RommelTimesMod(num1, pl1, num2Cop, l2C, mod, lM);
	RommelTimesMod(num1, pl1, single1, lS1, mod, lM);*/
	return;
}
//快速模幂
void GPmodP(unsigned char base[], int lBase, unsigned char index[], int lIndex, unsigned char numP[], int lP, unsigned char numR[], int* pL)
{
	/*time_t a, b;
	a = clock();*/

	unsigned char baseC[DIGITS] = { 0 }, indexC[DIGITS] = { 0 }; 
	int lIC = 1, lBC = 1;
	numTnum(base, baseC, lBase, &lBC);
	numTnum(index, indexC, lIndex, &lIC);
	unsigned char numDef[DIGITS] = { 1,0 };
	int left = 0;
	int lDef = 1;
	
	
	if (-1 != Compare(baseC, numP, lBC, lP))
	{
		
		//HighQuotient(baseC, &lBC, numP, lP);


		int i = lBC - lP;
		int lDefDef = 0;
		for (; i >= 0; i--)
		{
			while (-1 != Compare(baseC + i, numP, lBC - i, lP))
			{
				lDefDef = lBC - i;
				Subtraction(baseC + i, numP, &lDefDef, lP);
				lBC = lDefDef + i;
			}
		}
		
	}
	
	
	
	for (; !(lIC == 1 && indexC[0] == 1);)
	{	
		
		
		left = LowQuotient(indexC, &lIC, 2);
		if (left == 1)
		{
			Times(numDef, baseC, lDef, lBC, numDef, &lDef);
			if (-1 != Compare(numDef, numP, lDef, lP))
			{
				int i = lDef - lP;
				int lDefDef = 0;
				for (; i >= 0; i--)
				{
					while (-1 != Compare(numDef + i, numP, lDef - i, lP))
					{
						lDefDef = lDef - i;
						Subtraction(numDef + i, numP, &lDefDef, lP);
						lDef = lDefDef + i;
					}
				}
			}
		}
		
		Times(baseC, baseC, lBC, lBC, baseC, &lBC);
		
		
		if (-1 != Compare(baseC, numP, lBC, lP))
		{		
			int i = lBC - lP;
			int lDefDef = 0;
			for (; i >= 0; i--)
			{

				while (-1 != Compare(baseC + i, numP, lBC - i, lP))
				{
					lDefDef = lBC - i;
					Subtraction(baseC + i, numP, &lDefDef, lP);
					lBC = lDefDef + i;
				}
				
			}		
		}
		
	}
	
	
	Times(numDef, baseC, lDef, lBC, baseC, &lBC);
	if (-1 != Compare(baseC, numP, lBC, lP))
	{
		int i = lBC - lP;
		int lDefDef = 0;
		for (; i >= 0; i--)
		{
			while (-1 != Compare(baseC + i, numP, lBC - i, lP))
			{
				lDefDef = lBC - i;
				Subtraction(baseC + i, numP, &lDefDef, lP);
				lBC = lDefDef + i;
			}
		}
	}
	numTnum(baseC, numR, lBC, pL);
	

	/*b = clock();
	printf("%lf\n", (double)(b - a) / CLOCKS_PER_SEC);*/
	return;
}

//蒙哥马利快速模幂
void GpMontModP(unsigned char base[], int lBase, unsigned char index[], int lIndex, unsigned char numP[], int lP, unsigned char numR[], int* pL)
{
	
	unsigned char baseC[DIGITS] = { 0 }, indexC[DIGITS] = { 0 }, numT[DIGITS] = { 1 };
	int lIC = 1, lBC = 1, lT = 1;
	numTnum(base, baseC, lBase, &lBC);
	numTnum(index, indexC, lIndex, &lIC);
	unsigned char numDef[DIGITS] = { 1,0 };
	int left = 0;
	int lDef = 1;

	RommelTimesMod(numT, &lT, MontNumSq, lMNS, numP, lP);
	RommelTimesMod(baseC, &lBC, MontNumSq, lMNS, numP, lP);

	for (; !(lIC == 1 && indexC[0] == 1);)
	{

		left = LowQuotient(indexC, &lIC, 2);
		if (left == 1)
		{
			RommelTimesMod(numT, &lT, baseC, lBC, numP, lP);
		}
		RommelTimesMod(baseC, &lBC, baseC, lBC, numP, lP);

	}
	
	RommelTimesMod(baseC, &lBC, numT, lT, numP, lP);
	unsigned char hehe[DIGITS] = { 1 };
	int hehehe = 1;
	RommelTimesMod(baseC, &lBC, hehe, hehehe, numP, lP);
	numTnum(baseC, numR, lBC, pL);

	

}
//mr素数检验（蒙哥马利
int MRtestmont(unsigned char num[], int l, unsigned char base[], int lB)//输入p，及检验用的底数
{
	
	unsigned char numDef[DIGITS] = { 0 }, mod[DIGITS] = { 0 };
	int lDef = 1, lMod = 1;
	unsigned char pS[DIGITS] = { 0 }, num1[DIGITS] = { 1, 0 }, num2[DIGITS] = { 2, 0 };//pS用于存储n - 1， def里存放指数,mod中存放mod
	int l1 = 1, lPS = 1, l2 = 1;
	numTnum(num, pS, l, &lPS);
	Subtraction(pS, num1, &lPS, l1);
	
	int k = Devisor2Extract(pS, lPS, numDef, &lDef);
	
	//可知k >= 1
	int i = 0, ret = 0;
	

	//GPmodP(base, lB, numDef, lDef, num, l, mod, &lMod);//时间主要花在这一步上
	GpMontModP(base, lB, numDef, lDef, num, l, mod, &lMod);
	
	
	for (;; i++, GpMontModP(mod, lMod, num2, l2, num, l, mod, &lMod))
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
//mr素数检验
int MRtest(unsigned char num[], int l, unsigned char base[], int lB)//输入p，及检验用的底数
{

	unsigned char numDef[DIGITS] = { 0 }, mod[DIGITS] = { 0 };
	int lDef = 1, lMod = 1;
	unsigned char pS[DIGITS] = { 0 }, num1[DIGITS] = { 1, 0 }, num2[DIGITS] = { 2, 0 };//pS用于存储n - 1， def里存放指数,mod中存放mod
	int l1 = 1, lPS = 1, l2 = 1;
	numTnum(num, pS, l, &lPS);
	Subtraction(pS, num1, &lPS, l1);

	int k = Devisor2Extract(pS, lPS, numDef, &lDef);

	//可知k >= 1
	int i = 0, ret = 0;


	GPmodP(base, lB, numDef, lDef, num, l, mod, &lMod);//时间主要花在这一步上
	//GpMontModP(base, lB, numDef, lDef, num, l, mod, &lMod);


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
		if (i == k - 1)
		{
			ret = 0;
			break;
		}
	}

	return ret;
}
//对一个大数进行提前检验
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
//多次mr素数检验（蒙哥马利
int superMRmont(unsigned char num[], int l)//用多个底数进行MR检验，可能是质数则返回1，合数返回0
{
	if (preLowTest(num, l) == 1)
		return 1;
	if(preTest(num, l) == 0)
		return 0;
	numInf(MontNumSq, &lMNS);
	MontNumSq[618] = 1;
	lMNS = 619;
	HighQuotient(MontNumSq, &lMNS, num, l);
	unsigned char aGroup[10][DIGITS] = { {2},{5,2,3} ,{5,7,3,9},{8,7,1,8,2}, {5,7,7,0,5,4}, {4,0,5,0,8,7,9},{2,2,0,5,6,2,5,9,7,1} };//,{7,5,7,8,9,9,6,3,2,1,4,5,7,8,8,5,2,3,6,4,7,8,5,4,4,5,9,5,1,5,5,8,5,1,2,3,7,9,8,6,4,7,9,4,5,1,6,5,5,4,5,6,4,6,4,4,5,4,8,7,9,2,9} };
	int lA[10] = { 1 , 3 ,4, 5, 6, 7, 10};
	int i = 0, ret = 0;
	for ( i = 6; i >= 0; i--)
	{
		
		ret = MRtestmont(num, l, aGroup[i], lA[i]);
		
		if (ret == 0)
			return 0;
	}
	return 1;
}
//多次mr素数检验
int superMR(unsigned char num[], int l)//用多个底数进行MR检验，可能是质数则返回1，合数返回0
{

	if (preLowTest(num, l) == 1)
		return 1;
	if (preTest(num, l) == 0)
		return 0;

	unsigned char aGroup[10][DIGITS] = { {2},{5,2,3} ,{5,7,3,9},{8,7,1,8,2}, {5,7,7,0,5,4}, {4,0,5,0,8,7,9},{2,2,0,5,6,2,5,9,7,1} };//,{7,5,7,8,9,9,6,3,2,1,4,5,7,8,8,5,2,3,6,4,7,8,5,4,4,5,9,5,1,5,5,8,5,1,2,3,7,9,8,6,4,7,9,4,5,1,6,5,5,4,5,6,4,6,4,4,5,4,8,7,9,2,9} };
	int lA[10] = { 1 , 3 ,4, 5, 6, 7, 10 };
	int i = 0, ret = 0;
	for (i = 6; i >= 0; i--)
	{

		ret = MRtest(num, l, aGroup[i], lA[i]);

		if (ret == 0)
			return 0;
	}
	return 1;
}
//随机//生成2^1024至2^1025的大数（实际小一点doge
void randBig(unsigned char num[], int* l)
{
	//这是2^1024
	char Cstandard[320] = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216";
	unsigned char stand[320] = { 0 };
	int lStand = 309, iStand = 0;
	for (iStand = 0; iStand < 309; iStand++)
	{
		stand[iStand] = Cstandard[308 - iStand] - '0';
	}
	int i = 0;
	num[308] = rand() % 2;
	num[307] = rand() % 8;
	num[306] = rand() % 9;
	for (i = 0; i < 306; i++)
	{
		num[i] = rand() % 10;
	}
	for (i = 308; i > 0; i--)
	{
		if (num[i] != 0)
			break;
	}	
	*l = i + 1;
	Plus(num, stand, l, lStand);
	return;
}
//将高精度以十六进制输出
void oxprintNum(unsigned char num[], int l,unsigned end[], int lEnd)
{
	for (int i = 0; i < 256; i++)
	{
		end[i] = LowQuotient(num, &l, 16);
	}
	for (int i = 255; i >= 0; i--)
	{
		printf("%x", end[i]);
	}
	printf("\n");
	return;
}
//随机生成一个质数（2进制下1024位）
void PrimeGenerate(void)
{	
	
	unsigned char num1[DIGITS] = { 1 };
	int l1 = 1;
	
	unsigned char num[DIGITS] = { 0 };
	int l = 0;
	int count = 1;
	randBig(num, &l);	
		
	for(;;count++)
	{			
		//printf("%d ", count);
		//print_num(num, l);	
		if (superMRmont(num, l) == 1)
		{
			unsigned char end[DIGITS] = { 0 }, lE = 256;
			printf("十进制：\n");
			print_num(num, l);
			printf("十六进制：\n");
			oxprintNum(num, l, end , lE);
			printf("Congradulations!!!\n");

			
			FILE* fp = fopen(".\\data.txt", "a");
			fputc(' ', fp);
			for (int i = 255; i >= 0; i--)
			{
				fprintf(fp, "%ox", end[i]);
			}
			fclose(fp);
			break;
		}	
		Plus(num, num1, &l, l1);
	}
	return;
}



int main()
{
	srand((unsigned int)time(NULL));


	int judge = 0;
	printf("输入1生成质数，输入2判断质数，请输入：");
	while (1)
	{

		scanf("%d", &judge);
		if (judge == 1)
		{
			time_t a, b;
			a = clock();
			//生成质数
			printf("1024bits big prime :\n");
			PrimeGenerate();
			b = clock();
			printf("full time = %lf\n", (double)(b - a) / CLOCKS_PER_SEC);
			break;
		}
		else if (judge == 2)
		{
			//判断质数
			printf("please input judge times in int n:");
			unsigned char num[DIGITS] = { 0 };
			int length = 0, n = 10, i = 0;
			scanf("%d", &n);
			for (; i < n; i++)
			{
				printf("please input number:\n");
				scanf_num(num, &length);
				if (superMR(num, length) == 1)
					printf("prime\n");
				else
					printf("not prime\n");
			}
			break;
		}
		else
		{
			printf("en?\n");
		}
	}


	

	/*printf("please input n:");
	unsigned char num[DIGITS] = { 0 };
	int length = 0, n = 10, i = 0;
	scanf("%d", &n);
	for(;i < n ; i++)
	{
		printf("please input big number:\n");
		scanf_num(num, &length);
		if (superMR(num, length) == 1)
			printf("是质数");
		else
			printf("不是质数");
	}*/
	


	//unsigned char numR[DIGITS] = { 0 }, numK[DIGITS] = { 0 };
	//int lR = 1, lK = 1;
	//unsigned char numP[DIGITS] = { 0 };
	//int lP = 1;

	//while (1)
	//{
	//	scanf_num(numR, &lR);
	//	scanf_num(numK, &lK);
	//	scanf_num(numP, &lP);
	//	//RommelTimesMod(numR, &lR, numK, lK, numP, lP);
	//	QuickTimesModMont(numR, &lR, numK, lK, numP, lP);
	//	print_num(numR, lR);
	//}


	///*RommelTimesMod(numR, &lR, numK, lK, num2, l2);
	//print_num(numR, lR);*/

	///*RommelTimesMod(num7, &l7, MontNumSq, lMNS, num2, l2);
	//print_num(num7, l7);*/

	//QuickTimesModMont(num2, &l2, num7, l7, num2, l2);
	//print_num(num2, l2);
		

		//int d2e = Devisor2Extract(numK, lK, numK, &lK);

		//GPmodP(num2, l2, numR, lR,num7, l7, numR, &lR);
		//print_num(numK, lK);
		//printf("%d\n", d2e);
	
	//print_num(numK, lK);
}

//无法识别的质数(solved
//342306316014587030881690081234553129223851888600997080320601449774651684245132200662810329136023462577807460819354035577666036210546350935482857425399429932276139355925853689237564882147452991125643579312194921647070628767792479433829627837566731708691455608688656254318260177948189823333068428160695388768349
// 
// 
//1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000