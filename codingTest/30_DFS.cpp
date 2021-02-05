#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// dfs�� ������ '�湮'�Ѱŷ� �Ǵ�
// �ش� ��ġ�� check true�� ���ش�.
void doDFS(int start, vector<int> graph[], bool visited[]) {
	
	visited[start] = true;
	cout << start;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		// �湮���� �ʾҴٸ�
		if (visited[next] == false) {
			doDFS(next, graph, visited);
		}
	}
}

int main() {

	//n = vertex�� ��, start = DFS�� �����ϴ� vertex��ȣ
	int n = 0, start = 0;
	cin >> n >> start;

	vector<int> * graph = new vector<int>[n+1];	//graph�� �����Ҵ�

	bool* visited = new bool[n + 1];

	fill(visited, visited + n + 1, false);

	//v1, v2, ��� -1�� �ԷµǸ� ���� ����
	int v1, v2;
	while (1)
	{
		cin >> v1 >> v2;

		if (v1 == -1 && v1 == -1)
		{
			break;
		}
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	//���ڰ� ���� �ͺ��� �湮�ϱ� ���� sorting
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	doDFS(start, graph, visited);

	return 0;
}