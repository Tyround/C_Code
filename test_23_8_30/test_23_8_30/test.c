#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//ţţ�Ӽ�������һ�������������ж���������ܱ� 2 3 7 ���ļ������������������������������ܱ� 2 3 7 ����һ������������� n��
int main()
{
	int a;
	int count = 0;
	scanf("%d", &a);
	if (a % 2 == 0)
		printf("%d ", 2);
	else
		count++;
	if (a % 3 == 0)
		printf("%d ", 3);
	else
		count++;
	if (a % 7 == 0)
		printf("%d ", 7);
	else
		count++;
	if (count == 3)
		printf("n");
	return 0;
}