#include "default.h"
#include "Queue.h"

/*�ڽӾ����ʾͼ*/

boolean visited[MAXVEX];							/*���ʱ�־����*/
typedef int Patharc_D[MAXVEX];						/*���·���±������(Dijkstra)*/
typedef int ShortPathTable_D[MAXVEX];				/*�洢���������·����Ȩֵ��(Dijkstra)*/
typedef int Patharc_F[MAXVEX][MAXVEX];				/*���·���±������(Floyd)*/
typedef int ShortPathTable_F[MAXVEX][MAXVEX];		/*�洢���������·����Ȩֵ��(Floyd)*/

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

	G->numEdges = 16;
	G->numNodes = 9;

	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;					/*�ڽӾ����ʼ����ȫ��Ԫ������Ϊ�����*/
		}
	}

	//�Զ����ڽӾ���
	//G->arc[0][1] = 10;
	//G->arc[0][5] = 11;
	//G->arc[1][2] = 18;
	//G->arc[1][8] = 12;
	//G->arc[1][6] = 16;
	//G->arc[2][8] = 8;
	//G->arc[2][3] = 22;
	//G->arc[3][8] = 21;
	//G->arc[3][6] = 24;
	//G->arc[3][7] = 16;
	//G->arc[3][4] = 20;
	//G->arc[4][7] = 7;
	//G->arc[4][5] = 26;
	//G->arc[5][6] = 17;
	//G->arc[6][7] = 19;

	//���·���þ����Զ���Ȩ
	G->arc[0][1] = 1;
	G->arc[0][2] = 5;
	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;
	G->arc[3][4] = 2;
	G->arc[3][6] = 3;
	G->arc[4][5] = 3;

	G->arc[4][6] = 6;
	G->arc[4][7] = 9;
	G->arc[5][7] = 5;
	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;

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

/*Dijkstra�㷨����������G��v0�����ඥ������·���ͳ���*/
/*P[v]��ֵΪǰ�������±꣬D[v]��ʾv0��v�����·�����Ⱥ�*/
void ShortPath_Dijkstra(AMGraph G, int v0, Patharc_D* P, ShortPathTable_D* D)
{
	int v, w, k, min;
	int final[MAXVEX];				/*�洢���·��*/
	for (v = 0; v < G.numNodes; v++)
	{
		final[v] = 0;				/*��ʼ��Ϊδ֪���·��״̬*/
		(*D)[v] = G.arc[v0][v];		/*����v0�������ߵĶ������Ȩֵ*/
		(*P)[v] = -1;				/*��ʼ��·������PΪ-1*/
	}
	(*D)[v0] = 0;					/*v0��v0Ϊ0*/
	final[v0] = 1;

	/*��ʼ��ѭ����ÿ�����v0��ĳ������v�����·��*/
	for (v = 1; v < G.numNodes; v++)
	{
		min = INFINITY;				/*δ֪vo����С·��*/
		for (w = 0; w < G.numNodes; w++)
		{
			if (!final[w] && (*D)[w] < min)	/*Ѱ����v0����Ķ���*/
			{
				k = w;
				min = (*D)[w];				/*w������v0���*/
			}
		}
		final[k] = 1;						/*��Ŀǰ�ҵ������������Ϊ1*/
		for (w = 0; w < G.numNodes; w++)
		{
			/*�������v�����·������������·�����ȶ�*/
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))	/*˵���ҵ��˸��̵�·�����޸�D��P*/
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}

/*Floyd�㷨������ͼG�и�����v�����ඥ��w�����·��P[v][w]����Ȩ����D[v][w]*/
void ShortestPath_Floyd(AMGraph G, Patharc_F* P, ShortPathTable_F* D)
{
	int v, w, k;
	for (v = 0; v < G.numNodes; v++)
	{
		for (w = 0; w < G.numNodes; w++)
		{
			(*D)[v][w] = G.arc[v][w];		/*��ʼ��DΪ��ӦȨֵ*/
			(*P)[v][w] = w;					/*��ʼ��P*/
		}
	}

	for (k = 0; k < G.numNodes; k++)
	{
		for (v = 0; v < G.numNodes; v++)
		{
			for (w = 0; w < G.numNodes; w++)
			{
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])	/*��������±�Ϊk�����·����ԭ�������·������*/
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];	/*����ǰ������Ȩֵ���Сһ��*/
					(*P)[v][w] = (*P)[v][k];				/*·������Ϊ�����±�k�Ķ���*/
				}
			}
		}
	}
}

int main()
{
	int v, w, k;
	AMGraph G;
	CreateAMGraph(&G);

	/*MiniSpanTree_Prim(G);*/

	/*MiniSpanTree_Kruskal(G);*/

	//Dijkstra�㷨
	//int v0 = 0;
	//Patharc_D P;
	//ShortPathTable_D D; /* ��ĳ�㵽�����������·�� */
	//ShortPath_Dijkstra(G, v0, &P, &D);

	//Floyd�㷨
	Patharc_F P;
	ShortPathTable_F D;
	ShortestPath_Floyd(G, &P, &D);

	printf("����������·������:\n");
	for (v = 0; v < G.numNodes; ++v)
	{
		for (w = v + 1; w < G.numNodes; w++)
		{
			printf("v%d-v%d weight: %d ", v, w, D[v][w]);
			k = P[v][w];				/* ��õ�һ��·�������±� */
			printf(" path: %d", v);	/* ��ӡԴ�� */
			while (k != w)				/* ���·�������±겻���յ� */
			{
				printf(" -> %d", k);	/* ��ӡ·������ */
				k = P[k][w];			/* �����һ��·�������±� */
			}
			printf(" -> %d\n", w);	/* ��ӡ�յ� */
		}
		printf("\n");
	}

	printf("���·��D\n");
	for (v = 0; v < G.numNodes; ++v)
	{
		for (w = 0; w < G.numNodes; ++w)
		{
			printf("%d\t", D[v][w]);
		}
		printf("\n");
	}
	printf("���·��P\n");
	for (v = 0; v < G.numNodes; ++v)
	{
		for (w = 0; w < G.numNodes; ++w)
		{
			printf("%d ", P[v][w]);
		}
		printf("\n");
	}

	return 0;
}