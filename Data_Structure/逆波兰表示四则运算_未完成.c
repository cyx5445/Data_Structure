#include "default.h"

#define MAX_SIZE 100

typedef char SElemType_Char;

typedef struct
{
	SElemType_Char data[MAX_SIZE];
	int top;
}SqStack;

Status InitSqStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

Status Push(SqStack* S, SElemType_Char e)
{
	if (S->top == MAX_SIZE - 1)
		return ERROR;
	S->top++;
	S->data[S->top] = e;
	return OK;
}

Status Pop(SqStack* S, SElemType_Char* e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

int Judge(char* sign)
{
	if (sign == NULL)
		return 0;
	switch (*sign)
	{
	case '(':
		return 1;
	case ')':
		return 1;
	case '*':
		return 3;
	case '/':
		return 3;
	case '+':
		return 4;
	case '-':
		return 4;
	default:
		return 0;
	}
}

/*中缀表达式*/
Status InfixExpression(SqStack* S, char* Exp)
{
	char Exp2[MAX_SIZE];
	int i = 0;
	for (i = 0; i <= strlen(Exp); i++)
	{
		char c = Exp[i];
		if (c >= '0' && c <= '9')
			Exp2[i] = c;
		else if (c == '\0')
			break;
		else
		{
			if (Judge(&c) >= Judge(&(S->top)))
				Push(S, Exp[i]);
			else
			{
				char e[2];
				Pop(&S, &e);
				Exp2[i] = c;
			}
				
		}
	}
}



int main()
{
	SqStack S;
	InitSqStack(&S);
	char Exp[MAX_SIZE] = { 0 };
	scanf_s("%s", Exp, MAX_SIZE);
	InfixExpression(&S, &Exp);

	return 0;
}