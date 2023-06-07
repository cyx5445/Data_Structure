#include "D:\Project\C\Data_Structure\Data_Structure\default.c"

/*
递归：包含自己，自己定义自己的对象
*/

/*计算斐波那契数列*/
int Fibonacci(int n)
{
	int count = 0;
	if (n == 1)
	{
		return 1;
		++count;
	}
	else if (n <= 0)
	{
		return 0;
		++count;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	int n, res;
	scanf_s("%d", &n);
	res = Fibonacci(n);
	printf("%d\n", res);
	return 0;
}