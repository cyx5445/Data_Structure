#include "D:\Project\C\Data_Structure\Data_Structure\default.c"

/*��*/

/*���ṹ*/
typedef struct PTNode
{
	TElemtype data;		/*�������*/
	int parent;			/*˫��λ��*/
}PTNode;

/*���ṹ*/
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];	/*�������*/
	int r;							/*����λ��*/
	int n;							/*�������*/
}PTree;

