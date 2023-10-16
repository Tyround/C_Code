#define _CRT_SECURE_NO_WARNINGS 1
#define DIGITS 666
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int imax(int a, int b)
{
	return a > b ? a : b;
}
void scanf_num(int iNum[], int* pl)//����һ�����֣�����int�͸߾���
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

void intTnum(int x, int num[], int* pL)//��int����߾�����
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

void numTnum(int numG[], int numR[], int lengthG, int* pLengthR)//��ǰһ���߾���int��ֵ��һ���߾���int
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
void Plus(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//ʵ�ָ߾��ȼӸ߾��ȣ��������������������֮ǰ���ֵģ�
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
void Times(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//ʵ�ָ߾��ȳ��Ը߾��ȣ��������������������֮ǰ���ֵģ�
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
void Subtraction(int num1[], int num2[], int l1, int l2, int numR[], int* pL)//ֻ�����ô�����С����doge
{
	int com = Compare(num1, num2, l1, l2);
	if (com == -1)
	{
		printf("����д����\n");
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
int LowQuotient(int num[], int l, int x, int numR[], int* pL)//�߾��ȳ��Ե;���,��������
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
void HighQuotient(int num[], int l, int div[], int dl, int quo[], int* lQ, int remainder[], int* lR)//�߾��ȳ��Ը߾���
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
void GreatPower(int a, int num[], int length, int numR[], int* pL)//��;��ȵĸ߾��ȴ���
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
int Devisor2Extract(int num[], int length, int numR[], int* pL)//��num�е�2�ֽ����������ʽ����numR,����2���Ӵ���
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
void GPmodP(int base[], int lBase, int index[], int lIndex, int numP[], int lP, int numR[], int* pL)//���ѷ���һ�����ĸ߾��ȴη���ÿ�ž����Ҫ���ݷ�������ʱʱ��ȥp
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
int MRtest(int num[], int l, int base[], int lB)//����p���������õĵ���
{
	int numDef[DIGITS] = { 0 }, lDef = 1, mod[DIGITS] = { 0 }, lMod = 1;
	int pS[DIGITS] = { 0 }, lPS = 1, num1[10] = { 1, 0 }, l1 = 1, num2[10] = { 2, 0 }, l2 = 1;
	Subtraction(num, num1, l, l1, pS, &lPS);
	int k = Devisor2Extract(pS, lPS, numDef, &lDef);
	//��֪k >=1
	int i = 1;
	for (; i <= k - 1 || i == 1; i++)
	{
		GPmodP(base, lB, numDef, lDef, num, l, mod, &lMod);
		if (Compare(mod, pS, lMod, lPS) == 0 || Compare(mod, num1, lMod, l1) == 0)
		{
			return 1;
		}
		Times(numDef, num2, lDef, l2, numDef, &lDef);
	}
	return 0;
}
int preTest(int num[], int l)//�Ը߾���������Ԥ������������������1�� ��������0
{

	if (num[0] == 0 || num[0] == 2 || num[0] == 4 || num[0] == 6 || num[0] == 8 || num[0] == 5)//ȥ��2��5�ı���
		return 0;
	int sumOdd = 0, sumEven = 0, i = 0;
	for (; i < l; i++)//
	{
		if (i % 2 == 0)
			sumOdd += num[i];
		else
			sumEven += num[i];
	}
	if ((sumOdd + sumEven) % 3 == 0)//ȥ��3����
		return 0;
	if (sumOdd == sumEven)//ȥ��11����
		return 0;
	//7�ı�����΢���ӣ�������������Ҳ��΢С�ģ���д��
	return 1;
}
int superMR(int num[], int l)//�ö����������MR���飬�����������򷵻�1����������0
{
	if(preTest(num, l) == 0)
		return 0;
	
	int aGroup[10][DIGITS] = { {2},{3,7} }, lA[10] = { 1 , 2};
	int i = 0, ret = 0;
	for (; i < 2; i++)
	{
		ret = MRtest(num, l, aGroup[i], lA[i]);
		if (ret == 0)
			return 0;
	}
	return 1;
}
void randBig(int num[], int* l)//���ɲ�����2^1024�Ĵ�����ʵ��Сһ��doge
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
void PrimeGenerate(void)//�������һ��������2������1024λ��
{
	char Cstandard[320] = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216";
	int stand[320] = { 0 }, lStand = 309, iStand = 0;
	int num1[DIGITS] = {1}, l1 = 1;
	for (iStand = 0; iStand < 309; iStand++)
	{
		stand[iStand] = Cstandard[308 - iStand] - '0';
	}
	int num[DIGITS] = { 0 }, l = 0;
	int count = 1;
	randBig(num, &l);
	Plus(num, stand, l, lStand, num, &l);
	for(;;count++)
	{		
		printf("%d ", count);
		print_num(num, l);
		
		if (superMR(num, l) == 1)
		{
			
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

	/*printf("please input n:");
	int num[DIGITS] = { 0 }, length = 0, n = 0, i = 0;
	scanf("%d", &n);
	for(; i < n; i++)
	{
		printf("please input big number:\n");
		scanf_num(num, &length);
		if (superMR(num, length) == 1)
			printf("������");
		else
			printf("��������");
	}
	*/

	/*int numR[DIGITS] = { 4,2,0,1 }, lR = 4, numK[DIGITS] = { 5,2,0,1 }, lK = 4;
	GreatPower(2, numR, lR, numR, & lR);
	GreatPower(2, numK, lK, numK, &lK);
	print_num(numR, lR);
	print_num(numK, lK);*/
}