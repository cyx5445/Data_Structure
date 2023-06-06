#define _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0			
#define INFEASIBLE -1	
#define MAX_SIZE 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef Nums ElemType;
typedef int Status;

/*
��̬����������������ָ��
*/

typedef struct Nums
{
	int nums;
}Nums;

typedef struct
{
	ElemType data;
	int cur;							/*�α�*/
}Component, StaticLinkList[MAX_SIZE];

/*��ʼ����̬����*/
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAX_SIZE - 1; i++)	/*����ÿһ��Ԫ�ص�cur*/
	{
		space[i].cur = i + 1;
	}
	space[MAX_SIZE - 1].cur = 0;		/*���һ��cur��ŵ�һ��Ԫ�ص��±�*/
	return OK;
}

/*ȷ�Ͼ�̬�����ÿռ�ǿգ��򷵻ط������±꣬���򷵻�0*/
int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

/*��̬������*/
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAX_SIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		++j;
	}
	return j;
}

/*��̬���������Ԫ��*/
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int l, j, k;
	k = MAX_SIZE - 1;						/*kΪ���һ��Ԫ�ص��±�*/
	if (i < 1 || i > ListLength(L) + 1)
		return ERROR;
	j = Malloc_SSL(L);						/*��ÿ��з������±�*/
	if (j)
	{
		L[j].data = e;
		for (l = 1; l <= i - 1; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

/*���±�Ϊi�Ŀ��н����յ����ý��*/
void Free_SSL(StaticLinkList L, int i)
{
	L[i].cur = L[0].cur;
	L[0].cur = i;
}

/*ɾ����i��Ԫ��*/
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i < 1 || i > ListLength(L) + 1)
		return ERROR;
	k = MAX_SIZE - 1;
	for (j = 1; j <= i - 1; j++)
	{
		k = L[k].cur;
	}
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
}