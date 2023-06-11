#include "default.h"

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
} BiTNode, *BiTree;

/*��������������*/
Status SearchBST(BiTree T, const int key, BiTree f, BiTree* p)
{			/*�����Ҳ��ɹ���ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE*/
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

/*����������������*/
Status InsertBST(BiTree* T, const int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))	/*����key�Ƿ���ڣ������ڷ���key�Ľ��*/
	{
		s = (BiTree*)malloc(sizeof(BiTNode));
		if (!s)
			return OVERFLOW;
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			*T = s;						/*����sΪ�µĸ����*/
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	else
		return FALSE;
}

/*ɾ���������������*/
Status Delete(BiTree* p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL)		/*��������Ϊ�գ���ֻ���ؽ�������*/
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)	/*��������Ϊ��*/
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{								/*������������Ϊ��*/
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)			/*ת��Ȼ�����ҵ���ͷ���ҵ���ɾ�������������µ�ǰ��*/
		{
			q = s;					/*qΪs����һ�����*/
			s = s->rchild;
		}
		(*p)->data = s->data;		/*��sָ��ɾ����ǰ����������ǰ�����汻ɾ���*/
		if (q != p)
			q->rchild = s->lchild;	/*�ؽ�q��������*/
		else
			q->lchild = s->lchild;	/*�ؽ�q��������*/
		free(s);
	}
	return TRUE;
}

/*����������ɾ�����*/
Status DeleteBST(BiTree* T, int key)
{
	if (!*T)
		return FALSE;
	else
	{
		if (key == (*T)->data)		/*���õݹ���ҵ���key�Ľ��*/
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

	printf("����������ϵ���ٲ鿴�����������ṹ");
	return 0;
}