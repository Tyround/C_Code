#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//学生五门课程均为百分制整数，输入gpa，求所有可能加权平均分，假定学分均为1



int minscore(int x)
{
	switch (x)
	{
	case 0:
		return 0;
	case 1:
		return 60;
	case 2:
		return 65;
	case 3:
		return 70;
	case 4:
		return 75;
	case 5:
		return 80;
	case 6:
		return 85;
	case 7:
		return 90;
	case 8:
		return 95;
	case 9:
		return 100;
		break;
	}

	printf("worng");
	return 0;
}

int maxscore(int x)
{
	switch (x)
	{
	case 0:
		return 59;
	case 1:
		return 64;
	case 2:
		return 69;
	case 3:
		return 74;
	case 4:
		return 79;
	case 5:
		return 84;
	case 6:
		return 89;
	case 7:
		return 94;
	case 8:
		return 99;
	case 9:
		return 100;
		break;
	}

	printf("worng");
	return 0;
}

int main()
{

	int a = 0, b = 0, c = 0, d = 0, e = 0;
	double gpa_list[10] = { 0,1,1.5,2,2.5,3,3.5,4,4.5,5 };
	double gpa = 0;
	
	
	scanf("%lf", &gpa);
	double sum_g = 5 * gpa;
	double sum_my = 0;

	double max = 0, min = 500;
	double max_def = 0, min_def = 0;

	
	for (a = 0; a < 10; a++)
	{
		for (b = a; b < 10; b++)
		{
			for (c = b; c < 10; c++)
			{
				for (d = c; d < 10; d++)
				{
					for (e = d; e < 10; e++)
					{
						sum_my = gpa_list[a] + gpa_list[b] + gpa_list[c] + gpa_list[d] + gpa_list[e];
						if (sum_my == sum_g)
						{
							min_def = minscore(a) + minscore(b) + minscore(c) + minscore(d) + minscore(e);
							max_def = maxscore(a) + maxscore(b) + maxscore(c) + maxscore(d) + maxscore(e);
							if (min_def < min)
								min = min_def;
							if (max_def > max)
								max = max_def;
						}
					}
				}
			}
		}
	}

	for (double i = min / 5.0; i <= max / 5.0 + 0.1; i += 0.2)
	{
		printf("%.1lf ", i);
	}


	return 0;
}