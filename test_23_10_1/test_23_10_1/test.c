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
//	//�����������������ɵ���
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

//���Ұָ��
//1 ��ʼ��
//2 ����Խ��
//3 �ռ��ͷź�ֵNULL
//4 ���ⷵ�ؾֲ�����
//5 �����Ч��