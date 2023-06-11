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