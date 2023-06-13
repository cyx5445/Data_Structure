#include "default.h"

typedef int KeyType;

typedef struct
{
	int r[MAX_SIZE + 1];	/*��1��λ�ÿ�ʼ��0һ�����ڱ����߻�����*/
	int length;
}SqList;

/*����L������r���±�Ϊi��j��ֵ*/
void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/*����ð�����򣨴�С����*/
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

/*ð������*/
void BubbleSort(SqList* L)
{
	int i, j;
	for (i = 0; i < L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[j + 1])		/*��ǰ�ߴ��ں���*/
				swap(L, j, j + 1);			/*��������λ��*/
		}
	}
}

/*ð������Ľ��㷨*/
void BubbleSort2(SqList* L)
{
	int i, j;
	Status flag = TRUE;						/*��flag�������*/
	for (i = 0; i < L->length && flag; i++)	/*��flagΪTRUE�������ݽ����������˳�ѭ��*/
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
	/*�Ľ��㷨(����ȡ�з�)*/
	int m = low + (high - low) / 2;	/*ȡ�м�Ԫ���±�*/
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
		//swap(L, low, high);		/*���������¼С�ļ�¼�������ϵͶ�*/
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
	int pivot;		/*����*/
	if (low < high)
	{
		pivot = Partition(L, low, high);
		QSort(L, low, pivot - 1);			/*�Ե��ӱ�ݹ�����*/
		QSort(L, pivot + 1, high);			/*�Ը��ӱ�ݹ�����*/
	}
}

/*��������*/
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