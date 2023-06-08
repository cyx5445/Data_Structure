#include "default.h"

/*
Õ»µÄÁ´Ê½´æ´¢£ºÁ´Õ»
*/

/*Á´Õ»½á¹¹*/
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, *LinkStackPtr;

typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitLinkStack(LinkStack* S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	S->top->next = NULL;
	S->count = 0;
	return OK;
}

Status LinkStackEmpty(LinkStack S)
{
	if (S.top->next == NULL)
		return TRUE;
	return FALSE;
}

Status Push(LinkStack* S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}

Status Pop(LinkStack* S, SElemType* e)
{
	LinkStackPtr p;
	if (S->count == 0)
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}

Status GetTopElem(LinkStack S, SElemType* e)
{
	if (S.count == 0)
		return ERROR;
	*e = S.top->data;
	return OK;
}

int main()
{
	LinkStack S;
	InitLinkStack(&S);

	int e;
	scanf_s("%d", &e);
	Push(&S, e);

	return 0;
}