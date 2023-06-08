#include "default.h"

/*
ջ������ȳ�
*/



/*����ջ�ṹ���ͣ���̬��*/
typedef struct
{
	SElemType data[MAX_SIZE];
	int top;					/*����ջ��ָ��*/
	//int base;					/*ָ��ջ��Ԫ��*/
}SqStack;

/*��ʼ��ջ*/
Status InitSqStack(SqStack* S)
{
	S->top = -1;				/*��ʼ��topΪ-1*/
	return OK;
}

/*�ж�˳��ջ�Ƿ�Ϊ��*/
Status SqStackEmpty(const SqStack S)
{
	if (S.top == -1)
		return TRUE;
	return FALSE;
}

/*��˳��ջ�ĳ���*/
Status SqStackLength(const SqStack S)
{
	if (S.top == -1)
		return ERROR;
	return (S.top + 1);
}

/*���˳��ջ*/
Status ClearSqStack(SqStack* S)
{
	if (S->top != -1)
		S->top = -1;
	else
		return ERROR;
	return OK;
}

/*����˳��ջ*/
Status SqStackDestory(SqStack* S)
{
	if (S->top != -1)
	{
		//S->data
		S->top = NULL;
	}
	return OK;
}

/*˳��ջ����ջ*/
Status Push(SqStack* S, SElemType e)
{
	if (S->top == MAX_SIZE - 1)		/*ջ��*/
		return ERROR;
	S->top++;
	S->data[S->top] = e;
	return OK;
}

/*˳��ջ��ջ*/
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
	printf("���� ��ջ����ֵ��");
	scanf_s("%d", &input);
	Push(&S, input);

	return 0;
}