#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

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

#define MAX_SIZE 100			/*��ʼ����ռ䣨��̬���䣩*/

typedef int ElemType;			/*Ԫ������(int)*/

typedef struct
{
	//ElemType data[MAX_SIZE];	/*���飺����Ԫ��*/
	ElemType* data;				/*��̬���䣺(ElemType*)malloc(sizeof(ElemType)*MAX_SIZE)*/
	int length;					/*���Ա���*/
}SqList;						/*˳�������*/

void InitList()
{

}

int main()
{
	SqList L;
	L.data = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);	/*���䶯̬�ڴ�*/

	free(L.data);
	L.data = NULL;

	return 0;
}
