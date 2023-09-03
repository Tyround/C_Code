#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//小乐乐学校教学楼的电梯前排了很多人，他的前面有n个人在等电梯。电梯每次可以乘坐12人，每次上下需要的时间为4分钟（上需要2分钟，下需要2分钟）。
//请帮助小乐乐计算还需要多少分钟才能乘电梯到达楼上。（假设最初电梯在1层）

int main()
{
	int n;
	scanf("%d", &n);
	int time = 0;
	time += n / 12 * 4;
	
	time += 2;
	printf("%d", time);
	return 0;
}