#include "default.h"
#include "Queue.h"

/*�ڽӱ��ʾͼ*/

typedef struct EdgeNode			/*�ڽӱ�߱���*/
{
	int adjvex;					/*�ڽӵ��򣬴洢�����Ӧ���±�*/
	EdgeType info;				/*�洢Ȩֵ*/
	struct EdgeNode* next;		/*����ָ����һ���ڽӵ�*/
} EdgeNode;

typedef struct VertexNode		/*�������*/
{
	VertexType data;
	EdgeNode* firstedge;		/*�߱�ͷָ��*/
} VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges;		/*ͼ�е�ǰ�������ͱ���*/
} GraphAdjList;

/*����ͼ���ڽӱ�ṹ����������*/
Status CreateGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode* e;
	printf("������ͼ�Ķ������ͱ�����");
	scanf_s("%d %d", &G->numNodes, &G->numEdges);
	for (i = 0; i < G->numNodes; i++)
	{
		printf("�����붥����Ϣ��");
		scanf_s("%s", &G->adjList[i].data, 20);				/*���붥����Ϣ*/
		G->adjList[i].firstedge = NULL;					/*��ʼ��Ϊ��*/
	}

	for (k = 0; k < G->numEdges; k++)
	{
		printf("������ߣ�vi, vj���ϵĶ�����ţ�");
		scanf_s("%d %d", &i, &j);
		/*ͷ�巨*/
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!e)
			return OVERFLOW;
		e->adjvex = j;									/*�ڽӵ����Ϊj*/
		e->next = G->adjList[i].firstedge;				/*��e��ָ��ָ��ǰ����ָ��Ľ��*/
		G->adjList[i].firstedge = e;					/*�������ָ��ָ���½ڵ�e*/
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!e)
			return OVERFLOW;
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
	return OK;
}

boolean visited[MAXVEX];							/*���ʱ�־����*/

/*�ڽӱ�������ȱ����ݹ��㷨*/
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

/*�ڽӱ����ȱ�������*/
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

/*�ڽӱ�Ĺ�ȱ�����*/
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
					if (!visited[p->adjvex])			/*���˶���δ������*/
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