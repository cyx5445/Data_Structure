#include "default.h"

/*����������*/

typedef enum 
{
	Link,			/*LinkĬ��Ϊ0����ʾ���Һ���ָ��*/
	Thread			/*Thread = 1����ʾָ��ǰ�����̵�����*/
} PointerTag;

/*�����������ṹ*/
typedef struct BiThrNode
{
	TElemtype data;
	struct BiThrNode* lchild;
	struct BithrNode* rchild;
	PointerTag Ltag;			/*���ұ�־*/
	PointerTag Rtag;
} BiThrNode, *BiThrTree;

BiThrTree pre;					/*ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��*/

/*�������������������*/
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);		/*�ݹ�������������*/
		if (!p->lchild)				/*�ж�����*/
		{
			p->Ltag = Thread;		/*���û�����ӣ�����ǰ������*/
			p->lchild = pre;		/*����ָ��ǰ��*/
		}
		if (!pre->rchild)			/*ǰ��û���Һ���*/
		{
			pre->Rtag = Thread;		/*�������*/
			pre->rchild = p;		/*ǰ���Һ���ָ���̣�p��*/
		}
		pre = p;					/*����preָ��p��ǰ��*/
		InThreading(p->rchild);		/*�ݹ�������������*/
	}
}

/*������������������*/
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
		*T = (BiThrTree)malloc(sizeof(BiThrNode));				/*����ռ�*/
		if (!*T)
			return ERROR;
		(*T)->data = ch;									/*���ɸ����*/
		CreateBiThrTree(&(*T)->lchild);						/*����������*/
		CreateBiThrTree(&(*T)->rchild);						/*����������*/
	}
	return OK;
}

/*�����������������*/
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;
	while (p != T)									/*����������p == T*/
	{
		while (p->Ltag == Link)						/*��Ltag == 0 ʱָ������ĵ�һ�����*/
			p = p->lchild;
		printf("%c", p->data);						/*��ӡ�����һ�����*/
		while (p->Rtag == Thread && p->rchild != T)	/*�ж��ұ��ָ���̽���Ҳ���ͷ���*/
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