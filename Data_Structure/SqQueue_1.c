#include "D:\Project\C\Data_Structure\Data_Structure\default.c"

/*
���У��Ƚ��ȳ�
*/

/*��̬����*/
typedef struct
{
	ElemType data[MAX_SIZE];
	int front;		/*��ͷ*/
	int rear;		/*��β*/
}SqQueue;

Status InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status DestroyQueue(SqQueue* Q)
{
	if (Q->front != Q->rear)
	{
		Q->front = NULL;
	}
	return OK;
}

Status ClearQueue(SqQueue* Q)
{
	if (Q->front != Q->rear)
	{
		Q->front = 0;
		Q->rear = 0;
	}
		
	else
		return ERROR;
	return OK;
}

Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	return FALSE;
}

Status GetHead(SqQueue Q, ElemType* e)
{
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.data[Q.rear];
	return OK;
}

Status EnQueue(SqQueue* Q, ElemType e)
{
	if (Q->rear == MAX_SIZE)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear++;
	return OK;
}

Status DeQueue(SqQueue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front++;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return Q.rear - Q.front;
}

void PrintQueue(SqQueue Q)
{
	for (int i = Q.front; i <= Q.rear; i++)
	{
		printf("��%d��Ԫ�أ�%d\n", i, Q.data[i]);
	}
}

int main()
{
	SqQueue Q;

	return 0;
}