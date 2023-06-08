#include "default.h"

/*ѭ������*/

typedef struct
{
	ElemType data[MAX_SIZE];
	int front;					/*��ͷ*/
	int rear;					/*��β*/
}SqQueue;

Status InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;
}

Status EnQueue(SqQueue* Q, ElemType e)
{
	if ((Q->rear + 1) % MAX_SIZE == Q->front)	/*�ж��Ƿ������*/
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAX_SIZE;
	return OK;
}

Status DeQueue(SqQueue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAX_SIZE;
	return OK;
}

void PrintQueue(SqQueue Q)
{
	if (Q.front == Q.rear)
		printf("��Ϊ��\n");
	if (Q.rear > Q.front)
	{
		for (int i = Q.front; i < Q.rear; i++)
		{
			printf("�±꣺%d Ԫ�أ�%d\n", i, Q.data[i]);
		}
	}
	else
	{
		for (int i = Q.rear; i < Q.front; i++)
		{
			printf("�±꣺%d Ԫ�أ�%d\n", i, Q.data[i]);
		}
	}
	
}

int main()
{
	SqQueue Q;
	InitQueue(&Q);

	int input, e, len;
	do
	{
		printf("1.��� 2.���� 3.�ӳ� 4.��ӡ 0.�˳���");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("���Ԫ�أ�");
			scanf_s("%d", &e);
			EnQueue(&Q, e);
			break;
		case 2:
			DeQueue(&Q, &e);
			printf("����Ԫ��Ϊ��%d\n", e);
			break;
		case 3:
			len = QueueLength(Q);
			printf("�ӳ�Ϊ��%d\n", len);
			break;
		case 4:
			PrintQueue(Q);
			break;
		case 0:
			break;
		default:
			break;
	}
	} while (input);
	return 0;
}