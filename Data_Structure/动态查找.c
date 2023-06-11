#include "default.h"

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
} BiTNode, *BiTree;

/*二叉排序树查找*/
Status SearchBST(BiTree T, const int key, BiTree f, BiTree* p)
{			/*若查找不成功，指针p指向查找路径上访问的最后一个结点并返回FALSE*/
	if (!T)
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data)
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
		return SearchBST(T->lchild, key, T, p);
	else
		return SearchBST(T->rchild, key, T, p);
}

/*二叉排序树插入结点*/
Status InsertBST(BiTree* T, const int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))	/*查找key是否存在，若存在返回key的结点*/
	{
		s = (BiTree*)malloc(sizeof(BiTNode));
		if (!s)
			return OVERFLOW;
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;						/*插入s为新的根结点*/
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	else
		return FALSE;
}

/*删除二叉排列树结点*/
Status Delete(BiTree* p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL)		/*若右子树为空，则只需重接左子树*/
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)	/*若左子树为空*/
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{								/*左右子树都不为空*/
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)			/*转左，然后向右到尽头，找到被删结点在中序遍历下的前驱*/
		{
			q = s;					/*q为s的上一个结点*/
			s = s->rchild;
		}
		(*p)->data = s->data;		/*将s指向被删结点的前驱，用它的前驱代替被删结点*/
		if (q != p)
			q->rchild = s->lchild;	/*重接q的右子树*/
		else
			q->lchild = s->lchild;	/*重接q的左子树*/
		free(s);
	}
	return TRUE;
}

/*二叉排列树删除结点*/
Status DeleteBST(BiTree* T, int key)
{
	if (!*T)
		return FALSE;
	else
	{
		if (key == (*T)->data)		/*利用递归查找等于key的结点*/
			return Delete(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}

int main()
{
	int i;
	int a[10] = { 62,88,58,47,35,73,51,99,37,93 };
	BiTree T = NULL;

	for (i = 0; i < 10; i++)
	{
		InsertBST(&T, a[i]);
	}

	printf("本样例建议断点跟踪查看二叉排序树结构");
	return 0;
}