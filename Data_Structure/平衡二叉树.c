#include "default.h"

/*结点的平衡因子*/
#define LH +1		/*左高*/
#define EH 0		/*等高*/
#define RH -1		/*右高*/

/*二叉树的二叉链表结点结构*/
typedef struct BiTNode
{
	int data;
	int bf;			/*结点的平衡因子（左孩子高度-右孩子高度）*/
	struct BiTNode* lchild, * rchild;
} BiTNode, *BiTree;

/*最小二叉平衡树插入后右旋（LL型）*/
void R_Rotate(BiTree* P)
{
	BiTree L;
	L = (*P)->lchild;
	(*P)->lchild = L->lchild;
	L->rchild = (*P);
	*P = L;
}

/*左旋*/
void L_Rotate(BiTree* P)
{
	BiTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->rchild;
	R->lchild = (*P);
	*P = R;
}

/*二叉树左平衡旋转处理*/
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf)		/*检查T左子树的平衡度*/
	{
	case LH:			/*新结点插在T的左孩子的左子树上，要做右旋*/
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:			/*新结点在T的左孩子的右子树，要作双旋*/
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
		L_Rotate(&(*T)->lchild);	/*对T的左子树作左旋平衡处理*/
		R_Rotate(T);				/*对T作右旋平衡处理*/
		break;
	}
}

/*二叉树右平衡旋转处理*/
void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild; /*  R指向T的右子树根结点 */
	switch (R->bf)
	{ /*  检查T的右子树的平衡度，并作相应平衡处理 */
	case RH: /*  新结点插入在T的右孩子的右子树上，要作单左旋处理 */
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH: /*  新结点插入在T的右孩子的左子树上，要作双旋处理 */
		Rl = R->lchild; 			/*  Rl指向T的右孩子的左子树根 */
		switch (Rl->bf)
		{ 						/*  修改T及其右孩子的平衡因子 */
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
		R_Rotate(&(*T)->rchild); /*  对T的右子树作右旋平衡处理 */
		L_Rotate(T); /*  对T作左旋平衡处理 */
		break;
	}
}

/*平衡二叉树处理*/
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
		if (e == (*T)->data)	/*若已有结点，则不再插入*/
		{
			*taller = FALSE;
			return FALSE;
		}

		if (e < (*T)->data)		/*小于结点进入左子树进行搜索*/
		{
			if (!InsertAVL(&(*T)->lchild, e, taller))	/*未插入*/
				return FALSE;
			if (*taller)
			{
				switch ((*T)->bf)	/*检查T的平衡度*/
				{
				case LH:
					LeftBalance(T);
					*taller = FALSE;
					break;
				case EH:			/*原本左右子树等高，现因左子树增高*/
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
			if (!InsertAVL(&(*T)->lchild, e, taller))	/*未插入*/
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