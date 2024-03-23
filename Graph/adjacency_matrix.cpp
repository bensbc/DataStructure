#include "adjacency_matrix.h"

void CreateAdj_matrix(Adj_matrix* G)
{
	int i, j, k;
	char ch1, ch2;
	printf("�����붥����:");
	cin >> G->n;

	printf("���������:");
	cin >> G->e;

	printf("������������Ϣ(ÿ������Իس���Ϊ����):\n");
	for (i = 0; i < G->n; i++)
	{
		getchar();
		printf("�����%d������:", i + 1);
		cin >> G->vexs[i];
	}

	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++)
			G->edges[i][j] = 0;		/*���ڽӾ���Ԫ��ȫ����0*/

	/*��ӱ�*/
	for (k = 0; k < G->e; k++)
	{
		getchar();
		printf("������%d����(�����ʽ:����1,����2):", k + 1);
		scanf("%c,%c", &ch1, &ch2);
		for (i = 0; i < G->n; i++)
			for (j = 0; j < G->n; j++)
				if (ch1 == G->vexs[i] && ch2 == G->vexs[j])
				{
					G->edges[i][j] = 1;
					G->edges[j][i] = 1;		/*���ϸ����Ϊ�����ڽӾ���,ȥ��Ϊ�����ڽӾ���*/
				}
	}

}

void DispAdj_matrix(Adj_matrix*G)
{
	int i, j;
	printf("\nͼ���ڽӾ���:\n  ");
	for (i = 0; i < G->n; i++)
		printf("%5c", G->vexs[i]);
	printf("\n");
	for (i = 0; i < G->n; i++)
		printf(" -----");
	printf("\n");
	for (i = 0; i < G->n; i++)
	{
		printf("%c|", G->vexs[i]);
		for (j = 0; j < G->n; j++)
			printf("%5d", G->edges[i][j]);
		printf("\n |\n");
	}
}

void DFS(Adj_matrix*G, int index, int* visited)
{
	printf("%c\t", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->n; i++)
	{
		if (G->edges[index][i] == 1 && visited[i] != 1)
			DFS(G, i, visited);
	}
}

void BFS(Adj_matrix*G, int index)
{
	// ��Ƕ����Ƿ񱻷��ʹ�������
	int* visited = (int*)malloc(sizeof(int) * G->n); // ע�⣺malloc�Ĳ������ֽ�����������Ҫ ���͵Ĵ�С*����
	if (!visited)
		return;
	memset(visited, 0, sizeof(int) * G->n);  // sizeof(visited)��õĽ����ָ��Ĵ�С����������Ĵ�С

	// ��������
	queue<int>q;

	q.push(index);        // ��һ���������
	visited[index] = 1;   // ���
	
	while (!q.empty())
	{
		/*���в�Ϊ��ʱ�����Ӳ����ʳ��ӵĶ��㣬�øö����ڽӵ�����������ӣ��ɴ�������ֱ������Ϊ��*/
		int curr = q.front();
		q.pop();
		cout << G->vexs[curr] << "\t";
		// ������ǰ����������ھ�  
		for (int i = 0; i < G->n; i++) {
			if (G->edges[curr][i] && !visited[i]) // �����ǰ�������i������֮���б��ҵ�i������δ�����ʹ�
			{
				q.push(i); // ����i��������������  
				visited[i] = 1; // ��ǵ�i������Ϊ�ѷ���  
			}
		}
	}

	free(visited);
}
