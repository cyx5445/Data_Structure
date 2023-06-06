#include "D:\Project\C\Data_Structure\Data_Structure\default.c"

typedef struct
{
	ElemType data;
	int length;
}SqList;

void Union(SqList* La, SqList* Lb)
{
	int La_len = La->length;
	int Lb_len = Lb->length;
	int i = 1;
	ElemType e;
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		
	}
}

int main()
{


	return 0;
}