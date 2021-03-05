#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n, m;
vector<pair<int, int>> graph[100001];	//���� ��� ����
bool visited[100001];	//�湮����
int d[100001];	//�ִܰŸ�

int findSmallest()
{
	int minV = INF;
	int idx = 0;

	for (int i = 1; i < n + 1; i++)
	{
		if (d[i] < minV && visited[i] == false)
		{
			minV = d[i];
			idx = i;
		}
	}
	return idx;
}

void dijkstra(int start)
{
	d[start] = 0;
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++)	//start�� ����Ǿ� �ִ� �ֵ�
	{
		d[graph[start][i].first] = graph[start][i].second;	//start�� ����Ǿ� �ִ� ��� �Ÿ� �ʱ�ȭ
	}

	for (int i = 0; i < n - 1; i++)
	{
		int now = findSmallest();
		visited[now] = true;

		for (int j = 0; j < graph[now].size(); i++)
		{
			int cost = d[now] + graph[now][j].second;
			if (cost < d[graph[now][j].first])
			{
				d[graph[now][j].first] = cost;
			}
		}
	}
}


int main()
{
	int start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	fill_n(d, 100001, INF);

	dijkstra(start);

	int cnt = 0;
	int max = -1;
	for (int i = 1; i < n; i++)
	{
		if (d[i] != INF)
		{
			cnt++;
			if (d[i] > max)
			{
				max = d[i];
			}
		}
	}

	cout << cnt << " " << max;

	return 0;
}