#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//
//int main()
//{
//	int* p = test();
//	//变量生命结束，不可调用
//	return 0;
//}


int main()
{
	int* p = NULL;
	if (p != NULL) // if(p)
	{
		p = 100;
	}
	return 0;
}

//规避野指针
//1 初始化
//2 避免越界
//3 空间释放后赋值NULL
//4 避免返回局部变量
//5 检查有效性