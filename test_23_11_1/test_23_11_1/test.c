#define _CRT_SECURE_NO_WARNINGS 1


int main()
{
	(*(void (*)())0)();//����0���洢�ĺ���
	void (*signal(int, void (*)(int)))(int);//���庯��
	return 0;
}