#define _CRT_SECURE_NO_WARNINGS 1


int main()
{
	(*(void (*)())0)();//调用0处存储的函数
	void (*signal(int, void (*)(int)))(int);//定义函数
	return 0;
}