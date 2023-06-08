#include "default.h"

/*线索二叉树*/

typedef enum 
{
	Link,			/*Link默认为0，表示左右孩子指针*/
	Thread			/*Thread = 1，表示指向前驱或后继的线索*/
} PointerTag;

/*线索二叉树结构*/
typedef struct BiThrNode
{
	TElemtype data;
	struct BiThrNode* lchild;
	struct BithrNode* rchild;
	PointerTag Ltag;			/*左右标志*/
	PointerTag Rtag;
} BiThrNode, *BiThrTree;

BiThrTree pre;					/*全局变量，始终指向刚刚访问过的结点*/

/*中序遍历进行中线索化*/
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);		/*递归左子树线索化*/
		if (!p->lchild)				/*判断左孩子*/
		{
			p->Ltag = Thread;		/*如果没有左孩子，则是前驱线索*/
			p->lchild = pre;		/*左孩子指向前驱*/
		}
		if (!pre->rchild)			/*前驱没有右孩子*/
		{
			pre->Rtag = Thread;		/*后继线索*/
			pre->rchild = p;		/*前驱右孩子指向后继（p）*/
		}
		pre = p;					/*保持pre指向p的前驱*/
		InThreading(p->rchild);		/*递归右子树线索化*/
	}
}

/*创建中序线索二叉树*/
void CreateThread(BiThrTree* T)
{
	pre = NULL;
	if (T != NULL)
	{
		InThreading(*T);
		pre->rchild = NULL;
		pre->Rtag = Thread;
	}

}

Status CreateBiThrTree(BiThrTree* T)
{
	TElemtype ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));				/*分配空间*/
		if (!*T)
			return ERROR;
		(*T)->data = ch;									/*生成根结点*/
		CreateBiThrTree(&(*T)->lchild);						/*构造左子树*/
		CreateBiThrTree(&(*T)->rchild);						/*构造右子树*/
	}
	return OK;
}

/*中序遍历线索二叉树*/
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;
	while (p != T)									/*遍历结束后，p == T*/
	{
		while (p->Ltag == Link)						/*当Ltag == 0 时指向中序的第一个结点*/
			p = p->lchild;
		printf("%c", p->data);						/*打印中序第一个结点*/
		while (p->Rtag == Thread && p->rchild != T)	/*判断右标记指向后继结点且不是头结点*/
		{
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree H, T;
	T = (BiThrTree)malloc(sizeof(BiThrNode));
	H = (BiThrTree)malloc(sizeof(BiThrNode));
	CreateBiThrTree(&T);
	InOrderThreading(&H, T);

	return 0;
}