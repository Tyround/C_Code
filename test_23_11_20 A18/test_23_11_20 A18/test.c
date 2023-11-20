
#define DIGITS 1024

#include <stdio.h>
#include <string.h>

void compress(void)
{
	char receive[DIGITS] = { 0 };

	printf("please input filename to compress");
	char fileName[50] = { 0 };
	if (scanf("%s", fileName) == -1)
		printf("no input");
	FILE* fp = fopen(fileName, "r");

	char store[DIGITS] = { 0 };
	fscanf(fp, "%s", store);
	fclose(fp);

	int times = 0, j = 0;
	char def = 0;

	strcpy(receive, fileName);
	for (; receive[j] != 0; j++)
		;
	j++;

	for (int i = 0; store[i] != 0; i++)
	{
		if (receive[j + 1] != store[i] || receive[j] >= '8')
		{
			j += 2;
			receive[j] = '1';
			receive[j + 1] = store[i];
			def = store[i];
		}
		else
		{
			receive[j]++;
		}
	}


	//这里需要翻译成二进制
	fp = fopen("data.bin", "w");




	fprint(fp, "%s", receive);
	int n = 0;
	for (n = 0; receive[n] != 0; n++)
		;
	n++;
	fprint(fp, " %s", receive + n);

	fclose(fp);

	return;
}

void output_comp(const char arr[])
{
	FILE* fp = fopen(".data.bin", "a");
	for (int j = 0; arr[j] != 0; j += 2)
	{
		;//wait
	}
}

void uncompress(void)
{
	printf("please input filename to uncompress");
	char filename[DIGITS] = { 0 };
	scanf("%s", filename);
	FILE* fp = fopen(filename, "r");
	fscanf(fp, "%s", )
}

int main()
{
	char input[DIGITS] = { 0 };

	return 0;
}