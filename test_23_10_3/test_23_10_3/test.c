#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr1[4] = { 1, 2, 3, 4 };
	int arr2[4] = { 2, 3, 4, 5 };
	int arr3[4] = { 3, 4, 5 ,6 };
	int* parr[3] = { arr1, arr2, arr3 };
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//使用指针数组实现二维数组