#include"adjacency_list.h"
#include"adjacency_matrix.h"

static void TESTMatrix()
{
	cout << "***********Testing the creation of adjacency matrix.**************" << endl;
	Adj_matrix*G = new Adj_matrix;
	CreateAdj_matrix(G);
	DispAdj_matrix(G);
	cout << "************Finished**********" << endl;

	cout << "**********Testing the traverse of adjacency matrix.************" << endl;
	int* visited = (int*)malloc(sizeof(int) * (G->n));
	if (!visited)
		return;
	memset(visited, 0, sizeof(int) * (G->n));
	printf("请输入DFS遍历的起始顶点(写下标)：");
	int index = 0;
	cin >> index;
	DFS(G, index, visited);
	putchar('\n');


	printf("请输入BFS遍历的起始顶点(写下标)：");
	cin >> index;
	BFS(G, index);
	putchar('\n');
	cout << "************Finished**********" << endl;

	delete G;
}

static void test_adjacency_list()
{
	cout << "***********Testing the creation of adjacency list.**************" << endl;
	int i, f;
	AdjList*g = new AdjList;
	//建立无向图
	CreateAGraph(g, 0);
	//输出邻接表
	DispAGraph(g);
	cout << "************Finished**********" << endl;

	cout << "**********Testing the traverse of adjacency list.************" << endl;
	printf("请输入要DFS遍历的顶点下标：");
	cin >> f;
	printf("从顶点%d开始进行DFS的遍历序列为：", f);
	for (i = 0; i < g->n; i++)
	{
		visited_vertex[i] = 0;
	}
	DFS_AL(g, f);
	printf("\n");

	printf("请输入要BFS遍历的顶点下标：");
	cin >> f;
	printf("从顶点%d开始进行BFS的遍历序列为：", f);
	BFS_AL(g, f);
	printf("\n");
	cout << "************Finished**********" << endl;

	delete g;
}


int main()
{
	void(*p[2])() = { TESTMatrix,test_adjacency_list };
	//p[0]();
	p[1]();
	system("pause");
	return 0;
}