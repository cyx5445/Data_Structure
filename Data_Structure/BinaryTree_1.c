#include "default.h"

/*������*/

/*˳��洢(��������ȫ������)*/
//typedef TElemtype SqBiTree[MAX_TREE_SIZE];
//SqBiTree bt;

/*��������*/
typedef struct BiTNode
{
	TElemtype data;				/*������*/
	struct BiTNode* lchild;		/*����ָ��*/
	struct BiTNode* rchild;		/*�Һ���ָ��*/
	//struct BiNode* parent;		/*˫��ָ�루��������*/
}BiTNode, *BiTree;

/*���������DLR��*/
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);	/*�ȱ���������*/
	PreOrderTraverse(T->rchild);	/*����������*/
}

/*���������LDR��*/
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
}

/*���������LRD��*/
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
}

/*�ǵݹ��㷨��ջ��*/
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

 /*��α��������У�*/
//void LeverOrderTraverse(BiTree T)
//{
//	SqQueue* Q;							/*����ѭ������*/
//	InitSqQueue(Q);
//	BiNode* p;
//	EnQueue(Q, T);						/*�����ָ�����*/
//	while (!QueueEmpty(Q))				/*�Ӳ�Ϊ�գ���ѭ��*/
//	{
//		deQueue(Q, p);					/*���ӽ��p*/
//		printf("%c", p->data);
//		if (p->lchild != NULL)
//			EnQueue(Q, p->lchild);		/*������ʱ���*/
//		if (p->rchild != NULL)
//			EnQueue(Q, p->rchild);		/*���Һ���ʱ���*/
//	}
//}

/*�������Ľ���������*/
Status CreateBiTree(BiTree* T)
{
	TElemtype ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));				/*����ռ�*/
		if (!*T)	
			return ERROR;
		(*T)->data = ch;									/*���ɸ����*/
		CreateBiTree(&(*T)->lchild);						/*����������*/
		CreateBiTree(&(*T)->rchild);						/*����������*/
	}
	return OK;
}

/*������*/
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

/*�����������*/
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

/*�������*/
int NodeCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

/*Ҷ�ӽ�����*/
int LeafCount(BiTree T)
{
	if (T == NULL)
		return 0;
	else if (T->lchild == NULL && T->rchild == NULL)		/*�ж��Ƿ�Ҷ�ӽ��*/
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