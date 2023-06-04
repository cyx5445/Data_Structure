#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

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

#define MAX_SIZE 100			/*初始分配空间（静态分配）*/

typedef int ElemType;			/*元素类型(int)*/

typedef struct
{
	//ElemType data[MAX_SIZE];	/*数组：储存元素*/
	ElemType* data;				/*动态分配：(ElemType*)malloc(sizeof(ElemType)*MAX_SIZE)*/
	int length;					/*线性表长度*/
}SqList;						/*顺序表类型*/

void InitList()
{

}

int main()
{
	SqList L;
	L.data = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);	/*分配动态内存*/

	free(L.data);
	L.data = NULL;

	return 0;
}
