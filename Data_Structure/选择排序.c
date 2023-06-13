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

/*����Ϊ�󶥶�*/
void HeapAdjust(SqList* L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && L->r[j] < L->r[j + 1])	/*�Ƚ����������ĸ���*/
			++j;
		if (temp >= L->r[j])
			break;
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;
}

void HeapSort(SqList* L)
{
	int i;
	for (i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);
	for (i = L->length; i > 1; i--)
	{
		swap(L, 1, i);
		HeapAdjust(L, 1, i - 1);
	}
}

int main()
{
	int d[9] = { 50,10,90,30,70,40,80,60,20 };
	SqList L;
	for (int i = 0; i < 9; i++)
	{
		L.r[i + 1] = d[i];
	}
	L.length = 9;
	HeapSort(&L);

	return 0;
}