#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//ţţ���ڼĿ�ݣ����˽⵽����� 1kg ���ڵİ��𲽼� 20 Ԫ���㣬�������ְ�ÿ kg 1Ԫ���㣬���� 1kg ���ְ� 1kg���㡣
// ����Ӽ��Ļ�Ҫ���⸶��Ԫ������ţţ�ܹ�Ҫ֧�����ٿ�ݷ�
int intify(float x)//֧����������
{
	if (x > 1)
		return intify(x - 1) + 1;
	return 1;
}

int main()
{
	float x = 0.0;
	char y;
	scanf("%f %c", &x, &y);
	int count = 0;
	count += 20;
		if(x <= 1)
		
			;
		
		else
		{
			count += intify(x - 1);
		}
			
	if (y == 'y')
		count += 5;
	printf("%d", count);

	return 0;
}