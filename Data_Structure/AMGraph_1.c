#include "default.h"
#include "Queue.h"

/*�ڽӾ����ʾͼ*/

/*�ڽӾ���Adjacency Matrix Graph��*/
typedef struct
{
	VertexType vex[MAXVEX];			/*�����*/
	EdgeType arc[MAXVEX][MAXVEX];	/*�ڽӾ���*/
	int numNodes, numEdges;			/*ͼ�ж������ͱ���*/
} AMGraph;							

/*�Ա߼�����Edge�ṹ*/
typedef struct
{
	int begin;			/*�����*/
	int end;			/*���յ�*/
	int weight;			/*Ȩֵ*/
}Edge;

/*����������ͼ���ڽӾ����ʾ*/
void CreateAMGraph(AMGraph* G)
{
	int i, j, k, w, v1, v2;
	//printf("�����붥�����ͱ�����");					
	//scanf_s("%d %d", &G->numNodes, &G->numEdges);			/*���붥�����ͱ���*/
	//for (i = 0; i < G->numNodes; i++)					/*�������붥����Ϣ*/
	//{
	//	scanf_s("%s", &G->vex[i], 20);
	//}

	G->numEdges = 15;
	G->numNodes = 9;

	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;					/*�ڽӾ����ʼ����ȫ��Ԫ������Ϊ�����*/
		}
	}

	//�Զ����ڽӾ���
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	//�Գ�
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = i; j < G->numNodes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

	//for (k = 0; k < G->numEdges; k++)
	//{
	//	/*ֱ�������ڽӾ����i j*/
	//	printf("�������(vi, vj)�ϵ��±�i���±�j��Ȩֵw��");
	//	scanf_s("%d %d %d", &i, &j, &w);					/*������ϵ�Ȩֵ*/

	//	/*ͨ�����������Ķ���ȷ��i j*/
	//	//printf("������һ�����������Ķ����Լ�Ȩֵ��");
	//	//scanf("%d %d %d", &v1, &v2, &w);
	//	//i = LocateVex(*G, v1);							
	//	//j = LocateVex(*G, v2);							/*ȷ��v1, v2��G�е�λ��*/

	//	G->arc[i][j] = w;								/*��ֵȨֵ*/
	//	G->arc[j][i] = G->arc[i][j];					/*��Ϊ������ͼ���ڽӾ���Գ�*/
	//}


}

/*��ͼG�в��Ҷ���u�������򷵻ض�����е��±꣬���򷵻�-1*/
int LocateVex(AMGraph G, VertexType u)
{
	int i;
	for (i = 0; i < G.numNodes; i++)
	{
		if (u == G.vex[i])
			return i;
	}
	return -1;
}

boolean visited[MAXVEX];							/*���ʱ�־����*/

/*�ڽӾ����������ȱ���*/
void DFS(AMGraph G, int i)						// i ��ʾ��ʼ����
{
	int j;
	visited[i] = TRUE;
	printf("%c", G.vex[i]);
	for (j = 0; j < G.numNodes; j++)			/*���μ���ڽӾ���i���ڵ���*/
	{
		if (G.arc[i][j] != 0 && !visited[i])
			DFS(G, j);							/*j��i���ڽӵ㣬���jδ���ʣ���ݹ����DFS*/
	}
}

void DFSTraverse(AMGraph G)
{
	int i;
	for (i = 0; i < G.numNodes; i++)
		visited[i] = FALSE;						/*��ʼ��visited����*/
	for (i = 0; i < G.numNodes; i++)
		if (!visited[i])						/*��δ���ʵĶ������DFS����Ϊ��ͨͼ��ִ��һ��*/
			DFS(G, i);
}

