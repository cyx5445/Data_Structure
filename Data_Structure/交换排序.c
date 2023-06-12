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

/*��ѡ������*/
void SelectSort(SqList* L)
{
	int i, j, min;
	for (i = 1; i <= L->length; i++)
	{
		min = 1;							/*������С�±�*/
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[min] > L->r[j])
				min = j;
		}
		if (i != min)
			swap(L, i, min);
	}
}