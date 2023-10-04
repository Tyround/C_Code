#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

struct peo
{
	int length;
	char name[20];
	char age[4];
	char id[19];
}p1;

void test(struct peo* p)
{
	strcpy(p->name, "nick");

	return;
}

void printStrPeo(struct peo* p)
{
	printf("%d %s %s %s\n",p->length, p->name, p->age, p->id);
}

int main()
{
	struct peo p2 = {18, "clara", "199", "123456" };
	p1.length = 20;
	
	test(&p1);
	
	printStrPeo(&p1);
	printStrPeo(&p2);
	return 0;
}