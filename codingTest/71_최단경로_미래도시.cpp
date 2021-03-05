#include <iostream>

#define INF 1e9

using namespace std;

int main()
{
	int n, m;
	int graph[501][501];

	cin >> n >> m;

	for (int i = 0; i < m + 1; i++)
	{
		fill(graph[i], graph[i] + 501, INF);	//무한으로 초기화
	}

	//자기 자신은 0으로 초기화
	for (int i = 1; i < n + 1; i++)
	{
		graph[i][i] = 0;
	}

	int start, end;

	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		graph[start][end] = 1;
		graph[end][start] = 1;
	}


	int x, k;
	cin >> x >> k;
	
	for (int i = 1; i < n + 1; i++)
	{
		for (int a = 1; a < n + 1; a++)
		{
			for (int b = 1; b < n + 1; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
			}
		}
	}

	/*
		for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	*/


	if (graph[1][k] == INF || graph[k][x] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << graph[1][k] + graph[k][x];
	}

	return 0;
}

/*

5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5

*/