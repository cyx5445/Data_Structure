#include "default.h"

typedef int KeyType;

typedef struct
{
	int r[MAX_SIZE + 1];	/*从1号位置开始，0一般作哨兵或者缓冲区*/
	int length;
}SqList;

/*交换L中数组r的下标为i和j的值*/
void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*初级冒泡排序（从小到大）*/
void BubbleSort0(SqList* L)
{
	int i, j;
	for (i = 0; i < L->length; i++)
	{
		for (j = 0; j < L->length; j++)
		{
			if (L->r[i] > L->r[j])
				swap(L, i, j);
		}
	}
}

/*冒泡排序*/
void BubbleSort(SqList* L)
{
	int i, j;
	for (i = 0; i < L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[j + 1])		/*若前者大于后者*/
				swap(L, j, j + 1);			/*交换相邻位置*/
		}
	}
}

/*冒泡排序改进算法*/
void BubbleSort2(SqList* L)
{
	int i, j;
	Status flag = TRUE;						/*用flag来做标记*/
	for (i = 0; i < L->length && flag; i++)	/*若flag为TRUE则有数据交换，否则退出循环*/
	{
		flag = FALSE;
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
				flag = TRUE;
			}
		}
	}
}

/*简单选择排序*/
void SelectSort(SqList* L)
{
	int i, j, min;
	for (i = 1; i <= L->length; i++)
	{
		min = 1;							/*定义最小下标*/
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[min] > L->r[j])
				min = j;
		}
		if (i != min)
			swap(L, i, min);
	}
}