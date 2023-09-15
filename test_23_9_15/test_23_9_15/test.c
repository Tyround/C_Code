#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//����д��A6
//���һ��Y��M�µ�����

//���������ʾĳ�����ж�����
int DofM(int M,int leap)
{
	if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
		return 31;
	else if (M == 4 || M == 6 || M == 9 || M == 11)
		return 30;
	else
		return 28 + leap;
}

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
	int weekday = 6;//����1600��1��1�գ������������涨������Ϊ0
	//�����1600��Y���м�������
	int leap = (Y  - 1 - 1600) / 4 - (Y - 1 - 1600) / 100 + (Y - 1 - 1600) / 400 + 1;
	if (Y == 1600)
	{
		leap = 0;
	}
	weekday = (weekday + (Y - 1600 - leap) * 365 + leap * 366) % 7; //�������Y��1��1��������weekday+1

	//�������Y M 1�������ڼ�
	int tyl = 0;//tyl means this year leap
	if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
	{
		tyl = 1;
	}
	else
	{
		tyl = 0;
	}
	int i = 0;
	for (i = 1; i < M; i++)
	{
		weekday = weekday + DofM(i, tyl);
	}
	weekday %= 7;
	//������ά���鲢��ʼ��
	int row, col;
	char calendar[11][39] = {' '};
	for (row = 0; row < 11; row++)
	{
		for (col = 0; col < 39; col++)
		{
			calendar[row][col] = ' ';
		}
	}

	//�������ά��������������
	//�������·ݱ�ʶ
	if (M < 10)
	{
		for (row = 2; row <= 6; row++)
		{
			for (col = 14; col <= 20; col+= 2)
			{
				calendar[row][col] = '#';
				if (row > 2 && row < 6 && col > 14 && col < 20)
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}
	else
	{
		for (row = 2; row <= 6; row++)
		{
			col = 20;
			calendar[row][col] = '#';
		}
	}

	if (M == 1 || M == 11)
	{

	}
	else if (M == 2 || M == 12)
	{
		for (row = 2; row <= 6; row++)
		{
			for(col = 30; col <= 26; col += 2)
			{
				calendar[row][col] = '#';
				if (row > 2 && row < 6 && col > 30 && col < 36)
				{
					calendar[row][col] = ' ';
				}
			}
		}
	}
	//���������ˣ���commitһ��







	printf("S u n   M o n   T u e   W e d   T h u   F r i   S a t\n");
	//��ӡ��ά��������
	for (row = 0;row <11;row++)
	{
		for (col = 0; col < 39; col++)
		{
			printf("%c", calendar[row][col]);
		}
		printf("\n");
	}
	return 0;
}