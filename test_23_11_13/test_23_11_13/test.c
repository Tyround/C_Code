#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//A13

int main()
{
	char arr[1000000] = { 0 };
	scanf("%s", arr);
	int length = strlen(arr), i = 0, j = 0;
	
	for (i = length - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			printf("over£¡");
			return 0;
		}
		if ((int)arr[i - 1] < (int)arr[i])
		{
			for (j = i; j < length; j++)
			{

				if (((int)arr[j] > (int)arr[i-1] && (int)arr[j + 1] <= (int)arr[i-1])|| j == length - 1)
				{
					char hh = arr[i - 1];
					arr[i - 1] = arr[j];
					arr[j] = hh;
					break;
				}
			}
			for (j = i; j <= (length + i - 1)/2; j++)
					{
						char hehh = arr[j];
						arr[j] = arr[length - 1 + i - j];
						arr[length - 1 + i - j] = hehh;
					}

			printf("%s", arr);
			break;
			
		}
	}
	return 0;
}