/*Prim�㷨������С������*/
void MiniSpanTree_Prim(AMGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];							/*������ض����ߵ�Ȩֵ�±�*/
	int lowcost[MAXVEX];						/*������ض���ߵ�Ȩֵ*/
	lowcost[0] = 0;
	adjvex[0] = 0;

	for (i = 1; i < G.numNodes; i++)			/*ѭ�����±�Ϊ0�����ȫ������*/
	{
		lowcost[i] = G.arc[0][i];				/*��V0������֮�бߵ�Ȩֵ��������*/
		adjvex[i] = 0;							/*���Ի�adjvex��ΪV0���±�*/
	}
	
	for (i = 1; i < G.numNodes; i++)
	{
		min = INFINITY;
		j = 1; k = 0;
		while (j < G.numNodes)								/*ѭ��ȫ������*/
		{
			if (lowcost[j] != 0 && lowcost[j] < min)		/*���Ȩֵ��Ϊ0��С��min*/
			{
				min = lowcost[j];							/*���õ�ǰȨֵ��Ϊ��Сֵ*/
				k = j;										/*������Сֵ���±����k*/
			}
			++j;
		}
		printf("(%d %d)\n", adjvex[k], k);					/*��ӡ��ǰ�������Ȩֵ��С�ı�*/
		lowcost[k] = 0;										/*����ǰ����Ȩֵ����Ϊ0���˶������������*/
		for (j = 1; j < G.numNodes; j++)					/*ѭ�����н��*/
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])/*����±�Ϊk�Ķ������ȨֵС�ڴ�ǰ����δ����������Ȩֵ*/
			{
				lowcost[j] = G.arc[k][j];					/*�򽫽�С��Ȩֵ����lowcost������Ӧλ��*/
				adjvex[j] = k;
			}
		}
	}
}

/*�ȽϺ���*/
int cmp(const void* a, const void* b)
{
	Edge* pa = (Edge*)a;
	Edge* pb = (Edge*)b;
	int num1 = pa->weight;
	int num2 = pb->weight;

	return num1 - num2;
}

/*��ʼ��������*/
void InitEdge(Edge* edge, AMGraph G)
{
	int i, j;
	int k = 0;
	for (i = 0; i < G.numNodes; i++)
	{
		for (j = 0; j < G.numNodes; j++)
		{
			if (G.arc[i][j] != INFINITY && i < j)
			{
				edge->begin = i;
				edge->end = j;
				edge->weight = G.arc[i][j];
				++edge;
			}
		}
	}
}

/*�������߶���β���±�*/
int Find(int* parent, int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*Kruskal�㷨������С������*/
void MiniSpanTree_Kruskal(AMGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];
	int parent[MAXVEX];		/*����һ���������жϱ�����Ƿ��γɻ�·*/
	
	InitEdge(edges, G);
	qsort(edges, G.numEdges, sizeof(Edge), cmp);					/*��������*/

	for (i = 0; i < G.numNodes; i++)
		parent[i] = 0;						/*��ʼ��Ϊ0*/
	for (i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)							/*���n������m��˵���˱�û�������ڵ��������γɻ�·*/
		{
			parent[n] = m;					/*���˱ߵĽ�β��������±�Ϊ���������У���ʾ�˶����Ѿ�����������*/
			printf("(%d %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

/*�ڽӾ���Ĺ�ȱ����㷨*/
void BFSTraverse(AMGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numNodes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);
	for (i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", G.vex[i]);
			EnQueue(&Q, i);							/*���˶������*/
			while (QueueEmpty(Q))					/*����ǰ���в�Ϊ��*/
			{
				DeQueue(&Q, &i);					/*������Ԫ�س��ӣ���ֵ��i*/
				for (j = 0; j < G.numNodes; j++)		
				{
					if (G.arc[i][j] != 0 && !visited[j])/*�ж��������㣬���뵱ǰ������ڣ����Ҵ�δ���ʹ�*/
					{
						visited[j] = TRUE;
						printf("%c ", G.vex[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}

int main()
{
	AMGraph G;
	CreateAMGraph(&G);

	/*MiniSpanTree_Prim(G);*/

	MiniSpanTree_Kruskal(G);

	return 0;
}