#include "adjacency_list.h"

void CreateAGraph(AdjList* g, int flag)
{
	int i, j, k;
	EdgeNode* p;
	if (flag == 0)
		printf("������һ������ͼ��\n");
	else
		printf("������һ������ͼ��\n");

	printf("������ͼ�Ķ�����:");
	cin >> g->n;
	printf("������ͼ�ı���:");
	cin >> g->e;
	printf("\n������ͼ�ĸ�������Ϣ:\n");
	for (i = 0; i < g->n; i++)   /*������n������Ķ����*/
	{
		printf("��%d��������Ϣ:", i + 1);
		scanf("\n%c", &(g->adjlist[i].data)); /*���������Ϣ*/
		g->adjlist[i].firstedge = NULL;       /*��ʱ���ӱ�*/
	}

	printf("\n������ߵ���Ϣ,�����ʽΪ:m,n  ����m,nΪ��Ӧ�����±�\n");
	for (k = 0; k < g->e; k++) {
		printf("�������%d����:", k+1);
		scanf("\n%d,%d", &i, &j);

		/*�����Ϊi�Ľ����ӵ��ڽӱ���*/
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (p)
		{
			p->adjvex = j;
			p->next = g->adjlist[i].firstedge;
			g->adjlist[i].firstedge = p;

			/*�����Ϊj�Ľ����ӵ��ڽӱ���*/
			if (flag == 0) {
				p = (EdgeNode*)malloc(sizeof(EdgeNode));
				if (p)
				{
					p->adjvex = i;						/*�ڽӵ����Ϊ i*/
					p->next = g->adjlist[j].firstedge;  /*���½��p�嵽����vi�߱�ͷ*/
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
	printf("\nͼ���ڽӱ��ʾ����:\n�±� ���\n");
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
	int qu[MAX_VEX], front = 0, rear = 0;	/*����ѭ������*/

	EdgeNode* p;

	for (i = 0; i < g->n; i++)  /*�����ʱ��ȫ����Ϊ0*/
		visited[i] = 0;

	printf("[%c] ", g->adjlist[vi].data);

	visited[vi] = 1;
	rear = (rear + 1) % MAX_VEX;  /*��βָ�����*/
	qu[rear] = vi;  /*��vi���*/
	while (front != rear)  /*���Ӳ���ʱ*/
	{
		front = (front + 1) % MAX_VEX;  /*����*/
		v = qu[front]; /*����ͷԪ�س���,��������v*/
		p = g->adjlist[v].firstedge;  /*������v����һ���ڽӱ߶���ָ�븳��p*/
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)  /*��δ���ʹ�*/
			{
				visited[p->adjvex] = 1;        /*���������Ԫ����1,�ѷ���*/
				printf("[%c] ", g->adjlist[p->adjvex].data);  /*����������Ϣ*/
				rear = (rear + 1) % MAX_VEX;  /*��βָ�����*/
				qu[rear] = p->adjvex;		  /*��p��ָ�Ķ������*/
			}
			p = p->next;
		}
	}
}
