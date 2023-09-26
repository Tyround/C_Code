#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//A14 检查一条信息是否回文，使用指针

void judgeHuiWen(char message[100], int *pLength, int* pLeft)
{
	if (*pLeft == *pLength - 1)
	{
		printf("是回文数");
		return;
	}
	if (message[*pLeft] == message[*pLength - 1])
	{
		if (*pLeft == *pLength - 2)
		{
			printf("是回文数");
			return;
		}
		(*pLength)--;
		(*pLeft)++;
		judgeHuiWen(message, pLength, pLeft);
	}
	else
	{
		printf("不是回文数");
		return;
	}
}

int main()
{
	char message[100] = { 0 };
	scanf("%s", message);
	int length = strlen(message);
	int left = 0;
	int* pLength = &length, * pLeft = &left;

	judgeHuiWen(message, pLength, pLeft);

	return 0;
}



