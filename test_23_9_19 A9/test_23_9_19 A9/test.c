#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A9 ��������n�ֽ�Ϊ�����˻�

//������������i������
unsigned int prime(unsigned int i)
{
	if (i == 1)
		return 2;
	else
		i--;

	unsigned int count = 0, j = 0;
	for (j = 1; count < i;)
	{
		j += 2;
		count += test_prime(j);
	}
	return j;
}

//�����������һ�������Ƿ�������
unsigned test_prime(unsigned int j)
{
	unsigned int i = 0;
	for (i = 3; i * i <= j; i += 2)
	{
		if (j % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

//���������ֽ�Ϊ�����˻�
int main()
{
	unsigned int inte = 0;
	re:
	scanf("%u", &inte);
	printf("%u=", inte);
	int num = 1;
	int judge_1 = 0;
	for (; prime(num)<= inte; )
	{
		if (inte % prime(num) == 0)
		{
			if (judge_1 == 0)
			{
				printf("%u", prime(num));
				judge_1 = 1;
			}
			else
			{
				printf("*%u", prime(num));
			}
			inte /= prime(num);
		}
		else
		{
			num++;
		}
	}
	printf("\n");
	goto re;
	return 0;
}


//A10 100Ԫ 50Ԫ 20Ԫ 10Ԫ 5Ԫ 1Ԫ ֽ�ң���abcdef�ţ�����xԪ��Ʒ��ʹ����Ǯ�������٣�֧�������������١�

int main()
{

	return 0;
}

//ûʲôͷ��Ъ��