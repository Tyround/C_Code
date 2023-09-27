#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(int num[512], int copy[512], int left, int right)
{
	//这里要归并
	if (left >= right)
	{
		return;
	}
	//先递归实现拆分
	int left1 = left, right2 = right, right1 = (right - left) / 2 + left, left2 = (right - left) / 2 + left + 1;
	mergeSort(num, copy, left1, right1);
	mergeSort(num, copy, left2, right2);
	//将拆分后数重新组合
	int i = 0, j = 0, k = 0;
	for (i = left1, j = left2, k = left;!(i > right1 && j > right2); k++)
	{	
		if (i > right1)
		{
			copy[k] = num[j];			
			j++;
		}			
		else if (j > right2)
		{
			copy[k] = num[i];
			i++;
		}
		else
		{
			if (num[i] > num[j])
			{
				copy[k] = num[j];				
				j++;
			}
			else
			{
				copy[k] = num[i];
				i++;
			}
		}			
	}

	for (i = left; i <= right; i++)
	{
		num[i] = copy[i];
	}
	return;
}


int main()
{
	//从文件中读取整型数据
	int num[512] = { 0 }, copy[512] = { 0 }, i = 0;
	FILE* file = NULL;
	//传入本文件地址下文件
	file = fopen(".\\data.txt", "r");

	if (file == NULL)
	{
		exit(0);
	}

	while (!feof(file))
	{
		if (i == 512)
		{
			printf("太大了，进不来");
			exit(0);
		}
		fscanf(file, "%d", num + i);		
		i++;
	}
	fclose(file);
	file = NULL;

	int length = i;

	//归并排序排出大小
	mergeSort(num, copy, 0, length - 1);

	//打印结果
	for (i = 0; i < length; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}