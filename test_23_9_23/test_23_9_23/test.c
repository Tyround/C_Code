#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//学生五门课程均为百分制整数，输入gpa，求所有可能加权平均分，假定学分均为1

double part_gpa(int grade)
{
	if (grade < 60)
		return 0;
	else if (grade < 65)
		return 1;
	else if (grade < 70)
		return 1.5;
	else if (grade < 75)
		return 2;
	else if (grade < 80)
		return 2.5;
	else if (grade < 85)
		return 3;
	else if (grade < 90)
		return 3.5;
	else if (grade < 95)
		return 4;
	else if (grade < 100)
		return 4.5;
	else
		return 5;
}

double gpap(int a, int b, int c, int d, int e)
{
	return (part_gpa(a) + part_gpa(b) + part_gpa(c) + part_gpa(d) + part_gpa(e)) / 5.0;
}

double gpabase[500] = { -1 };

int gpacomp(double gpap, int num)
{
	int i = 0;
	for (i = 0; i <= num; i++)
	{
		if (gpabase[i] == gpap)
			return 0;
	}
	return 1;
}

//看不懂题目呢
int main()
{
	int i = 0;
	for (i = 0; i < 500; i++)
	{
		gpabase[i] = -1;
	}
	int a = 0, b = 0, c = 0, d =  0, e = 0;
	double gpa = 0;
	int num = 0;
	double gradep = 0;
	scanf("%lf", &gpa);
	for (a = 0; a <= 100; a++)
	{
		for (b = a; b <= 100; b++)
		{
			for (c = b; c <= 100; c++)
			{
				for (d = c; d <= 100; d++)
				{
					for (e = d; e <= 100; e++)
					{
						if (gpap(a, b, c, d, e) == gpa)
						{
							gradep = (a + b + c + d + e) / 5.0;
							if (gpacomp(gradep, num) == 1)
							{								
								printf("%d %d %d %d %d ", a, b, c, d, e);
								printf("%lf\n", gradep);
								gpabase[num] = gradep;
								num++;
							}							
						}
					}
				}
			}
		}
	}
}