#include "default.h"

typedef struct
{
	ElemType* data;
	int length;
}SqList;

Status InitSqlist(SqList* L)
{
	L->length = 0;
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAX_SIZE);
	if (!L->data)
		return OVERFLOW;
	return OK;
}

Status DestroyList(SqList* L)
{
	if (L->data)
	{
		free(L->data);
		L->data = NULL;
		L->length = 0;
	}
	else
	{
		return ERROR;
	}
		
}

Status ClearList(SqList* L)
{
	L->length = 0;
}

Status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ListLength(SqList L)
{
	return L.length;
}

Status GetElem(SqList L, int i, ElemType* e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}

Status LocateElem(SqList L, int i, ElemType* e)
{
	int j;
	for (j = 0; j < L.length; j++)
	{
		if (L.data[j] == i)
		{
			*e = j;
			return OK;
		}
	}
	return FALSE;
}

Status ListInsert(SqList* L, int i, ElemType e)
{
	int k;
	if (i < 1 || i > L->length)
		return ERROR;
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i - 1; k--)
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList* L, int pos)
{
	int k;
	if (pos > L->length || pos < 1)
		return ERROR;
	if (pos <= L->length)
	{
		for (k = pos; k < L->length; k++)
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}