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
#include <assert.h>

typedef int ElemType;
typedef int Status;

/*
循环链表：在单链表的基础下将尾指针指向头指针形成循环，用指向终端结点的尾指针来表示循环链表。
*/

typedef struct
{
	ElemType data;
	LinkList* next;
}LinkList;

/*合并两个循环链表*/
LinkList Connect(LinkList* rearA, LinkList* rearB)
{
	assert(rearA, rearB);
	LinkList p, q;
	p = *rearA->next;					/*用p存储A的头结点*/
	*rearA->next = *rearB->next->next;	/*将A表的尾指针指向B的第一个结点*/
	q = *rearB->next;					
	*rearB->next = p;					/*将B的尾指针指向A的头指针*/
	free(&q);							/*释放B的头指针*/
	return *rearB;
}