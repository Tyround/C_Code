#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//实现两字符串相减，若第二个字符串出现多次，只减去最后一个


void minus(char str1[100], char str2[100], int l1, int l2)
{
	int i = 0, j = 0;
	int count = 1;
	for (i = l1 - 1,j = l2 - 1; i >= j; )
	{
		if (str1[i] == str2[j])
		{
			if (j > 0)
			{
				i--;
				j--;
			}
			else
			{
				int k;
				for (k = 0; k < l2; k++, i++)
				{
					str1[i] = '\0';					
				}
				for (; i < l1; i++)
				{
					str1[i - l2] = str1[i];
					str1[i] = '\0';
				}
				return;
			}			
		}
		else
		{
			i = l1 - (++count);

			j = l2 - 1;
		}		
	}
	return;
}

int main()
{
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	
	scanf("%s", &str1);
	scanf("%s", &str2);
	int l1 = strlen(str1), l2 = strlen(str2);
	minus(str1, str2, l1, l2);
	printf("%s", str1);
	return 0;
}