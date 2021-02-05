#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void doBFS(int start, vector<int> graph[], bool visited[]) {
	
	queue<int> que;

	que.push(start);
	visited[start] = true;

	while (!que.empty()) {
		int temp = que.front();
		que.pop();
		cout << temp;
		for (int i = 0; i < graph[temp].size(); i++) {

			// �湮���� �ʾҴٸ�
			if (visited[graph[temp][i]] == false) {
				que.push(graph[temp][i]);	//ť�� �־��ش�.
				visited[graph[temp][i]] = true;	//�湮�ߴٰ� ǥ��
			}
		}
	}

}

int main() {

	int n, m, start;
	cin >> n >> m >> start;

	vector<int>* graph = new vector<int>[n + 1];	//graph�� �����Ҵ�
	
	bool* visited = new bool[n + 1];
	fill(visited, visited + n + 1, false);

	int v1, v2;
	for (int i = 0; i < m; i++) {
		
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	doBFS(start, graph, visited);

	return 0;
}