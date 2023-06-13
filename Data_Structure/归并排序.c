#include "default.h"

typedef int KeyType;

typedef struct
{
	int r[MAX_SIZE + 1];	/*��1��λ�ÿ�ʼ��0һ�����ڱ����߻�����*/
	int length;
}SqList;

void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];
	}
}

void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAX_SIZE + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);		/*�ݹ齫SR[s...m]�鲢Ϊ�����TR2[s...m]*/
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);	/*��TR2[s...m]��TR2[m+1...t]�鲢��TR1[s...t]*/
	}
}

void MergeSort(SqList* L)
{
	MSort(L->r, L->r, 1, L->length);
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
	MergeSort(&L);

	return 0;
}