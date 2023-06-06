#define _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0			/*错误(0)*/
#define INFEASIBLE -1	/*不可行(-1)*/
#define MAX_SIZE 100	/*初始分配空间（静态分配）*/

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

typedef Stu ElemType;			/*定义数据类型*/
typedef int Status;

/*线性表单链式存储结构*/
typedef struct Node
{
	ElemType data;				/*数据域*/
	struct Node* next;			/*指针域*/
}Node;

typedef struct Node* LinkList;	/*指针：指向链表*/

/*单链表初始化*/
Status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));		/*分配动态内存*/
	(*L)->next = NULL;							/*头指针为空*/
	return OK;
}

/*判断链表是否为空*/
Status ListEmpty(const LinkList* L)
{
	if ((*L)->next == NULL)
	{
		return 0;
	}
	return 1;
}

/*单链表的销毁*/
Status DestroyList(LinkList *L)
{
	LinkList p;
	while (L != NULL)
	{
		p = *L;				/*从头节点开始*/
		*L = (*L)->next;	/*使L指向下一个节点*/
		free(p);
	}
	return OK;
}

/*清空单链表*/
Status ClearList(LinkList* L)
{
	LinkList p, q;
	p = (*L)->next;			/*使p指向首元节点*/
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

/*求链表的表长*/
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

/*读取单链表数据*/
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

/*查找单链表数据*/
LinkList LocateElem(const LinkList* L, ElemType* e)
{
	LinkList p = (*L)->next;
	int input;
	printf("请选择查找类型（1.姓名、2.学号）:");
	scanf_s("%d", &input);
	do
	{
		if (input == 1)
		{
			printf("请输入要查找的信息：");
			scanf_s("%d", &input);
			while (p && p->data.name == input)
			{
				p = p->next;
			}
			return p;
		}
		else if (input == 2)
		{
			printf("请输入要查找的信息：");
			scanf_s("%d", &input);
			while (p && p->data.num == input)
			{
				p = p->next;
			}
			return p;
		}
		else
		{
			printf("请重新选择\n");
		}
	} while (1);
}

/*插入第i个节点*/
Status ListInsert(LinkList* L, int i, ElemType* e)
{
	int j = 1;
	LinkList p, s;
	p = *L;
	while (p && j < i)
	{
		p = p->next;			/*找到第i个节点*/
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

/*删除第i个节点*/
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
	q = p->next;				/*临时保存被删除的节点地址，以备释放*/
	p->next = q->next;			/* p->next = p->next->next */
	*e = q->data;				/*保存删除的data*/
	free(q);
	q = NULL;
	return OK;
}

/*创建一个链表（头插法）*/
void CreateListHead(LinkList* L, int n)
{
	LinkList p{};
	InitList(L);				/*初始化链表*/
	int i = 0;
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data.num = rand() % 100 + 1;		/*设置随机值1-100*/
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
	r = *L;			/*尾指针r指向头节点*/
	for (i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data.num = rand() % 100 + 1;		
		p->data.name = rand() % 100 + 1;
		p->data.score = rand() % 100 + 1;
		p->next = NULL;
		r->next = p;	/*插入到表尾*/
		r = p;			/*r指向新的尾指针*/
	}
}

Status PrintList(LinkList* L, int len)
{
	LinkList* p = L;
	for (int i = 0; i < len; i++)
	{
		printf("第%d个元素：name = %d, num = %d, score = %d, next = %p\n", i, (*p)->data.name, (*p)->data.num, (*p)->data.score, (*p)->next);
		*p = (*p)->next;
	}
	return OK;
}

/*有序集合并*/
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
	printf("随机创建指定长度的链表：");
	scanf_s("%d", &len);
	printf("1.头插法 2.尾插法：");
	scanf_s("%d", &input);
	if (input == 1)
	{
		CreateListHead(&L, len);
	}
	else if (input == 2)
	{
		CreateListTail(&L, len);
	}
	
	printf("是否要打印（Y/N）:");
	scanf_s("%s", &s, 2);
	if (strcmp(s, "Y") == 0)
		PrintList(&L, len);
		
	
	return 0;
}