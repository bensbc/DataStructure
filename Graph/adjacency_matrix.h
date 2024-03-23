#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<memory.h>
#include<queue>
using namespace std;
#define MAX 100			 /*����������ֵ*/

typedef struct
{
	int n, e;				/*������,����*/
	char vexs[MAX];			/*��������*/
	int edges[MAX][MAX];	/*�ߵ��ڽӾ���*/
}Adj_matrix;			    /*�ڽӾ���*/

/*�����ڽӾ���*/
void CreateAdj_matrix(Adj_matrix* G);	

/*��ʾ�ڽӾ���*/
void DispAdj_matrix(Adj_matrix*G);

//������ȱ���
void DFS(Adj_matrix*G, int index, int* visited);

//������ȱ���
void BFS(Adj_matrix*G, int index);
