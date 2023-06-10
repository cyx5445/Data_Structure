#include "default.h"
#include "Queue.h"

/*邻接表表示图*/

typedef struct EdgeNode			/*邻接表边表结点*/
{
	int adjvex;					/*邻接点域，存储顶点对应的下标*/
	EdgeType info;				/*存储权值*/
	struct EdgeNode* next;		/*链域，指向下一个邻接点*/
} EdgeNode;

typedef struct VertexNode		/*顶点表结点*/
{
	VertexType data;
	EdgeNode* firstedge;		/*边表头指针*/
} VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges;		/*图中当前顶点数和边数*/
} GraphAdjList;

/*建立图的邻接表结构（无向网）*/
Status CreateGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode* e;
	printf("请输入图的顶点数和边数：");
	scanf_s("%d %d", &G->numNodes, &G->numEdges);
	for (i = 0; i < G->numNodes; i++)
	{
		printf("请输入顶点信息：");
		scanf_s("%s", &G->adjList[i].data, 20);				/*输入顶点信息*/
		G->adjList[i].firstedge = NULL;					/*初始化为空*/
	}

	for (k = 0; k < G->numEdges; k++)
	{
		printf("请输入边（vi, vj）上的顶点序号：");
		scanf_s("%d %d", &i, &j);
		/*头插法*/
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!e)
			return OVERFLOW;
		e->adjvex = j;									/*邻接点序号为j*/
		e->next = G->adjList[i].firstedge;				/*将e的指针指向当前顶点指向的结点*/
		G->adjList[i].firstedge = e;					/*将顶点的指针指向新节点e*/
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!e)
			return OVERFLOW;
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
	return OK;
}

boolean visited[MAXVEX];							/*访问标志数组*/

/*邻接表深度优先遍历递归算法*/
void DFS(GraphAdjList G, int i)
{
	EdgeNode* p;
	visited[i] = TRUE;
	printf("%c", G.adjList[i].data);
	p = G.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}

/*邻接表的深度遍历操作*/
void DFSTraverse(GraphAdjList G)
{
	int i;
	for (i = 0; i < G.numNodes; i++)
	{
		visited[i] = FALSE;
	}
	for (i = 0; i < G.numNodes; i++)
	{
		if (!visited)
			DFS(G, i);
	}
}

/*邻接表的广度遍历法*/
void BFSTraverse(GraphAdjList G)
{
	int i;
	EdgeNode* p;
	Queue Q;
	for (i = 0; i < G.numNodes; i++)
	{
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for (i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", G.adjList[i].data);
			EnQueue(&Q, i);
			while (QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = G.adjList[i].firstedge;
				while (p)
				{
					if (!visited[p->adjvex])			/*当此顶点未被访问*/
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", G.adjList[p->adjvex].data);
						EnQueue(&Q, i);
					}
					p = p->next;
				}
			}
		}
	}
}

int main()
{
	GraphAdjList G;
	CreateGraph(&G);
	BFSTraverse(G);

	return 0;
}