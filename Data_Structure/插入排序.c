#include "default.h"

typedef int KeyType;

typedef struct
{
	int r[MAX_SIZE + 1];	/*从1号位置开始，0一般作哨兵或者缓冲区*/
	int length;
}SqList;

/*直接插入排序算法*/
void InsertSort(SqList* L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i] < L->r[i - 1])
		{
			L->r[0] = L->r[i];			/*设置哨兵*/
			for (j = i - 1; L->r[j] > L->r[0]; j--)
			{
				L->r[j + 1] = L->r[j];	/*记录逐个后移*/
			}
			L->r[j + 1] = L->r[0];
		}
	}
}

/*折半插入排序算法*/
void BInsertSort(SqList* L)
{
	int i, j, mid, low, high;
	for (i = 2; i <= L->length; i++)
	{
		low = 1; high = i - 1;
		L->r[0] = L->r[i];
		while (low <= high)				/*寻找插入位置high + 1*/
		{
			mid = (low + high) / 2;
			if (L->r[0] < L->r[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; j--)
		{
			L->r[j + 1] = L->r[j];
		}
		L->r[j + 1] = L->r[0];
	}
}

/*希尔排序（dk为增量）*/
void ShellSort(SqList* L, int dk)
{
	int i, j, k = 0;
	int increment = L->length;
	do
	{
		increment = increment / dk + 1;
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])
			{
				L->r[0] = L->r[i];
				for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
					L->r[j + increment] = L->r[0];
				L->r[j + increment] = L->r[0];
			}
		}
	} while (increment > 1);
}

int main()
{
	SqList L;
	int arr[] = { 0,2,1,3,4,6,9,7,5,8 };
	L.length = sizeof(arr) / sizeof(int) - 1;
	for (int i = 0; i <= L.length; i++)
	{
		L.r[i] = arr[i];
	}
	BubbleSort2(&L);
}