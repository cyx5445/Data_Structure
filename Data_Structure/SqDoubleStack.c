#include "default.h"

/*
两栈共享空间
*/

/*两栈共享空间结构*/
typedef struct
{
	SElemType data[MAX_SIZE];
	int top1;			/*栈1的栈顶指针*/
	int top2;			/*栈2的栈顶指针*/
}SqDoubleStack;

/*初始化共享空间栈*/
Status InitSqDoubleStack(SqDoubleStack* S)
{
	S->top1 = -1;
	S->top2 = MAX_SIZE;
	return OK;
}

/*插入元素e为新的栈顶元素*/
Status Push(SqDoubleStack* S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)		/*栈已满*/
		return ERROR;
	if (stackNumber == 1)
		S->data[++S->top1] = e;		/*栈1元素入栈*/
	else if (stackNumber == 2)
		S->data[--S->top2] = e;		/*栈2元素入栈*/
	return OK;
}

/*共享空间栈出栈*/
Status Pop(SqDoubleStack* S, SElemType* e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;			/*栈1为空栈*/
		*e = S->data[S->top1--];	/*删除的元素赋值给e，再-top1*/
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAX_SIZE)	/*确定栈2是否为空栈*/
			return ERROR;
		*e = S->data[S->top2++];	/*对于栈2，++为减*/
	}
	return OK;
}

/*打印共享空间栈*/
void PrintSqDoubleStack(const SqDoubleStack S)
{
	int i, j;
	for (i = 0; i <= S.top1; i++)
	{
		printf("栈1：S[%d] %d\n", i, S.data[i]);
	}
	for (j = MAX_SIZE - 1; j >= S.top2; j--)
	{
		printf("栈2：S[%d] %d\n", j, S.data[j]);
	}
}

int main()
{
	SqDoubleStack S;
	InitSqDoubleStack(&S);

	SElemType e;
	int stackNumber, input;

	do
	{
		printf("选择（1.入栈 2.出栈 0.退出）:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("请选择要插入的元素（元素值 栈）：");
			scanf_s("%d %d", &e, &stackNumber);
			Push(&S, e, stackNumber);
			break;
		case 2:
			printf("请选择要出栈（栈）：");
			scanf_s("%d", &stackNumber);
			Pop(&S, &e, stackNumber);
			printf("出栈元素为：%d\n", e);
			break;
		case 0:
			break;
		}
	} while (input);
	PrintSqDoubleStack(S);
	
	return 0;
}