#include "adjacency_matrix.h"

void CreateAdj_matrix(Adj_matrix* G)
{
	int i, j, k;
	char ch1, ch2;
	printf("请输入顶点数:");
	cin >> G->n;

	printf("请输入边数:");
	cin >> G->e;

	printf("请输入各项点信息(每个项点以回车作为结束):\n");
	for (i = 0; i < G->n; i++)
	{
		getchar();
		printf("输入第%d个顶点:", i + 1);
		cin >> G->vexs[i];
	}

	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++)
			G->edges[i][j] = 0;		/*将邻接矩阵元素全部置0*/

	/*添加边*/
	for (k = 0; k < G->e; k++)
	{
		getchar();
		printf("建立第%d条边(输入格式:顶点1,顶点2):", k + 1);
		scanf("%c,%c", &ch1, &ch2);
		for (i = 0; i < G->n; i++)
			for (j = 0; j < G->n; j++)
				if (ch1 == G->vexs[i] && ch2 == G->vexs[j])
				{
					G->edges[i][j] = 1;
					G->edges[j][i] = 1;		/*加上该语句为无向邻接矩阵,去掉为有向邻接矩阵*/
				}
	}

}

void DispAdj_matrix(Adj_matrix*G)
{
	int i, j;
	printf("\n图的邻接矩阵:\n  ");
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
	// 标记顶点是否被访问过的数组
	int* visited = (int*)malloc(sizeof(int) * G->n); // 注意：malloc的参数是字节数，所以需要 类型的大小*长度
	if (!visited)
		return;
	memset(visited, 0, sizeof(int) * G->n);  // sizeof(visited)求得的结果是指针的大小，不是数组的大小

	// 辅助队列
	queue<int>q;

	q.push(index);        // 第一个顶点入队
	visited[index] = 1;   // 标记
	
	while (!q.empty())
	{
		/*队列不为空时，出队并访问出队的顶点，让该顶点邻接的其他顶点入队，由此往复，直到队列为空*/
		int curr = q.front();
		q.pop();
		cout << G->vexs[curr] << "\t";
		// 遍历当前顶点的所有邻居  
		for (int i = 0; i < G->n; i++) {
			if (G->edges[curr][i] && !visited[i]) // 如果当前顶点与第i个顶点之间有边且第i个顶点未被访问过
			{
				q.push(i); // 将第i个顶点加入队列中  
				visited[i] = 1; // 标记第i个顶点为已访问  
			}
		}
	}

	free(visited);
}
