#include <stdio.h>

//int main()
//{
//	int a = 7 % 2;
//	printf("%d", a);
//	return 0;
//}
////取模操作符两边必须是整数
//

//移位操作符
//<<左移操作符
//>>右移操作符
//移动的是二进制位
//二进制使用原码 反 补
int main()
{
	int a = 7;
	int b = a >> 1;
	printf("%d ", a );
	printf("%d", b);
	return 0;
}