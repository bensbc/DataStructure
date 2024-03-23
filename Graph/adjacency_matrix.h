#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<memory.h>
#include<queue>
using namespace std;
#define MAX 100			 /*顶点个数最大值*/

typedef struct
{
	int n, e;				/*顶点数,边数*/
	char vexs[MAX];			/*顶点数组*/
	int edges[MAX][MAX];	/*边的邻接矩阵*/
}Adj_matrix;			    /*邻接矩阵*/

/*创建邻接矩阵*/
void CreateAdj_matrix(Adj_matrix* G);	

/*显示邻接矩阵*/
void DispAdj_matrix(Adj_matrix*G);

//深度优先遍历
void DFS(Adj_matrix*G, int index, int* visited);

//广度优先遍历
void BFS(Adj_matrix*G, int index);
