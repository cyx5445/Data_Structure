#define _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0			/*����(0)*/
#define INFEASIBLE -1	/*������(-1)*/
#define MAX_SIZE 100	/*��ʼ����ռ䣨��̬���䣩*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

typedef struct Stu
{
	int num;
	int name;
	int score;
}Stu;

typedef Stu ElemType;			/*������������*/
typedef int Status;

/*���Ա���ʽ�洢�ṹ*/
typedef struct Node
{
	ElemType data;				/*������*/
	struct Node* next;			/*ָ����*/
}Node;

typedef struct Node* LinkList;	/*ָ�룺ָ������*/

/*�������ʼ��*/
Status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));		/*���䶯̬�ڴ�*/
	(*L)->next = NULL;							/*ͷָ��Ϊ��*/
	return OK;
}

/*�ж������Ƿ�Ϊ��*/
Status ListEmpty(const LinkList* L)
{
	if ((*L)->next == NULL)
	{
		return 0;
	}
	return 1;
}

/*�����������*/
Status DestroyList(LinkList *L)
{
	LinkList p;
	while (L != NULL)
	{
		p = *L;				/*��ͷ�ڵ㿪ʼ*/
		*L = (*L)->next;	/*ʹLָ����һ���ڵ�*/
		free(p);
	}
	return OK;
}

/*��յ�����*/
Status ClearList(LinkList* L)
{
	LinkList p, q;
	p = (*L)->next;			/*ʹpָ����Ԫ�ڵ�*/
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

/*������ı�*/
Status ListLength(const LinkList* L)
{
	LinkList p;
	int count = 0;
	p = (*L)->next;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}

/*��ȡ����������*/
Status GetElem(const LinkList* L, int i, ElemType* e)
{
	int j = 1;
	LinkList p;
	p = (*L)->next;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

/*���ҵ���������*/
LinkList LocateElem(const LinkList* L, ElemType* e)
{
	LinkList p = (*L)->next;
	int input;
	printf("��ѡ��������ͣ�1.������2.ѧ�ţ�:");
	scanf_s("%d", &input);
	do
	{
		if (input == 1)
		{
			printf("������Ҫ���ҵ���Ϣ��");
			scanf_s("%d", &input);
			while (p && p->data.name == input)
			{
				p = p->next;
			}
			return p;
		}
		else if (input == 2)
		{
			printf("������Ҫ���ҵ���Ϣ��");
			scanf_s("%d", &input);
			while (p && p->data.num == input)
			{
				p = p->next;
			}
			return p;
		}
		else
		{
			printf("������ѡ��\n");
		}
	} while (1);
}

/*�����i���ڵ�*/
Status ListInsert(LinkList* L, int i, ElemType* e)
{
	int j = 1;
	LinkList p, s;
	p = *L;
	while (p && j < i)
	{
		p = p->next;			/*�ҵ���i���ڵ�*/
		++j;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = *e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/*ɾ����i���ڵ�*/
Status ListDelete(LinkList* L, int i, ElemType* e)
{
	LinkList p, q;
	int j = 1;
	p = *L;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;				/*��ʱ���汻ɾ���Ľڵ��ַ���Ա��ͷ�*/
	p->next = q->next;			/* p->next = p->next->next */
	*e = q->data;				/*����ɾ����data*/
	free(q);
	q = NULL;
	return OK;
}

/*����һ������ͷ�巨��*/
void CreateListHead(LinkList* L, int n)
{
	LinkList p{};
	InitList(L);				/*��ʼ������*/
	int i = 0;
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data.num = rand() % 100 + 1;		/*�������ֵ1-100*/
		p->data.name = rand() % 100 + 1;
		p->data.score = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	InitList(L);
	int i = 0;
	srand(time(0));
	r = *L;			/*βָ��rָ��ͷ�ڵ�*/
	for (i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data.num = rand() % 100 + 1;		
		p->data.name = rand() % 100 + 1;
		p->data.score = rand() % 100 + 1;
		p->next = NULL;
		r->next = p;	/*���뵽��β*/
		r = p;			/*rָ���µ�βָ��*/
	}
}

Status PrintList(LinkList* L, int len)
{
	LinkList* p = L;
	for (int i = 0; i < len; i++)
	{
		printf("��%d��Ԫ�أ�name = %d, num = %d, score = %d, next = %p\n", i, (*p)->data.name, (*p)->data.num, (*p)->data.score, (*p)->next);
		*p = (*p)->next;
	}
	return OK;
}

/*���򼯺ϲ�*/
void MergeList(LinkList* La, LinkList* Lb, LinkList* Lc)
{
	LinkList pa, pb, pc;
	pa = (*La)->next;
	pb = (*Lb)->next;
	pc = (*Lc)->next;
	while (pa && pb)
	{
		if (pa->data.num <= pb->data.num)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = (pa ? pa : pb);
		free(Lb);
	}
}

int main()
{
	LinkList L{};
	int len = 0;
	int input;
	char s[2];
	printf("�������ָ�����ȵ�����");
	scanf_s("%d", &len);
	printf("1.ͷ�巨 2.β�巨��");
	scanf_s("%d", &input);
	if (input == 1)
	{
		CreateListHead(&L, len);
	}
	else if (input == 2)
	{
		CreateListTail(&L, len);
	}
	
	printf("�Ƿ�Ҫ��ӡ��Y/N��:");
	scanf_s("%s", &s, 2);
	if (strcmp(s, "Y") == 0)
		PrintList(&L, len);
		
	
	return 0;
}