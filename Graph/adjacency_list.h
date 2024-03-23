#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<malloc.h>
using namespace std;
#define MAX_VEX 100      /*顶点数最大值*/

typedef char VertexType;     // 顶点类型
__declspec(selectany) int visited_vertex[MAX_VEX];    /*标记顶点是否已被访问的数组*/

typedef struct node     
{
	int adjvex;         /*邻接点的下标*/
	struct node* next;  /*指向下一邻接点的指针域*/
}EdgeNode;				/*边结点*/


typedef struct vexnode  
{
	VertexType data;      /*顶点数据域*/
	EdgeNode* firstedge;  /*邻接的第一条边*/
}VHeadNode;				  /*顶点类型*/


typedef struct {
	VHeadNode adjlist[MAX_VEX]; /*邻接表的结点集*/
	int n, e;					/*顶点数,边数*/
} AdjList;						/*邻接表*/


/*生成无向图*/
void CreateAGraph(AdjList* g, int flag);

/*输出图*/
void DispAGraph(AdjList* g);

/*用邻接表存储的图以顶点vi开始深度优先遍历函数*/
void DFS_AL(AdjList* g, int vi);

/*用邻接表存储的图以顶点vi开始广度优先遍历函数*/
void BFS_AL(AdjList* g, int vi);