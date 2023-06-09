#include "default.h"

/*图*/

/*邻接矩阵（Adjacency Matrix Graph）*/
typedef struct
{
	VertexType vex[MAXVEX];			/*顶点表*/
	EdgeType arc[MAXVEX][MAXVEX];	/*邻接矩阵*/
	int numNodes, numEdges;			/*图中顶点数和边数*/
} AMGraph;							

/*创建无向网图的邻接矩阵表示*/
void CreateAMGraph(AMGraph* G)
{
	int i, j, k, w, v1, v2;
	printf("请输入顶点数和边数：");					
	scanf_s("%d %d", &G->numNodes, &G->numEdges);			/*输入顶点数和边数*/
	for (i = 0; i < G->numNodes; i++)					/*依次输入顶点信息*/
	{
		scanf_s("%s", &G->vex[i], 20);
	}
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;					/*邻接矩阵初始化，全部元素设置为无穷大*/
		}
	}
	for (k = 0; k < G->numEdges; k++)
	{
		/*直接输入邻接矩阵的i j*/
		printf("请输入边(vi, vj)上的下标i，下标j，权值w：");
		scanf_s("%d %d %d", &i, &j, &w);					/*输入边上的权值*/

		/*通过边所依附的顶点确定i j*/
		//printf("请输入一条边所依附的顶点以及权值：");
		//scanf("%d %d %d", &v1, &v2, &w);
		//i = LocateVex(*G, v1);							
		//j = LocateVex(*G, v2);							/*确定v1, v2在G中的位置*/

		G->arc[i][j] = w;								/*赋值权值*/
		G->arc[j][i] = G->arc[i][j];					/*因为是无向图，邻接矩阵对称*/
	}
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

int main()
{
	AMGraph G;
	CreateAMGraph(&G);

	return 0;
}