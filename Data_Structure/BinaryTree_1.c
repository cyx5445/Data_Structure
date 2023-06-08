#include "default.h"

/*二叉树*/

/*顺序存储(适用于完全二叉树)*/
//typedef TElemtype SqBiTree[MAX_TREE_SIZE];
//SqBiTree bt;

/*二叉链表*/
typedef struct BiTNode
{
	TElemtype data;				/*数据域*/
	struct BiTNode* lchild;		/*左孩子指针*/
	struct BiTNode* rchild;		/*右孩子指针*/
	//struct BiNode* parent;		/*双亲指针（三叉链表）*/
}BiTNode, *BiTree;

/*先序遍历（DLR）*/
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);	/*先遍历左子树*/
	PreOrderTraverse(T->rchild);	/*遍历右子树*/
}

/*中序遍历（LDR）*/
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
}

/*后序遍历（LRD）*/
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
}

/*非递归算法（栈）*/
//void InOrderTraverse_Stack(BiTree T)
//{
//	BiTree p, q;
//	LinkStack S;
//	InitStack(S);
//	p = T;
//	while (p || !StackEmpty(S))
//	{
//		if (p)
//		{
//			Push(S, p);
//			p = p->lchild;
//		}
//		else
//		{
//			Pop(S, &q);
//			printf("%c", q->data);
//			p = q->rchild;
//		}
//	}
//	return OK;
//}

 /*层次遍历（队列）*/
//void LeverOrderTraverse(BiTree T)
//{
//	SqQueue* Q;							/*创建循环队列*/
//	InitSqQueue(Q);
//	BiNode* p;
//	EnQueue(Q, T);						/*根结点指针入队*/
//	while (!QueueEmpty(Q))				/*队不为空，则循环*/
//	{
//		deQueue(Q, p);					/*出队结点p*/
//		printf("%c", p->data);
//		if (p->lchild != NULL)
//			EnQueue(Q, p->lchild);		/*有左孩子时入队*/
//		if (p->rchild != NULL)
//			EnQueue(Q, p->rchild);		/*有右孩子时入队*/
//	}
//}

/*二叉树的建立（先序）*/
Status CreateBiTree(BiTree* T)
{
	TElemtype ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));				/*分配空间*/
		if (!*T)	
			return ERROR;
		(*T)->data = ch;									/*生成根结点*/
		CreateBiTree(&(*T)->lchild);						/*构造左子树*/
		CreateBiTree(&(*T)->rchild);						/*构造右子树*/
	}
	return OK;
}

/*复制树*/
Status Copy(BiTree T, BiTree* NewT)
{
	if (T == NULL)
	{
		*NewT = NULL;
		return 0;
	}else {
		*NewT = (BiTree)malloc(sizeof(BiTNode));
		if (!*NewT)
			return ERROR;
		(*NewT)->data = T->data;
		Copy(T->lchild, &(*NewT)->lchild);
		Copy(T->rchild, &(*NewT)->rchild);
	}
}

/*计算树的深度*/
int Depth(BiTree T)
{
	int m, n;
	if (T == NULL)
		return 0;
	else
	{
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

/*求结点个数*/
int NodeCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

/*叶子结点个数*/
int LeafCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else if (T->lchild == NULL && T->rchild == NULL)		/*判断是否叶子结点*/
		return 1;
	else
		return LeafCount(T->lchild) + LeafCount(T->rchild);
}

//int main()
//{
//	BiTree T, B;
//	CreateBiTree(&T);
//	PreOrderTraverse(T);
//	printf("\n");
//	//InOrderTraverse(T);
//	//printf("\n");
//	//PostOrderTraverse(T);
//	//printf("\n");
//	//test:ABDG##H###CE#I##F##
//
//	//Copy(T, &B);
//	//PreOrderTraverse(B);
//
//	//int depth = Depth(T);
//	//printf("%d\n", depth);
//
//	//printf("%d", NodeCount(T));
//
//	return 0;
//}