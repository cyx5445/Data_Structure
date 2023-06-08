#include "default.h"

/*
栈：后进先出
*/



/*定义栈结构类型（静态）*/
typedef struct
{
	SElemType data[MAX_SIZE];
	int top;					/*用于栈顶指针*/
	//int base;					/*指向栈底元素*/
}SqStack;

/*初始化栈*/
Status InitSqStack(SqStack* S)
{
	S->top = -1;				/*初始化top为-1*/
	return OK;
}

/*判断顺序栈是否为空*/
Status SqStackEmpty(const SqStack S)
{
	if (S.top == -1)
		return TRUE;
	return FALSE;
}

/*求顺序栈的长度*/
Status SqStackLength(const SqStack S)
{
	if (S.top == -1)
		return ERROR;
	return (S.top + 1);
}

/*清空顺序栈*/
Status ClearSqStack(SqStack* S)
{
	if (S->top != -1)
		S->top = -1;
	else
		return ERROR;
	return OK;
}

/*销毁顺序栈*/
Status SqStackDestory(SqStack* S)
{
	if (S->top != -1)
	{
		//S->data
		S->top = NULL;
	}
	return OK;
}

/*顺序栈的入栈*/
Status Push(SqStack* S, SElemType e)
{
	if (S->top == MAX_SIZE - 1)		/*栈满*/
		return ERROR;
	S->top++;
	S->data[S->top] = e;
	return OK;
}

/*顺序栈出栈*/
Status Pop(SqStack* S, SElemType* e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

int main()
{
	SqStack S;
	InitSqStack(&S);

	int input;
	printf("输入 入栈的数值：");
	scanf_s("%d", &input);
	Push(&S, input);

	return 0;
}