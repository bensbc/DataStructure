#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<malloc.h>
using namespace std;
#define MAX_VEX 100      /*���������ֵ*/

typedef char VertexType;     // ��������
__declspec(selectany) int visited_vertex[MAX_VEX];    /*��Ƕ����Ƿ��ѱ����ʵ�����*/

typedef struct node     
{
	int adjvex;         /*�ڽӵ���±�*/
	struct node* next;  /*ָ����һ�ڽӵ��ָ����*/
}EdgeNode;				/*�߽��*/


typedef struct vexnode  
{
	VertexType data;      /*����������*/
	EdgeNode* firstedge;  /*�ڽӵĵ�һ����*/
}VHeadNode;				  /*��������*/


typedef struct {
	VHeadNode adjlist[MAX_VEX]; /*�ڽӱ�Ľ�㼯*/
	int n, e;					/*������,����*/
} AdjList;						/*�ڽӱ�*/


/*��������ͼ*/
void CreateAGraph(AdjList* g, int flag);

/*���ͼ*/
void DispAGraph(AdjList* g);

/*���ڽӱ�洢��ͼ�Զ���vi��ʼ������ȱ�������*/
void DFS_AL(AdjList* g, int vi);

/*���ڽӱ�洢��ͼ�Զ���vi��ʼ������ȱ�������*/
void BFS_AL(AdjList* g, int vi);