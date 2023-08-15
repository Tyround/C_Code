#include <stdio.h>
////二维数组在内存中连续存储
//int main() 
//{
//	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
//	int i, j = 1;
//
//	for (i = 0; i <= 2; i++)
//	{
//		for (j = 0; j <= 3; j++)
//			printf("%p\n", &arr[i][j]);
//		printf("\n");
//	}
//
//	return 0;
//}


//形参写成数组
void bubble_sort(int arr[],int sz)
{
	int j = 0;
	int i = 0;
	int x = 0;
	for (j = 0; j < sz - 1; j++) 
	{
	
		for (i = 0; i < sz - 1 - j; i++)
			{

				if (arr[i] > arr[i + 1])
				{
					x = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = x;
				}
			}
	}
	

}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	//想让数组成升序排列
	//冒泡排序算法
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	int i = 0;
		for (i = 0; i < sz; i++)
			printf("%d ", arr[i]);
	return 0;
}

//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", &arr );
//	printf("%d", ( & arr) + 1);
//	return 0;
//}