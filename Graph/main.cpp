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
	printf("������DFS��������ʼ����(д�±�)��");
	int index = 0;
	cin >> index;
	DFS(G, index, visited);
	putchar('\n');


	printf("������BFS��������ʼ����(д�±�)��");
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
	//��������ͼ
	CreateAGraph(g, 0);
	//����ڽӱ�
	DispAGraph(g);
	cout << "************Finished**********" << endl;

	cout << "**********Testing the traverse of adjacency list.************" << endl;
	printf("������ҪDFS�����Ķ����±꣺");
	cin >> f;
	printf("�Ӷ���%d��ʼ����DFS�ı�������Ϊ��", f);
	for (i = 0; i < g->n; i++)
	{
		visited_vertex[i] = 0;
	}
	DFS_AL(g, f);
	printf("\n");

	printf("������ҪBFS�����Ķ����±꣺");
	cin >> f;
	printf("�Ӷ���%d��ʼ����BFS�ı�������Ϊ��", f);
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