#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//A13

int main()
{
	char arr[100] = { 0 }, copy[100] = { 0 }, output[100] = { 0 };
	scanf("%s", arr);
	int length = strlen(arr), i = 0, j = 0, k = 0, defint, m, n, p = 0, q;
	char def;
	for (i = length - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			printf("over");
			return 0;
		}
		if ((int)arr[i - 1] < (int)arr[i])
		{
			for (j = i; j < length; j++)
			{
				output[k] = arr[j];
				k++;
				if ((int)arr[j] > (int) arr[i - 1])
				{
					copy[p] = arr[j];
					p++;
				}
			}
			
			def = copy[p - 1];
		
			for(p--; p >= 0; p--)
			{
				if ((int)copy[p] < (int)def)
				{
					def = copy[p];
				}
			}
			for (q = 0; q < i - 1; q++)
				printf("%c", arr[q]);
			printf("%c", def);

			for (m = 0; m < length - i - 1; m++)
			{
				if (output[m] == def)
				{
					output[m] = arr[i - 1];
					break;
				}
			}

			
			for (m = 1; m < length - i ; m++)
			{
				for (n = 0; n < length - i - m; n++)
				{
					if ((int)output[n + 1] < (int)output[n])
					{
						def = output[n + 1];
						output[n + 1] = output[n];
						output[n] = def;
					}
				}
			}
		printf("%s", output);
				return 0;

		}
		

	}
	return 0;
}