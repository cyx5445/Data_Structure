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
静态链表：用数组来代替指针
*/

typedef struct Nums
{
	int nums;
}Nums;

typedef struct
{
	ElemType data;
	int cur;							/*游标*/
}Component, StaticLinkList[MAX_SIZE];

/*初始化静态链表*/
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAX_SIZE - 1; i++)	/*分配每一个元素的cur*/
	{
		space[i].cur = i + 1;
	}
	space[MAX_SIZE - 1].cur = 0;		/*最后一个cur存放第一个元素的下标*/
	return OK;
}

/*确认静态链表备用空间非空，则返回分配结点下标，否则返回0*/
int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

/*求静态链表长度*/
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

/*静态链表插入新元素*/
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int l, j, k;
	k = MAX_SIZE - 1;						/*k为最后一个元素的下标*/
	if (i < 1 || i > ListLength(L) + 1)
		return ERROR;
	j = Malloc_SSL(L);						/*获得空闲分量的下标*/
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

/*把下标为i的空闲结点回收到备用结点*/
void Free_SSL(StaticLinkList L, int i)
{
	L[i].cur = L[0].cur;
	L[0].cur = i;
}

/*删除第i个元素*/
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