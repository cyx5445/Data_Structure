#include "D:\Project\C\Data_Structure\Data_Structure\default.c"

typedef struct
{
	ElemType data;
	struct DuNode* prior;		/*ǰ��ָ��*/
	struct DuNode* next;		/*���ָ��*/
}DuNode, *DuLinkList;

// p->prior->next = p = p->next->prior

Status DuListInsert(DuLinkList L, int i, ElemType e)
{
	DuLinkList s, p;
	s->data = e;
	s->prior = L->prior;
	p = L->next;
	p->prior = s;
	s->next = L;
	L->prior = s;
	return OK;
}

int main()
{


	return 0;
}