#include "default.h"

/*ͼ*/

/*�ڽӾ���Adjacency Matrix Graph��*/
typedef struct
{
	VertexType vex[MAXVEX];			/*�����*/
	EdgeType arc[MAXVEX][MAXVEX];	/*�ڽӾ���*/
	int numNodes, numEdges;			/*ͼ�ж������ͱ���*/
} AMGraph;							

/*����������ͼ���ڽӾ����ʾ*/
void CreateAMGraph(AMGraph* G)
{
	int i, j, k, w, v1, v2;
	printf("�����붥�����ͱ�����");					
	scanf_s("%d %d", &G->numNodes, &G->numEdges);			/*���붥�����ͱ���*/
	for (i = 0; i < G->numNodes; i++)					/*�������붥����Ϣ*/
	{
		scanf_s("%s", &G->vex[i], 20);
	}
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY;					/*�ڽӾ����ʼ����ȫ��Ԫ������Ϊ�����*/
		}
	}
	for (k = 0; k < G->numEdges; k++)
	{
		/*ֱ�������ڽӾ����i j*/
		printf("�������(vi, vj)�ϵ��±�i���±�j��Ȩֵw��");
		scanf_s("%d %d %d", &i, &j, &w);					/*������ϵ�Ȩֵ*/

		/*ͨ�����������Ķ���ȷ��i j*/
		//printf("������һ�����������Ķ����Լ�Ȩֵ��");
		//scanf("%d %d %d", &v1, &v2, &w);
		//i = LocateVex(*G, v1);							
		//j = LocateVex(*G, v2);							/*ȷ��v1, v2��G�е�λ��*/

		G->arc[i][j] = w;								/*��ֵȨֵ*/
		G->arc[j][i] = G->arc[i][j];					/*��Ϊ������ͼ���ڽӾ���Գ�*/
	}
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

int main()
{
	AMGraph G;
	CreateAMGraph(&G);

	return 0;
}