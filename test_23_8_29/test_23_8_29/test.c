#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//С����ϲ�����֣�����ϲ��0��1�������ڵõ���һ���������ÿλ�������0��1��
// ���ĳһλ���������Ͱ������1�������ż������ô�Ͱ������0������ش������õ������Ƕ��١�
int times(int x, int count)
{
	if (count == 0)
		return 1;
	int y = 1;
	if (count > 1)
	{
		y = times(x,count - 1);
	}
		y *= x;
		return y;
}
int main()
{
	int x = 0;
	int dest = 0;
	int count = 0;
	scanf("%d", &x);
	

	for (; x>9; x /=10, count++)
	{
		if (x % 2 == 1)
			dest = dest + times(10, count);
		
	}
	if (x % 2 == 1)
	dest = dest + 1 * times(10, count);
	printf("%d", dest);
	return 0;
  }