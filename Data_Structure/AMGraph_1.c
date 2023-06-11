#include "default.h"
#include "Queue.h"

/*邻接矩阵表示图*/

boolean visited[MAXVEX];							/*访问标志数组*/
typedef int Patharc_D[MAXVEX];						/*最短路径下标的数组(Dijkstra)*/
typedef int ShortPathTable_D[MAXVEX];				/*存储到各点最短路径的权值和(Dijkstra)*/
typedef int Patharc_F[MAXVEX][MAXVEX];				/*最短路径下标的数组(Floyd)*/
typedef int ShortPathTable_F[MAXVEX][MAXVEX];		/*存储到各点最短路径的权值和(Floyd)*/

/*邻接矩阵（Adjacency Matrix Graph）*/
typedef struct
{
	VertexType vex[MAXVEX];			/*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX];	/*邻接矩阵*/
	int numNodes, numEdges;			/*图中顶点数和边数*/
} AMGraph;							

/*对边集数组Edge结构*/
typedef struct
{
	int begin;			/*边起点*/
	int end;			/*边终点*/
	int weight;			/*权值*/
}Edge;

/*创建无向网图的邻接矩阵表示*/
void CreateAMGraph(AMGraph* G)
{
	int i, j, k, w, v1, v2;
	//printf("请输入顶点数和边数：");					
	//scanf_s("%d %d", &G->numNodes, &G->numEdges);			/*输入顶点数和边数*/
	//for (i = 0; i < G->numNodes; i++)					/*依次输入顶点信息*/
	//{
	//	scanf_s("%s", &G->vex[i], 20);
	//}

	G->numEdges = 16;
	G->numNodes = 9;

	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;					/*邻接矩阵初始化，全部元素设置为无穷大*/
		}
	}

	//自定义邻接矩阵
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

	//最短路径用矩阵自定义权
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

	//对称
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = i; j < G->numNodes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

	//for (k = 0; k < G->numEdges; k++)
	//{
	//	/*直接输入邻接矩阵的i j*/
	//	printf("请输入边(vi, vj)上的下标i，下标j，权值w：");
	//	scanf_s("%d %d %d", &i, &j, &w);					/*输入边上的权值*/

	//	/*通过边所依附的顶点确定i j*/
	//	//printf("请输入一条边所依附的顶点以及权值：");
	//	//scanf("%d %d %d", &v1, &v2, &w);
	//	//i = LocateVex(*G, v1);							
	//	//j = LocateVex(*G, v2);							/*确定v1, v2在G中的位置*/

	//	G->arc[i][j] = w;								/*赋值权值*/
	//	G->arc[j][i] = G->arc[i][j];					/*因为是无向图，邻接矩阵对称*/
	//}


}

/*在图G中查找顶点u，存在则返回顶点表中的下标，否则返回-1*/
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

/*邻接矩阵的深度优先遍历*/
void DFS(AMGraph G, int i)						// i 表示起始顶点
{
	int j;
	visited[i] = TRUE;
	printf("%c", G.vex[i]);
	for (j = 0; j < G.numNodes; j++)			/*依次检查邻接矩阵i所在的行*/
	{
		if (G.arc[i][j] != 0 && !visited[i])
			DFS(G, j);							/*j是i的邻接点，如果j未访问，则递归调用DFS*/
	}
}

void DFSTraverse(AMGraph G)
{
	int i;
	for (i = 0; i < G.numNodes; i++)
		visited[i] = FALSE;						/*初始化visited数组*/
	for (i = 0; i < G.numNodes; i++)
		if (!visited[i])						/*对未访问的顶点调用DFS，若为连通图仅执行一次*/
			DFS(G, i);
}

/*Prim算法生成最小生成树*/
void MiniSpanTree_Prim(AMGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];							/*保存相关顶点间边的权值下标*/
	int lowcost[MAXVEX];						/*保存相关顶点边的权值*/
	lowcost[0] = 0;
	adjvex[0] = 0;

	for (i = 1; i < G.numNodes; i++)			/*循环除下标为0意外的全部顶点*/
	{
		lowcost[i] = G.arc[0][i];				/*将V0顶点与之有边的权值输入数组*/
		adjvex[i] = 0;							/*初试化adjvex都为V0的下标*/
	}
	
	for (i = 1; i < G.numNodes; i++)
	{
		min = INFINITY;
		j = 1; k = 0;
		while (j < G.numNodes)								/*循环全部顶点*/
		{
			if (lowcost[j] != 0 && lowcost[j] < min)		/*如果权值不为0且小于min*/
			{
				min = lowcost[j];							/*则让当前权值成为最小值*/
				k = j;										/*并将最小值的下标存入k*/
			}
			++j;
		}
		printf("(%d %d)\n", adjvex[k], k);					/*打印当前顶点边中权值最小的边*/
		lowcost[k] = 0;										/*将当前顶点权值设置为0，此顶点已完成任务*/
		for (j = 1; j < G.numNodes; j++)					/*循环所有结点*/
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])/*如果下标为k的顶点各边权值小于此前顶点未被加入树的权值*/
			{
				lowcost[j] = G.arc[k][j];					/*则将较小的权值存入lowcost数组相应位置*/
				adjvex[j] = k;
			}
		}
	}
}

