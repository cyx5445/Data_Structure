#include "default.h"

/*
��ջ����ռ�
*/

/*��ջ����ռ�ṹ*/
typedef struct
{
	SElemType data[MAX_SIZE];
	int top1;			/*ջ1��ջ��ָ��*/
	int top2;			/*ջ2��ջ��ָ��*/
}SqDoubleStack;

/*��ʼ������ռ�ջ*/
Status InitSqDoubleStack(SqDoubleStack* S)
{
	S->top1 = -1;
	S->top2 = MAX_SIZE;
	return OK;
}

/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status Push(SqDoubleStack* S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)		/*ջ����*/
		return ERROR;
	if (stackNumber == 1)
		S->data[++S->top1] = e;		/*ջ1Ԫ����ջ*/
	else if (stackNumber == 2)
		S->data[--S->top2] = e;		/*ջ2Ԫ����ջ*/
	return OK;
}

/*����ռ�ջ��ջ*/
Status Pop(SqDoubleStack* S, SElemType* e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;			/*ջ1Ϊ��ջ*/
		*e = S->data[S->top1--];	/*ɾ����Ԫ�ظ�ֵ��e����-top1*/
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAX_SIZE)	/*ȷ��ջ2�Ƿ�Ϊ��ջ*/
			return ERROR;
		*e = S->data[S->top2++];	/*����ջ2��++Ϊ��*/
	}
	return OK;
}

/*��ӡ����ռ�ջ*/
void PrintSqDoubleStack(const SqDoubleStack S)
{
	int i, j;
	for (i = 0; i <= S.top1; i++)
	{
		printf("ջ1��S[%d] %d\n", i, S.data[i]);
	}
	for (j = MAX_SIZE - 1; j >= S.top2; j--)
	{
		printf("ջ2��S[%d] %d\n", j, S.data[j]);
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
		printf("ѡ��1.��ջ 2.��ջ 0.�˳���:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ѡ��Ҫ�����Ԫ�أ�Ԫ��ֵ ջ����");
			scanf_s("%d %d", &e, &stackNumber);
			Push(&S, e, stackNumber);
			break;
		case 2:
			printf("��ѡ��Ҫ��ջ��ջ����");
			scanf_s("%d", &stackNumber);
			Pop(&S, &e, stackNumber);
			printf("��ջԪ��Ϊ��%d\n", e);
			break;
		case 0:
			break;
		}
	} while (input);
	PrintSqDoubleStack(S);
	
	return 0;
}