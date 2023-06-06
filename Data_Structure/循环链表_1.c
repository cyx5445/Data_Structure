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
ѭ�������ڵ�����Ļ����½�βָ��ָ��ͷָ���γ�ѭ������ָ���ն˽���βָ������ʾѭ������
*/

typedef struct
{
	ElemType data;
	LinkList* next;
}LinkList;

/*�ϲ�����ѭ������*/
LinkList Connect(LinkList* rearA, LinkList* rearB)
{
	assert(rearA, rearB);
	LinkList p, q;
	p = *rearA->next;					/*��p�洢A��ͷ���*/
	*rearA->next = *rearB->next->next;	/*��A���βָ��ָ��B�ĵ�һ�����*/
	q = *rearB->next;					
	*rearB->next = p;					/*��B��βָ��ָ��A��ͷָ��*/
	free(&q);							/*�ͷ�B��ͷָ��*/
	return *rearB;
}