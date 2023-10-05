#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



char judgeTri(long long int a, long long int b, long long int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 'e';
	}


	if ( b - a < c && c - a < b && a - c < b)
	{

	}

	else
	{
		return 'e';
	}

	if (a == b && b == c)
	{
		return 'b';
	}

	else if (a == b || b == c || c == a)
	{
		return 'y';
	}
	else
	{

	}



	if (a * a == c * c - b * b || a * a - b * b == c * c || a * a == b * b - c * c)
	{
		return 'z';

	}

	

	return 'p';
}


int main()
{
	long long int a = 0, b = 0, c = 0;
	int n = 0;
	char printChar[2048] = { '\0' };
	scanf("%d", &n);
	int i = 0;
	for (; i < n; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		printChar[i] = judgeTri(a, b, c);
	}
	printChar[i] = '\0';

	for (i = 0; i < n; i++)
	{
		if (printChar[i] == 'e')
			printf("error\n");
		else if (printChar[i] == 'b')
			printf("dengbian\n");
		else if (printChar[i] == 'y')
			printf("dengyao\n");
		else if (printChar[i] == 'z')
			printf("zhijao\n");
		else if (printChar[i] == 'p')
			printf("putong\n");
		else
		{

		}


	}

	return 0;
}