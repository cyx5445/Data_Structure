#include "default.h"

/*链式队列*/

/*结点结构*/
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, *QueuePtr;

/*链表结构*/
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitLinkQueue(LinkQueue* Q)
{
	Q->front = (QueuePtr)malloc(sizeof(QNode));
	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front || !Q->rear)
		return OVERFLOW;
	Q->front->next = NULL;
	Q->rear->next = NULL;
	return OK;
}

Status DestroyLinkQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		QueuePtr p = Q->front->next;
		free(Q->front);
		Q->front = p;
	}
	return OK;
}

Status EnLinkQueue(LinkQueue* Q, ElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
		return OVERFLOW;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

Status DeLinkQueue(LinkQueue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
		return ERROR;
	QueuePtr p;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

Status GetHead(LinkQueue Q, ElemType* e)
{
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p = Q.front->next;
	*e = p->data;
	return OK;
}
