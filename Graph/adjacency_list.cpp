#include "adjacency_list.h"

void CreateAGraph(AdjList* g, int flag)
{
	int i, j, k;
	EdgeNode* p;
	if (flag == 0)
		printf("将建立一个无向图。\n");
	else
		printf("将建立一个有向图。\n");

	printf("请输入图的顶点数:");
	cin >> g->n;
	printf("请输入图的边数:");
	cin >> g->e;
	printf("\n请输入图的各顶点信息:\n");
	for (i = 0; i < g->n; i++)   /*生成有n个顶点的顶点表*/
	{
		printf("第%d个顶点信息:", i + 1);
		scanf("\n%c", &(g->adjlist[i].data)); /*读入项点信息*/
		g->adjlist[i].firstedge = NULL;       /*暂时不接边*/
	}

	printf("\n请输入边的信息,输入格式为:m,n  其中m,n为对应结点的下标\n");
	for (k = 0; k < g->e; k++) {
		printf("请输入第%d条边:", k+1);
		scanf("\n%d,%d", &i, &j);

		/*将编号为i的结点添加到邻接表中*/
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (p)
		{
			p->adjvex = j;
			p->next = g->adjlist[i].firstedge;
			g->adjlist[i].firstedge = p;

			/*将编号为j的结点添加到邻接表中*/
			if (flag == 0) {
				p = (EdgeNode*)malloc(sizeof(EdgeNode));
				if (p)
				{
					p->adjvex = i;						/*邻接点序号为 i*/
					p->next = g->adjlist[j].firstedge;  /*将新结点p插到顶点vi边表头*/
					g->adjlist[j].firstedge = p;
				}
			}
		}
	}
}

void DispAGraph(AdjList* g)
{
	int i;
	EdgeNode* p;
	printf("\n图的邻接表表示如下:\n下标 结点\n");
	for (i = 0; i < g->n; i++)
	{
		printf("%2d    [%c]", i, g->adjlist[i].data);
		p = g->adjlist[i].firstedge;

		while (p != NULL) {
			printf("-->[%c]", g->adjlist[p->adjvex].data);
			p = p->next;
		}
		printf("\n");
	}
}

void DFS_AL(AdjList* g, int vi)
{
	EdgeNode* p;
	printf("[%c] ", g->adjlist[vi].data);
	visited_vertex[vi] = 1;
	p = g->adjlist[vi].firstedge;
	while (p)
	{
		if (visited_vertex[p->adjvex] == 0)
			DFS_AL(g, p->adjvex);
		p = p->next;
	}
}

void BFS_AL(AdjList* g, int vi)
{
	int i, v, visited[MAX_VEX];
	int qu[MAX_VEX], front = 0, rear = 0;	/*定义循环队列*/

	EdgeNode* p;

	for (i = 0; i < g->n; i++)  /*将访问标记全部置为0*/
		visited[i] = 0;

	printf("[%c] ", g->adjlist[vi].data);

	visited[vi] = 1;
	rear = (rear + 1) % MAX_VEX;  /*队尾指针后移*/
	qu[rear] = vi;  /*将vi入队*/
	while (front != rear)  /*当队不空时*/
	{
		front = (front + 1) % MAX_VEX;  /*出队*/
		v = qu[front]; /*将队头元素出队,赋给顶点v*/
		p = g->adjlist[v].firstedge;  /*将顶点v的下一条邻接边顶点指针赋给p*/
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)  /*若未访问过*/
			{
				visited[p->adjvex] = 1;        /*访问数组该元素置1,已访问*/
				printf("[%c] ", g->adjlist[p->adjvex].data);  /*输出该项点信息*/
				rear = (rear + 1) % MAX_VEX;  /*队尾指针后移*/
				qu[rear] = p->adjvex;		  /*将p所指的顶点入队*/
			}
			p = p->next;
		}
	}
}
