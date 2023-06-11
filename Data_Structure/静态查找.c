#include "default.h"

typedef struct
{
	KeyType key;	/*关键字域*/
	//其他域
} ElemType_Search;

/*顺序表结构*/
typedef struct
{
	ElemType_Search* R;	/*表基址*/
	int length;		/*表长*/
} SSTable;

int F[15] = { 0 };

/*顺序查找，a为数组，n为数组个数，key为关键字*/
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

/*顺序查找（顺序表）*/
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

/*优化顺序查找（哨兵）*/
int Sequential_Search2(SSTable ST, KeyType key)
{
	int i = ST.length;
	ST.R[0].key = key;			/*设置一个哨兵*/
	while (ST.R[i].key != key)
		--i;
	//for (i; ST.R[i].key != key; --i);
	return i;
}

/*折半查找（二分查找）*/
int Binary_Search(SSTable ST, KeyType key)
{
	int low, high, mid;
	low = 1;
	high = ST.length;
	while (low <= high)
	{
		mid = (low + high) / 2;			/*取中点，折半*/
		if (key < ST.R[mid].key)
			high = mid - 1;
		else if (key > ST.R[mid].key)
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}

/*折半查找（递归算法）*/
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

/*插值查找*/
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

//生成斐波那契数列
int Fibonacci(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

/*斐波那契查找*/
int Fibonacci_Search(SSTable ST, KeyType key)
{
	int low, high, mid, i, k;
	low = 1;
	high = ST.length;
	k = 0;
	while (ST.length > F[k] - 1)	/*计算n位斐波那契数列的位置*/
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
		printf("查找成功，目标下标为：%d\n", res);
	return 0;
}