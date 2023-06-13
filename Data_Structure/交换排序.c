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

int Partition(SqList* L, int low, int high)
{
	int pivotkey;
	/*改进算法(三数取中法)*/
	int m = low + (high - low) / 2;	/*取中间元素下标*/
	if (L->r[low] > L->r[high])
		swap(L, low, high);
	if (L->r[m] > L->r[high])
		swap(L, high, m);
	if (L->r[m] > L->r[low])
		swap(L, m, low);
	pivotkey = L->r[low];
	L->r[0] = pivotkey;

	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		L->r[low] = L->r[high];
		//swap(L, low, high);		/*将比枢轴记录小的记录交换到较低端*/
		while (low < high && L->r[low] <= pivotkey)
			low++;
		L->r[high] = L->r[low];
		//swap(L, low, high);
	}
	L->r[low] = L->r[0];
	return low;
}

void QSort(SqList* L, int low, int high)
{
	int pivot;		/*枢轴*/
	if (low < high)
	{
		pivot = Partition(L, low, high);
		QSort(L, low, pivot - 1);			/*对低子表递归排序*/
		QSort(L, pivot + 1, high);			/*对高子表递归排序*/
	}
}

/*快速排序*/
void QuickSort(SqList* L)
{
	My_QSort(L, 1, L->length);
}

//int main()
//{
//	int d[9] = { 50,10,90,30,70,40,80,60,20 };
//	SqList L;
//	for (int i = 0; i < 9; i++)
//	{
//		L.r[i + 1] = d[i];
//	}
//	L.length = 9;
//	QuickSort(&L);
//
//	return 0;
//}