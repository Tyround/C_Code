#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//指针是内存中最小单元（1byte)编号
//而口语中指针常指指针变量，即存储指针的变量
//取地址时取出第一个地址


int main()
{
	int a = 10;
	//pa是指针变量，用于存放a的地址
	int* pa = &a;
	
	return 0;
}