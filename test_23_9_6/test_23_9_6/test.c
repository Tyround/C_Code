#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。
//
//例如：给定一个10进制数56，将56加65（即把56从右向左读），得到121是一个回文数。
//又如：对于10进制数87：
//STEP1：87 + 78 = 165                  STEP2：165 + 561 = 726
//
//STEP3：726 + 627 = 1353                STEP4：1353 + 3531 = 4884
//
//在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。
//
//写一个程序，给定一个N（2 <= N <= 10或N = 16）进制数M（100位之内），求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible!”
//进制N > 10时，使用大写'A'字母表示10，'B'表示11, ..., 'E'表示15


int pow(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else
		return x * pow(x, n - 1);
}

int reverse(int M)//生成反序数(十进制)
{
	int i = 0;
	int arr[100] = { 0 };
	int def = 0;
	for( ; M / 10 != 0;i++)
	{
		arr[i] = M % 10;
		M /= 10;
		
	}
	arr[i] = M % 10;
	int j;
	for (j = 0; j <= i; j++)
	{
		def += pow(10, i - j)*arr[j];

	}
	return def;
}

int main()
{
	int N = 10, M = 0;
	scanf("%d %d", &N, &M);
	int tem = 0;//存储反序数
	int num[100] = { 0 };
	//先考虑十进制
	if (10 == N)
	{
		tem = reverse(M);


	}

	printf("%d", tem);
	return 0;
}

//今天先写到生成反序，剩下的明天写