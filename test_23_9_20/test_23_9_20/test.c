#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A10 100Ԫ 50Ԫ 20Ԫ 10Ԫ 5Ԫ 1Ԫ ֽ�ң���abcdef�ţ�����xԪ��Ʒ��ʹ����Ǯ�������٣�֧�������������١�


//�����������һ������֧����������0��ʾ����֧��
int full_pay(int cash[6], int value[6], int mount[6], int x, int left);

int main()
{
	int cash[6], x = 0;
	int value[6] = { 100, 50, 20, 10, 5, 1 };
	re:
	scanf("%d %d %d %d %d %d", &cash[0], &cash[1], &cash[2], & cash[3], &cash[4], &cash[5]);
	scanf("%d", &x);
	if (100 * cash[0] + 50 * cash[1] + 20 *cash[2] + 10 *cash[3] + 5 * cash[4] + cash[5] < x)
	{
		printf("���𣬹�\n");
		goto re;
	}

	else if (cash[0] < 0 || cash[1] < 0 || cash[2] < 0 || cash[3] < 0 || cash[4] < 0 || cash[5] < 0 || x < 0)
	{
		printf("��ֵ���Ϸ������������룺");
		goto re;
	}

	int mount[6] = { 0 };//����ֽ����������
	int left = x;//��������

	
	//���￼�ǲ����������
	int i = 0;
	int fp = full_pay(cash, value, mount, x, left);
	if(fp != 0)
	{
		for (i = 0; i < 6; i++)
		{
			printf("%d ", mount[i]);
		}
		printf("\n%d", fp);
	}

	//left!=0, ��ζ���޷������������������������������� :(
	//���ڿ��ǵ����������κ�����������Ҹ���100Ԫ
	// ���Ƶأ�50Ԫ�����1�ţ�20Ԫ�����4�ţ�10Ԫ�����1�ţ�5Ԫ���һ�ţ�1Ԫ���4�š�
	//�����ȿ�������Ϊ1�ŵ�
	int return_num[6] = {0,0,0,0,0,0};
	





	return 0;
}


int full_pay(int cash[6], int value[6], int mount[6], int x, int left) 
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 6; i++)
	{
		if (cash[i] >= left / value[i])
		{
			mount[i] = left / value[i];
			count += left / value[i];
			left -= value[i] * mount[i];
		}
		else
		{
			mount[i] = cash[i];
			left -= value[i] * mount[i];
		}
	}
	if (left == 0)
	{
		return count;
	}
	else
		return 0;
}