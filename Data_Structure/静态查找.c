#include "default.h"

typedef struct
{
	KeyType key;	/*�ؼ�����*/
	//������
} ElemType_Search;

/*˳���ṹ*/
typedef struct
{
	ElemType_Search* R;	/*���ַ*/
	int length;		/*��*/
} SSTable;

int F[15] = { 0 };

/*˳����ң�aΪ���飬nΪ���������keyΪ�ؼ���*/
int Sequential_Search(int* a, int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}

/*˳����ң�˳���*/
int Search_Seq(SSTable ST, KeyType key)
{
	int i;
	for (i = ST.length; i >= 1; i--)
	{
		if (ST.R[i].key == key)
			return i;
	}
	return 0;
}

/*�Ż�˳����ң��ڱ���*/
int Sequential_Search2(SSTable ST, KeyType key)
{
	int i = ST.length;
	ST.R[0].key = key;			/*����һ���ڱ�*/
	while (ST.R[i].key != key)
		--i;
	//for (i; ST.R[i].key != key; --i);
	return i;
}

/*�۰���ң����ֲ��ң�*/
int Binary_Search(SSTable ST, KeyType key)
{
	int low, high, mid;
	low = 1;
	high = ST.length;
	while (low <= high)
	{
		mid = (low + high) / 2;			/*ȡ�е㣬�۰�*/
		if (key < ST.R[mid].key)
			high = mid - 1;
		else if (key > ST.R[mid].key)
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}

/*�۰���ң��ݹ��㷨��*/
int Binary_Search2(SSTable ST, KeyType key, int low, int high)
{
	if (low > high)
		return 0;
	int mid = (high + low) / 2;
	if (key == ST.R[mid].key)
		return mid;
	else if (key < ST.R[mid].key)
	{
		high = mid - 1;
		Binary_Search2(ST, key, low, high);
	}
	else {
		low = mid + 1;
		Binary_Search2(ST, key, low, high);
	}
		
}

/*��ֵ����*/
int Interpolation_Search(SSTable ST, KeyType key)
{
	int low, high, mid;
	low = 1;
	high = ST.length;
	while (low <= high)
	{
		mid = (low + (high - low) * (key - ST.R[low].key) / (ST.R[high].key - ST.R[low].key));
		if (key < ST.R[mid].key)
			high = mid - 1;
		else if (key > ST.R[mid].key)
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}

//����쳲���������
int Fibonacci(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

/*쳲���������*/
int Fibonacci_Search(SSTable ST, KeyType key)
{
	int low, high, mid, i, k;
	low = 1;
	high = ST.length;
	k = 0;
	while (ST.length > F[k] - 1)	/*����nλ쳲��������е�λ��*/
		k++;
	for (i = ST.length; i < F[k]; i++)
		ST.R[i].key = ST.R[ST.length].key;
	while (low <= high)
	{
		mid = low + F[k - 1] - 1;
		if (key < ST.R[mid].key)
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (key > ST.R[mid].key)
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= ST.length)
				return mid;
			else
				return ST.length;
		}
	}
	return 0;
}



int main()
{
	int arr[] = { 0,1,16,24,35,47,59,62,73,88,99 };
	int res;

	SSTable ST;
	ST.R = (ElemType_Search*)malloc(sizeof(KeyType));
	ST.R = arr;
	ST.length = 11;

	for (int i = 0; i < 15; i++)
		F[i] = Fibonacci(i);
	
	res = Interpolation_Search(ST, 16);

	
	if (res != 0)
		printf("���ҳɹ���Ŀ���±�Ϊ��%d\n", res);
	return 0;
}