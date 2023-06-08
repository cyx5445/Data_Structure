#include "default.h"

#define MAX_LEN 255

/*Ë³Ðò´æ´¢´®*/
typedef struct
{
	char str[MAX_LEN + 1];
	int length;
}SString;

Status StrAssign(SString* T, char* chars)
{
	assert(chars);
	strcpy(T->str, chars);
	T->length = strlen(chars);
	return OK;
}

int Index(SString S, SString T)
{
	assert(&T);
	int i = 0;
	int j = 0;
	while (i < S.length && j < T.length)
	{
		if (S.str[i] == T.str[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= T.length)
		return i - T.length;
	else
		return 0;
}

int Index_pos(SString S, SString T, int pos)
{
	assert(&T);
	int i = pos;
	int j = 0;
	while (i < S.length && j < T.length)
	{
		if (S.str[i] == T.str[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= T.length)
		return i - T.length;
	else
		return 0;
}

int Get_Next(SString T, int* next)
{
	int i, k;
	i = 1;
	k = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (k == 0 || T.str[i] == T.str[k])
		{
			++i;
			++k;
			next[i] = k;
		}
		else
			k = next[k];
	}
}

int Get_Nextval(SString T, int* nextval)
{
	int i, k;
	i = 1;
	k = 0;
	nextval[1] = 0;
	while (i < T.length)
	{
		if (k == 0 || T.str[i] == T.str[k])
		{
			++i;
			++k;
			if (T.str[i] != T.str[k])
				nextval[i] = k;
			else
				nextval[i] = nextval[k];
		}
		else
			k = nextval[k];
	}
}

int Index_KMP(SString S, SString T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	Get_Next(T, next);
	while (i < S.length && j < T.length)
	{
		if (j == 0 || S.str[i] == T.str[j])
		{
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j >= T.length)
		return i - T.length;
	else
		return 0;
}

int main()
{
	SString S, T;
	char char1[] = "abcdefag";
	char char2[] = "def";
	StrAssign(&S, char1);
	StrAssign(&T, char2);

	//int p1 = Index(S, T);
	//int p2 = Index_pos(S, T, 5);
	//printf("%d %d", p1, p2);

	int p = Index_KMP(S, T, 1);
	printf("%d", p);

	return 0;
}