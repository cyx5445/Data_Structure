#include "default.h"

/* 邻接矩阵结构 */
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef struct EdgeNode	/*边表结点*/
{
	int adjvex;			/*邻接点域*/
	int weight;
	struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode	/*顶点表结点*/
{
	int in;					/*顶点入度*/
	int data;
	EdgeNode* firstedge;	/*边表头指针*/
} VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
} graphAdjList, *GraphAdjList;

void CreateMGraph(MGraph* G)/* 构件图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = 20;
	G->numVertexes = 14;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	G->arc[0][4] = 1;
	G->arc[0][5] = 1;
	G->arc[0][11] = 1;
	G->arc[1][2] = 1;
	G->arc[1][4] = 1;
	G->arc[1][8] = 1;
	G->arc[2][5] = 1;
	G->arc[2][6] = 1;
	G->arc[2][9] = 1;
	G->arc[3][2] = 1;
	G->arc[3][13] = 1;
	G->arc[4][7] = 1;
	G->arc[5][8] = 1;
	G->arc[5][12] = 1;
	G->arc[6][5] = 1;
	G->arc[8][7] = 1;
	G->arc[9][10] = 1;
	G->arc[9][11] = 1;
	G->arc[10][13] = 1;
	G->arc[12][9] = 1;

}

/*拓扑排序*/
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;		/*用于栈指针下标*/
	int count = 0;		/*用于统计输出顶点的个数*/
	int* stack;
	stack = (int*)malloc(GL->numVertexes * sizeof(int));
	if (!stack)
		return OVERFLOW;

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in)
			stack[++top] = i;		/*将入度为0的顶点入栈*/
	}

	while (top != 0)
	{
		gettop = stack[top--];		/*出栈*/
		printf("%d -> ", GL->adjList[gettop].data);
		count++;
		for (e = GL->adjList[gettop].firstedge; e; e = e->next);	/*对此顶点的弧表遍历*/
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))					/*将k号顶点邻接点的入度-1*/
				stack[++top] = k;						/*若为0则入栈，以便下次循环输出*/
		}
	}

	if (count < GL->numVertexes)	/*如果小于，则存在环*/
		return ERROR;
	else
		return OK;
}

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G, GraphAdjList* GL)
{
	int i, j;
	EdgeNode* e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for (i = 0; i < G.numVertexes; i++) /* 读入顶点信息，建立顶点表 */
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; 	/* 将边表置为空表 */
	}

	for (i = 0; i < G.numVertexes; i++) /* 建立边表 */
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->adjvex = j;					/* 邻接序号为j  */
				e->next = (*GL)->adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				(*GL)->adjList[i].firstedge = e;		/* 将当前顶点的指针指向e  */
				(*GL)->adjList[j].in++;

			}
		}
	}

}

int main()
{
	MGraph G;
	GraphAdjList GL;
	CreateMGraph(&G);
	CreateALGraph(G, &GL);
	int res = TopologicalSort(GL);
	printf("%d", res);

	return 0;
}