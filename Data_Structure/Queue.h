#include "default.h"

/*ѭ������*/

typedef struct
{
	ElemType data[MAX_SIZE];
	int front;					/*��ͷ*/
	int rear;					/*��β*/
}Queue;

Status InitQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

int QueueLength(Queue Q)
{
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;
}

Status EnQueue(Queue* Q, ElemType e)
{
	if ((Q->rear + 1) % MAX_SIZE == Q->front)	/*�ж��Ƿ������*/
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX_SIZE;
	return OK;
}

Status DeQueue(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAX_SIZE;
	return OK;
}

Status QueueEmpty(Queue Q)
{
	if (Q.front == Q.rear)
		return ERROR;
	return TRUE;
}