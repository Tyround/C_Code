#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////ʵ�ֵ���洢�ַ���
//void diverse(char* arr)
//{
//	int i = 0;
//	for (i = 0; 1; i++)
//	{
//		if (*(arr + i) == '\0')
//			break;
//	}
//
//	char x = ' ';
//	x = *(arr + i - 1);
//	int j = 0;
//	if(i>1)
//	for (j = i-2; j >=0; j--)
//	{
//		*(arr+j+1) = *(arr + j);
//		
//	}
//	*arr = x;
//	if (i > 1)
//		diverse(arr + 1);
//		
//		
//
//}
//
//int main()
//{
//	char arr[] = "abcdefghijkl";
//	diverse(arr);
//
//	
//		printf("%s", arr);
//	return 0;
//}


////����ʮ������ĳ����λ֮��
//
//int sum_ten(int x)
//{
//	if (x >= 10)
//		return (x % 10) + sum_ten(x / 10);
//
//	return x;
//}
//
//int main()
//{
//	int i = 121345;
//	printf("%d", sum_ten(i));
//	return 0;
//}


//n��k�η�

int squar(int x, int k)
{
	if (k > 1)
		return squar(x, k - 1) * x;
	else
		return x;
}

int main()
{
	int x = 0;
	int k = 1;
	scanf("%d %d", &x, &k);
	printf("%d", squar(x, k));
	return 0;
}