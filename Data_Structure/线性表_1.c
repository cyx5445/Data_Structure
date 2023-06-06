#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0			/*����(0)*/
#define INFEASIBLE -1	/*������(-1)*/
#define MAX_SIZE 100	/*��ʼ����ռ䣨��̬���䣩*/

/*
���Ա�򵥲���
������				˵����
1.InitList			��ʼ�����Ա�
2.DestoryList		�������Ա�
3.ClearList			�������Ա�
4.ListEmpty			�ж��Ƿ�Ϊ�ձ�
5.ListLength		�������Ա�Ԫ�ظ���
6.GetElem			ȡ���Ա���ָ��Ԫ��
7.LocateElem		���Ҷ�λָ��Ԫ��
8.PriorElem			����ָ��Ԫ��ǰ��
9.NextElem			����ָ��Ԫ�غ��
10.ListInsert		�����Ա��в���ָ��Ԫ��
11.ListDelete		ɾ��ָ��Ԫ��
12.ListTraverse		����Ԫ��
*/

typedef int ElemType;			/*Ԫ������(int)*/
typedef int Status;				/*��������(int)*/

typedef struct
{
	//ElemType data[MAX_SIZE];	/*���飺����Ԫ��*/
	ElemType* data;				/*��̬���䣺(ElemType*)malloc(sizeof(ElemType)*MAX_SIZE)*/
	int length;					/*���Ա���*/
	int capacity;				/*��ǰ���Ա�����*/
}SqList;						/*˳�������*/

void Menu()
{
	printf("**************   1.InitList     **************\n");
	printf("**************   2.DestoryList  **************\n");
	printf("**************   3.ClearList    **************\n");
	printf("**************   4.ListEmpty    **************\n");
	printf("**************   5.ListLength   **************\n");
	printf("**************   6.GetElem      **************\n");
	printf("**************   7.LocateElem   **************\n");
	printf("**************   8.PriorElem    **************\n");
	printf("**************   9.NextElem     **************\n");
	printf("**************   10.ListInsert  **************\n");
	printf("**************   11.ListDelete  **************\n");
	printf("**************   12.ListTraverse**************\n");
	printf("**************   0.exit         **************\n");
}

Status InitList(SqList* L)										/*����һ���ձ�*/
{
	L->length = 0;												/*�ձ���Ϊ0*/
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);	/*���䶯̬�ڴ�*/
	if (L->data == NULL)										/*�쳣����*/
	{
		printf("%s\n", strerror(errno));
	}
	printf("��ʼ���ɹ���\n");
	return OK;
}

void DestoryList(SqList* L)
{
	if (L->data)
	{
		free(L->data);					/*�ͷ��ڴ�*/
		L->data = NULL;
		printf("���ٳɹ���\n");
	}
	else
	{
		printf("���Ա�����\n");
	}
	
}

void ClearList(SqList* L)
{
	assert(L);
	L->length = 0;						/*�����Ա�������Ϊ0*/
	printf("���óɹ���\n");
}

Status ListEmpty(const SqList* L)
{
	if (L->length == 0)
	{
		printf("Ϊ�ձ�\n");
		return 1;
	}
	else
	{
		printf("�ǿձ�\n");
		return 0;
	}
}

Status ListLength(const SqList* L)
{
	assert(L);
	return L->length;
}

Status GetElem(const SqList* L,int i, ElemType* e)
{
	assert(L);
	if (i < 1 || i > L->length)			/*�ж�λ���Ƿ����*/
		return ERROR;
	*e = L->data[i - 1];				/*��i-1�ĵ�Ԫ�����i������*/
	return OK;
}

Status LocateElem(const SqList* L, int i, ElemType* e)
{
	assert(L);
	for (int j = 0; j < L->length; j++)
	{
		if (L->data[j] == i)
		{
			*e = j;
			return OK;
		}
	}
	return FALSE;
}

Status ListInsert(SqList* L, int i, ElemType e)
{
	assert(L);
	if (i < L->length || i > L->length + 1)
	{
		printf("����ʧ�ܣ�\n");
		return ERROR;
	}
	if (i <= L->length)
	{
		for (int k = L->length - 1; k >= i - 1; k--)
			L->data[k + 1] = L->data[k];				/*�������м䣬Ԫ�����κ���*/
	}
	L->data[i - 1] = e;

	L->length++;
	printf("����ɹ���\n");
	return OK;
}

Status ListDelete(SqList* L, int pos)
{
	assert(L);
	if (pos > L->length || pos < 1)
		return ERROR;
	if (pos < L->length)
	{
		for (int k = pos; k < L->length; k++)		/*����ǰ��Ԫ��*/
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

/*���򼯺ϲ�*/
//void MergeList(SqList La, SqList Lb, SqList* Lc)
//{
//	ElemType pa, pb, pc, pa_last, pb_last;
//	pa = *(La.data);
//	pb = *(Lb.data);
//	Lc->length = La.length + Lb.length;
//	Lc->data = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);
//	pc = *(Lc->data);
//	
//}

int main()
{
	int i, res, e, Len, pos;
	int input = 0;
	SqList L;
	do
	{
		Menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			InitList(&L);
			break;
		case 2:
			DestoryList(&L);
			break;
		case 3:
			ClearList(&L);
			break;
		case 4:
			ListEmpty(&L);
			break;
		case 5:
			Len = ListLength(&L);
			printf("���Ա���Ϊ��%d\n", Len);
			break;
		case 6:
			printf("������Ҫȡ�ڼ���ֵ��");
			scanf_s("%d", &i);
			GetElem(&L, i, &e);
			printf("ֵΪ��%d\n", e);
			break;
		case 7:
			printf("������Ҫ���ҵ�ֵ��");
			scanf_s("%d", &i);
			res = LocateElem(&L, i, &e);
			if (res == 1)
				printf("����ֵ�±�Ϊ��%d\n", e);
			else
				printf("�����ڸ�Ԫ��\n");
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			printf("��ѡ��Ҫ�����λ�� �����ֵ��");
			scanf_s("%d %d", &pos, &e);
			ListInsert(&L, pos, e);
			break;
		case 11:
			printf("��ѡ��Ҫɾ����λ�ã�");
			scanf_s("%d", &pos);
			ListDelete(&L, pos);
			break;
		case 12:
			break;
		case 0:
			DestoryList(&L);
			printf("�˳�\n");
			break;
		}
	} while (input);
	

	return 0;
}
