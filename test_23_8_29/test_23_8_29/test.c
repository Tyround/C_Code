#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数变成0或1。
// 如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。
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