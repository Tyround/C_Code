#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////A 5
////����һ��������
//void print_triangle(int i)
//{
//	int blank, j, k;
//	for (j = 0; j < i; j++)
//	{
//		for (blank = 0; blank < i - j - 1; blank++)
//		{
//			printf(" ");
//		}
//		for (k = 0; k < j + 1; k++)
//		{
//			printf("%d ", j + 1);
//		}
//		printf("\n");
//	}
//
//	for (j = i - 1; j > 0; j--)
//	{
//		for (blank = 0; blank < i - j ; blank++)
//		{
//			printf(" ");
//		}
//		for (k = 0; k < j; k++)
//		{
//			printf("%d ", j);
//		}
//		printf("\n");
//	}
//
//
//
//}
//
//int main()
//{
//	int i = 0;
//	//goto ���к��ģ�
//	re: scanf("%d", &i);
//	if (i > 0 && i < 10)
//	{
//		print_triangle(i);
//	}
//	else {
//		printf("�������ݷǷ������������룺");
//		goto re;
//	}
//	return 0;
//}


//��΢д��A6
//���һ��Y��M�µ�����
int main()
{
	
	int Y, M;
	illegal:
	scanf("%d %d", &Y, &M);
	if (Y >= 1600 && Y <= 2100 && M >= 0 && M <= 12)
		;
	else
	{
		printf("�������ݷǷ������������룺");
		goto illegal;
	}
	//�����������һ��һ�����ڼ�
	int weekday = 5;//����1600��1��1�գ���������
	//�����1600��Y���м�������
	int leap = (Y - 1600) / 4 - (Y - 1600) / 100 + (Y - 1600) / 400 + 1;
	if (Y == 1600)
	{
		leap = 0;
	}
	weekday = (weekday + (Y - 1600 - leap) * 365 + leap * 366) % 7; //�������Y��1��1��������weekday+1
	//�������Y M 1�������ڼ�
	//������д��Ъ��
	








	printf("S u n   M o n   T u e   W e d   T h u   F r i   S a t\n\n");
	return 0;
}