#include "D:\Project\C\Data_Structure\Data_Structure\default.c"

/*树*/

/*结点结构*/
typedef struct PTNode
{
	TElemtype data;		/*结点数据*/
	int parent;			/*双亲位置*/
}PTNode;

/*树结构*/
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];	/*结点数组*/
	int r;							/*根的位置*/
	int n;							/*结点数量*/
}PTree;

