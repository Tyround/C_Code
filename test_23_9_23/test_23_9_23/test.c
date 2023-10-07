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
	return (part_gpa(a) + part_gpa(b) + part_gpa(c) + part_gpa(d) + part_gpa(e));
}

int main()
{
	
	int a = 0, b = 0, c = 0, d =  0, e = 0;
	double gpa = 0;
	double num = 0;
	double gradep = 0;
	scanf("%lf", &gpa);
	if (gpa == 0)
		printf("%d ", 0);
	for (a = 0; a <= 100; a++)
	{
		if (a + 400 <= num * 5 + 0.9 || (5 * a > num * 5 + 1.1&& num!=0))
			continue;
		for (b = a; b <= 100; b++)
		{
			if (a + b + 300 <= num * 5 + 0.9 || (a + 4*b > num * 5 + 1.1&& num!=0))
				continue;
			for (c = b; c <= 100; c++)
			{
				if (a + b + c + 200 <= num * 5 + 0.9 || (a + b + 3*c> num * 5 + 1.1&& num!=0))
					continue;
				for (d = c; d <= 100; d++)
				{
					if (a + b + c + d + 100 <= num * 5 + 0.9 || (a + b + c + 2*d > num * 5 + 1.1&& num!=0))
						continue;
					for (e = d; e <= 100; e++)
					{
						if (num != 0 &&(a + b + c + d + e <= num * 5 + 0.9 || a + b + c + d + e >= num * 5 + 1.1))
							continue;
						if (gpap(a, b, c, d, e) == gpa * 5)
						{
							gradep = (a + b + c + d + e) / 5.0;							
							if (gradep > num)
							{								
								printf("%.1lf ", gradep);
								num = gradep;
							}							
						}
					}				
				}
			}
		}
	}
}