/*比较函数*/
int cmp(const void* a, const void* b)
{
	Edge* pa = (Edge*)a;
	Edge* pb = (Edge*)b;
	int num1 = pa->weight;
	int num2 = pb->weight;

	return num1 - num2;
}

/*初始化集数组*/
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

/*查找连线顶点尾部下标*/
int Find(int* parent, int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*Kruskal算法生成最小生成树*/
void MiniSpanTree_Kruskal(AMGraph G)
{
	int i, n, m;
	Edge edges[MAXEDGE];
	int parent[MAXVEX];		/*定义一数组用来判断边与边是否形成环路*/
	
	InitEdge(edges, G);
	qsort(edges, G.numEdges, sizeof(Edge), cmp);					/*排序集数组*/

	for (i = 0; i < G.numNodes; i++)
		parent[i] = 0;						/*初始化为0*/
	for (i = 0; i < G.numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)							/*如果n不等于m，说明此边没有与现在的生成树形成环路*/
		{
			parent[n] = m;					/*将此边的结尾顶点放入下标为起点的数组中，表示此顶点已经在生成树中*/
			printf("(%d %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

/*邻接矩阵的广度遍历算法*/
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
			EnQueue(&Q, i);							/*将此顶点入队*/
			while (QueueEmpty(Q))					/*若当前队列不为空*/
			{
				DeQueue(&Q, &i);					/*将队首元素出队，赋值给i*/
				for (j = 0; j < G.numNodes; j++)		
				{
					if (G.arc[i][j] != 0 && !visited[j])/*判断其他顶点，若与当前顶点存在，边且从未访问过*/
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

/*Dijkstra算法，求有向网G的v0到其余顶点的最短路径和长度*/
/*P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度和*/
void ShortPath_Dijkstra(AMGraph G, int v0, Patharc_D* P, ShortPathTable_D* D)
{
	int v, w, k, min;
	int final[MAXVEX];				/*存储最短路径*/
	for (v = 0; v < G.numNodes; v++)
	{
		final[v] = 0;				/*初始化为未知最短路径状态*/
		(*D)[v] = G.arc[v0][v];		/*将与v0点有连线的顶点加上权值*/
		(*P)[v] = -1;				/*初始化路径数组P为-1*/
	}
	(*D)[v0] = 0;					/*v0至v0为0*/
	final[v0] = 1;

	/*开始主循环，每次求得v0到某个顶点v的最短路径*/
	for (v = 1; v < G.numNodes; v++)
	{
		min = INFINITY;				/*未知vo的最小路径*/
		for (w = 0; w < G.numNodes; w++)
		{
			if (!final[w] && (*D)[w] < min)	/*寻找离v0最近的顶点*/
			{
				k = w;
				min = (*D)[w];				/*w顶点离v0最近*/
			}
		}
		final[k] = 1;						/*将目前找到的最近顶点置为1*/
		for (w = 0; w < G.numNodes; w++)
		{
			/*如果经过v顶点的路径比现在这条路径长度短*/
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))	/*说明找到了更短的路径，修改D和P*/
			{
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}

/*Floyd算法，求网图G中各顶点v到其余顶点w的最短路径P[v][w]及带权长度D[v][w]*/
void ShortestPath_Floyd(AMGraph G, Patharc_F* P, ShortPathTable_F* D)
{
	int v, w, k;
	for (v = 0; v < G.numNodes; v++)
	{
		for (w = 0; w < G.numNodes; w++)
		{
			(*D)[v][w] = G.arc[v][w];		/*初始化D为对应权值*/
			(*P)[v][w] = w;					/*初始化P*/
		}
	}

	for (k = 0; k < G.numNodes; k++)
	{
		for (v = 0; v < G.numNodes; v++)
		{
			for (w = 0; w < G.numNodes; w++)
			{
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])	/*如果经过下标为k顶点的路径比原先两点的路径更短*/
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];	/*将当前两点间的权值设更小一个*/
					(*P)[v][w] = (*P)[v][k];				/*路径设置为经过下标k的顶点*/
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

	//Dijkstra算法
	//int v0 = 0;
	//Patharc_D P;
	//ShortPathTable_D D; /* 求某点到其余各点的最短路径 */
	//ShortPath_Dijkstra(G, v0, &P, &D);

	//Floyd算法
	Patharc_F P;
	ShortPathTable_F D;
	ShortestPath_Floyd(G, &P, &D);

	printf("各顶点间最短路径如下:\n");
	for (v = 0; v < G.numNodes; ++v)
	{
		for (w = v + 1; w < G.numNodes; w++)
		{
			printf("v%d-v%d weight: %d ", v, w, D[v][w]);
			k = P[v][w];				/* 获得第一个路径顶点下标 */
			printf(" path: %d", v);	/* 打印源点 */
			while (k != w)				/* 如果路径顶点下标不是终点 */
			{
				printf(" -> %d", k);	/* 打印路径顶点 */
				k = P[k][w];			/* 获得下一个路径顶点下标 */
			}
			printf(" -> %d\n", w);	/* 打印终点 */
		}
		printf("\n");
	}

	printf("最短路径D\n");
	for (v = 0; v < G.numNodes; ++v)
	{
		for (w = 0; w < G.numNodes; ++w)
		{
			printf("%d\t", D[v][w]);
		}
		printf("\n");
	}
	printf("最短路径P\n");
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