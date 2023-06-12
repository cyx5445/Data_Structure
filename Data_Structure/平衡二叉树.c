#include "default.h"

/*����ƽ������*/
#define LH +1		/*���*/
#define EH 0		/*�ȸ�*/
#define RH -1		/*�Ҹ�*/

/*�������Ķ���������ṹ*/
typedef struct BiTNode
{
	int data;
	int bf;			/*����ƽ�����ӣ����Ӹ߶�-�Һ��Ӹ߶ȣ�*/
	struct BiTNode* lchild, * rchild;
} BiTNode, *BiTree;

/*��С����ƽ���������������LL�ͣ�*/
void R_Rotate(BiTree* P)
{
	BiTree L;
	L = (*P)->lchild;
	(*P)->lchild = L->lchild;
	L->rchild = (*P);
	*P = L;
}

/*����*/
void L_Rotate(BiTree* P)
{
	BiTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->rchild;
	R->lchild = (*P);
	*P = R;
}

/*��������ƽ����ת����*/
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf)		/*���T��������ƽ���*/
	{
	case LH:			/*�½�����T�����ӵ��������ϣ�Ҫ������*/
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:			/*�½����T�����ӵ���������Ҫ��˫��*/
		Lr = L->lchild;
		switch (Lr->bf)
		{
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);	/*��T��������������ƽ�⴦��*/
		R_Rotate(T);				/*��T������ƽ�⴦��*/
		break;
	}
}

/*��������ƽ����ת����*/
void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild; /*  Rָ��T������������� */
	switch (R->bf)
	{ /*  ���T����������ƽ��ȣ�������Ӧƽ�⴦�� */
	case RH: /*  �½�������T���Һ��ӵ��������ϣ�Ҫ������������ */
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH: /*  �½�������T���Һ��ӵ��������ϣ�Ҫ��˫������ */
		Rl = R->lchild; 			/*  Rlָ��T���Һ��ӵ��������� */
		switch (Rl->bf)
		{ 						/*  �޸�T�����Һ��ӵ�ƽ������ */
		case RH: (*T)->bf = LH;
			R->bf = EH;
			break;
		case EH: (*T)->bf = R->bf = EH;
			break;
		case LH: (*T)->bf = EH;
			R->bf = RH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild); /*  ��T��������������ƽ�⴦�� */
		L_Rotate(T); /*  ��T������ƽ�⴦�� */
		break;
	}
}

/*ƽ�����������*/
Status InsertAVL(BiTree* T, int e, Status* taller)
{
	if (!*T)
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!T)
			return ERROR;
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if (e == (*T)->data)	/*�����н�㣬���ٲ���*/
		{
			*taller = FALSE;
			return FALSE;
		}

		if (e < (*T)->data)		/*С�ڽ�������������������*/
		{
			if (!InsertAVL(&(*T)->lchild, e, taller))	/*δ����*/
				return FALSE;
			if (*taller)
			{
				switch ((*T)->bf)	/*���T��ƽ���*/
				{
				case LH:
					LeftBalance(T);
					*taller = FALSE;
					break;
				case EH:			/*ԭ�����������ȸߣ���������������*/
					(*T)->bf = LH;
					*taller = TRUE;
					break;
				case RH:
					RightBalance(T);
					*taller = FALSE;
					break;
				}
			}
		}
		else
		{
			if (!InsertAVL(&(*T)->lchild, e, taller))	/*δ����*/
				return FALSE;
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = TRUE;
				case RH:
					RightBalance(T);
					*taller = FALSE;
					break;
				}
			}
		}
	}
	return TRUE;
}

int main()
{
	int i;
	int a[10] = { 3,2,1,4,5,6,7,10,9,8 };
	BiTree T = NULL;
	Status taller;
	for (i = 0; i < 10; i++)
	{
		InsertAVL(&T, a[i], &taller);
	}

	return 0;
}