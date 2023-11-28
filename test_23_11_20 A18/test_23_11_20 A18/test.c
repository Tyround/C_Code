
#define DIGITS 1024
typedef unsigned char u8;
#include <stdio.h>
#include <string.h>

void get_from_int(unsigned long long* a, int st, u8* b)
{
	if (st < 8)
		printf("wrong in gfi");

	unsigned long long compare = 255;
	unsigned long long del = ~(unsigned long long)0;
	del >>= (71 - st);
	del >>= 1;
	compare = (compare << (st - 8))&(*a);
	*b = compare >> (st - 8);
	*a &= del;
	*a |= (unsigned long long)1 << (st - 8);
	return;
}

void compress(void)
{

	printf("please input filename to compress:");
	char fileName[50] = { 0 };
	if (scanf("%s", fileName) == -1)
		printf("no input");
	FILE* fp = fopen(fileName, "r");
	FILE* fpw = fopen("data.bin", "wb");

	//这里输入文件名，不压缩，结尾赋值254
	fwrite(fileName,strlen(fileName), 1, fpw);
	u8 full = 254;//full = 0b11111110
	fwrite(&full, 1, 1, fpw);
	
	u8 read = 0;
	int single = 0;//记录上一次存储是否为单个字符
	u8 times = 7;//出现次数,0-7
	u8 asc = full;//对应asc码
	unsigned long long store = 1;
	int st = 0;
	u8 input= 0;//写入时存储空间
	for(;1 ;)
	{
		read = fgetc(fp);
		if (read != asc)
		{
			if(asc != full)//执行写入程序
			{
				if(times != 0)
				{
					if (single == 1)
					{						
						store <<= 3;
						st += 3;
						single = 0;
					}
					store <<= 3;
					st += 3;
					store += times;
					store <<= 8;
					st += 8;
					store += (unsigned int)asc;
				}

				else//times ==0
				{
					if (single != 1)
					{
						store <<= 3;
						st += 3;
						single = 1;
					}
					store <<= 8;
					st += 8;
					store += (unsigned int)asc;
				}
			}
			
			
			times = 0;
			asc = read;
			

		}
		else//read==asc
		{
			if (times == 7)
			{
				if (single == 1)
				{
					store <<= 3;
					st += 3;
					single = 0;
				}
				store <<= 3;
				st += 3;
				store += times;
				store <<= 8;
				st += 8;
				store += (unsigned int)asc;
				times = 0;
				asc = read;
			}
			else
			{
				times++;
			}
		}

		//input
		while (st >= 8)
		{
			get_from_int(&store, st, &input);
			st -= 8;
			fwrite(&input, 1, 1, fpw);
		}

		//exit
		if(read == 255)
			break;
	}
	//在结尾补完一字节
	if (st != 0) 
	{
		store <<= (8 - st);
		
		st += (8 - st);
		while (st >= 8)
		{
			get_from_int(&store, st, &input);
			st -= 8;
			fwrite(&input, 1, 1, fpw);
		}

		
	}
	if (store != 1)
		printf("wrong in store");


	//end
	fclose(fp);
	fclose(fpw);
	fp = NULL;
	fpw = NULL;
	return;
}

void get_from_int_plus(unsigned long long* a, int st, u8* b, int num)
{
	if (st < num)
		printf("wrong in gfip");

	unsigned long long compare = 1;
	for (int i = 1; i < num; i++)
	{
		compare <<= 1;
		compare += 1;
	}
	unsigned long long del = ~(unsigned long long)0;
	del >>= (63 + num - st);
	del >>= 1;
	compare = (compare << (st - num)) & (*a);
	*b = compare >> (st - num);
	*a &= del;
	*a |= (unsigned long long)1 << (st - num);
	return;
}
void uncompress(void)
{
	printf("please input filename to uncompress:");
	char uncompress_name[DIGITS] = { 0 };
	scanf("%s", uncompress_name);
	FILE* fpr = fopen(uncompress_name, "rb");
	char fileName[20] = { 0 };
	u8 trans = 0;
	for(int i = 0;1;i++)
	{
		fread(&trans, 1, 1, fpr);
		if (trans == 254)
			break;
		fileName[i] = trans;
	}
	//打开解压出的文件名（其实没解压
	FILE* fpw = fopen(fileName, "w");


	//现在将文件中二进制值提出来并翻译
	u8 times = 0;//0-7
	u8 asc = 0;//需要的ascii
	int st = 0;//store中有效位数
	int state = 0;//0表示未读取数字与字符；1表示已读取非1数字，查找字符；2表示已读取数字1，查找字符或终结
	int wtf = 0;//这个表示读取1后是否读取了字符，优化效果不大
	unsigned long long store = 1;
	for (; feof(fpr) == 0;)
	{
		int pause = 9999;
		fread(&trans, 1, 1, fpr);
		if (pause == ftell(fpr))
			break;
		else
			pause = ftell(fpr);
		printf("%d\n", ftell(fpr));
		if (feof(fpr))
			break;
		store <<= 8;
		store += trans;
		st += 8;
		

		while (st >= 8)
		{
			if (state == 0)
			{
				get_from_int_plus(&store, st, &times, 3);
				st -= 3;
				if (times == 0)
				{
					state = 2;
				}
				else
				{
					state = 1;
				}
			}
			else if (state == 1)
			{
				get_from_int_plus(&store, st, &asc, 8);
				st -= 8;
				for (int i = times; i >= 0; i--)
				{
					fputc(asc, fpw);
				}
				state = 0;
			}
			else//state ==2
			{
				if(wtf == 0)
				{
					get_from_int_plus(&store, st, &asc, 8);
					st -= 8;					
					fputc(asc, fpw);
					wtf = 1;
				}
				else
				{
					get_from_int_plus(&store, st, &times, 3);
					st -= 3;
					if (times == 0)
					{
						state = 0;
					}
					else
					{
						u8 def = 0;
						get_from_int_plus(&store, st, &def, 5);
						st -= 5;
						asc = (times << 5) + def;
						fputc(asc, fpw);
					}
				}
			}
		}

	}

	fclose(fpr);
	fpr = NULL;
	fclose(fpw);
	fpw = NULL;
	return;
}

int main()
{
	printf("input 1 to compress, other nums to uncompress:");
	int n = 0;
	scanf("%d", &n);
	if (n == 1)
		compress();
	else
		uncompress();

	return 0;
}