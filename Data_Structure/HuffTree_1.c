#include "default.h"

/*哈夫曼树*/

#define Maxn 8	//定义题目中的结点个数
#define M 100;	//定义一个相对于权值很大的值

/*哈夫曼树结点结构*/
typedef struct HuffNode
{
	TElemtype data;
	int weight;				/*定义权值*/
	int parent;				/*定义双亲结点位置*/
	int lchild;
	int rchild;
} *HTNode;

/*哈夫曼树结构*/
typedef struct HuffTreeNode
{
	int n;					/*叶子结点个数*/
	int root;				/*定义树根*/
	HTNode ht;				/*定义指向结点的指针*/
} *HuffTree;

/*创建哈夫曼树*/
HuffTree CreateHuffTree(int n, int w[], char data[])
{
	HuffTree hpt;
	hpt = (HuffTree)malloc(sizeof(struct HuffTreeNode));
	if (!hpt)
		return;
	int i = 0, j = 0;			//定义循环变量
	int x1, x2, min1, min2;		//定义最小值下标、次小值下标、最小值、次小值
	int m = 2 * n - 1;			//数组总共m个元素
	hpt->ht = (HTNode)malloc(sizeof(struct HuffNode) * m);
	if (!hpt->ht)
		return;

	/*初始化哈夫曼树*/
	for (i = 0; i < m; i++)
	{
		hpt->ht[i].lchild = -1;		/*初始化叶节点左孩子*/
		hpt->ht[i].rchild = -1;		/*初始化叶节点右孩子*/
		hpt->ht[i].parent = -1;		/*初始化叶节点双亲*/
		if (i < n)
		{
			hpt->ht[i].weight = w[i];	/*赋值叶子结点的权值*/
			hpt->ht[i].data = data[i];	/*初始化叶子结点的data*/
		}
		else
		{
			hpt->ht[i].weight = -1;		/*初始化内部结点为-1*/
		}
	}

	/*初始化内部结点*/
	for (i = 0; i < n - 1; i++)			/*共产生n-1个结点*/
	{
		min1 = M;		/*初始化最小值*/
		min2 = M;
		x1 = -1;		/*初始化下标*/
		x2 = -1;
		for (j = 0; j < n + i; j++)
		{
			/*找到最小值下标赋值给x1, 最小值赋值给min1*/
			if (hpt->ht[j].weight < min1 && hpt->ht[j].parent == -1)
			{
				min2 = min1;
				x2 = x1;
				min1 = hpt->ht[j].weight;
				x1 = j;
			}
			/*找到次小值下标赋值给x2, 最次值赋值给min2*/
			else if (hpt->ht[j].weight < min2 && hpt->ht[j].parent == -1)
			{
				min2 = hpt->ht[j].weight;
				x2 = j;
			}
		}
		hpt->ht[n + i].weight = min1 + min2;	//初始化父结点的权值
		hpt->ht[n + i].lchild = x1;				//给父结点左孩子赋值
		hpt->ht[n + i].rchild = x2;				//给父结点右孩子赋值
		hpt->ht[x1].parent = n + i;				//给左孩子的父结点赋值
		hpt->ht[x2].parent = n + i;				//给右孩子的父结点赋值
	}
	hpt->root = 2 * n - 2;							//根节点位置
	hpt->n = n;										//哈夫曼树的叶子结点数
	return hpt;
}

//该函数用于输出叶子结点的哈夫曼编码
void PrintHuffCode(int n, HuffTree hpt)
{
	int i = 0, num = 0, j = 0;	//定义循环变量
	int parent = 0;				//定义父结点下标临时变量
	int times = 0;				//记录每个结点哈夫曼编码的长度
	int code[Maxn];
	for (i = 0; i < n; i++)		//循环给每个叶子结点进行编码
	{
		num = i;				//初始化用于控制循环的变量
		j = 0;					//初始化用于控制数组code的变量
		times = 0;
		while (hpt->ht[num].parent != -1)					//循环到当前结点的父结点为-1
		{
			parent = hpt->ht[num].parent;
			if (hpt->ht[parent].lchild == num)			//当前结点为父结点的左孩子，编码为0
			{
				code[j] = 0;
				j++;
				times++;									//编码长度加1
			}
			else if (hpt->ht[parent].rchild == num)		//当前结点为父结点的右孩子，编码为1
			{
				code[j] = 1;
				j++;
				times++;									//编码长度加1
			}
			num = parent;									//将num赋值为父结点下标
		}
		printf("%c:", hpt->ht[i].data);		//输出第i个叶子结点的data
		for (j = times - 1; j >= 0; j--)		//输出第i个叶子结点的哈夫曼编码
		{
			printf("%d", code[j]);
		}
		printf("\n");
	}
	return;
}

//该函数用于打印哈夫曼树的所有结点
void PrintHuffTree(HuffTree hpt, int n)
{
	for (int i = 0; i < 2 * n - 1; i++)
	{
		printf("第%d个结点:weight=%d  parent= %d  lchild=%d  rchild=%d\n", i, hpt->ht[i].weight, hpt->ht[i].parent, hpt->ht[i].lchild, hpt->ht[i].rchild);
	}
	return;
}


int main()
{
	int n = 8;
	int w[8] = { 5,29,7,8,14,23,3,11 };
	char data[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	HuffTree T = CreateHuffTree(n, w, data);

	return 0;
}