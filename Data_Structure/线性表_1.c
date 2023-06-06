#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0			/*错误(0)*/
#define INFEASIBLE -1	/*不可行(-1)*/
#define MAX_SIZE 100	/*初始分配空间（静态分配）*/

/*
线性表简单操作
操作：				说明：
1.InitList			初始化线性表
2.DestoryList		销毁线性表
3.ClearList			重置线性表
4.ListEmpty			判断是否为空表
5.ListLength		计算线性表元素个数
6.GetElem			取线性表中指定元素
7.LocateElem		查找定位指定元素
8.PriorElem			查找指定元素前驱
9.NextElem			查找指定元素后继
10.ListInsert		在线性表中插入指定元素
11.ListDelete		删除指定元素
12.ListTraverse		遍历元素
*/

typedef int ElemType;			/*元素类型(int)*/
typedef int Status;				/*函数类型(int)*/

typedef struct
{
	//ElemType data[MAX_SIZE];	/*数组：储存元素*/
	ElemType* data;				/*动态分配：(ElemType*)malloc(sizeof(ElemType)*MAX_SIZE)*/
	int length;					/*线性表长度*/
	int capacity;				/*当前线性表容量*/
}SqList;						/*顺序表类型*/

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

Status InitList(SqList* L)										/*构造一个空表*/
{
	L->length = 0;												/*空表长度为0*/
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);	/*分配动态内存*/
	if (L->data == NULL)										/*异常处理*/
	{
		printf("%s\n", strerror(errno));
	}
	printf("初始化成功！\n");
	return OK;
}

void DestoryList(SqList* L)
{
	if (L->data)
	{
		free(L->data);					/*释放内存*/
		L->data = NULL;
		printf("销毁成功！\n");
	}
	else
	{
		printf("线性表不存在\n");
	}
	
}

void ClearList(SqList* L)
{
	assert(L);
	L->length = 0;						/*将线性表长度设置为0*/
	printf("设置成功！\n");
}

Status ListEmpty(const SqList* L)
{
	if (L->length == 0)
	{
		printf("为空表\n");
		return 1;
	}
	else
	{
		printf("非空表\n");
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
	if (i < 1 || i > L->length)			/*判断位置是否合理*/
		return ERROR;
	*e = L->data[i - 1];				/*第i-1的单元储存第i个数据*/
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
		printf("插入失败！\n");
		return ERROR;
	}
	if (i <= L->length)
	{
		for (int k = L->length - 1; k >= i - 1; k--)
			L->data[k + 1] = L->data[k];				/*插入在中间，元素依次后移*/
	}
	L->data[i - 1] = e;

	L->length++;
	printf("插入成功！\n");
	return OK;
}

Status ListDelete(SqList* L, int pos)
{
	assert(L);
	if (pos > L->length || pos < 1)
		return ERROR;
	if (pos < L->length)
	{
		for (int k = pos; k < L->length; k++)		/*依次前移元素*/
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

/*有序集合并*/
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
		printf("请选择：");
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
			printf("线性表长度为：%d\n", Len);
			break;
		case 6:
			printf("请输入要取第几个值：");
			scanf_s("%d", &i);
			GetElem(&L, i, &e);
			printf("值为：%d\n", e);
			break;
		case 7:
			printf("请输入要查找的值：");
			scanf_s("%d", &i);
			res = LocateElem(&L, i, &e);
			if (res == 1)
				printf("查找值下标为：%d\n", e);
			else
				printf("不存在该元素\n");
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			printf("请选择要插入的位置 插入的值：");
			scanf_s("%d %d", &pos, &e);
			ListInsert(&L, pos, e);
			break;
		case 11:
			printf("请选择要删除的位置：");
			scanf_s("%d", &pos);
			ListDelete(&L, pos);
			break;
		case 12:
			break;
		case 0:
			DestoryList(&L);
			printf("退出\n");
			break;
		}
	} while (input);
	

	return 0;
}
