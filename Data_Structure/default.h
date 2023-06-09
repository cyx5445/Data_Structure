#define _CRT_SECURE_NO_WARNINGS 1
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0			
#define INFEASIBLE -1	
#define OVERFLOW -1;
#define MAX_SIZE 1000
#define MAX_TREE_SIZE 100		/*树最大空间*/
#define INFINITY 65535			/*代表无穷量∞*/
#define MAXVEX 100				/*图 最大顶点数*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int ElemType;			/*int*/
typedef int SElemType;			/*int*/
typedef char TElemtype;			/*char*/
typedef char VertexType;		/*图顶点类型(char)*/
typedef int EdgeType;			/*图权值类型(int)*/

typedef int Status;				/*int*/