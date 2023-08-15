#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//¥Ú”°100-200÷  ˝
//int main()
//{
//	int i = 1, j = 1;
//	int count = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		for (j = 2; j*j <= i; j++)
//		{
//			if (i % j == 0)
//				goto end;
//		}
//		printf("%d ", i);
//		count++;
//	end:;
//
//	}
//	printf("\n%d", count);
//	return 0;
//}

void print_binary(int x)
{
    if (x > 9)
        print_binary(x / 10);
    
        printf("%d", x % 2);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    print_binary(n);

    return 0;
}

