#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// dfs에 들어오면 '방문'한거로 판단
// 해당 위치에 check true로 해준다.
void doDFS(int start, vector<int> graph[], bool visited[]) {
	
	visited[start] = true;
	cout << start;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		// 방문하지 않았다면
		if (visited[next] == false) {
			doDFS(next, graph, visited);
		}
	}
}

int main() {

	//n = vertex의 수, start = DFS를 시작하는 vertex번호
	int n = 0, start = 0;
	cin >> n >> start;

	vector<int> * graph = new vector<int>[n+1];	//graph를 동적할당

	bool* visited = new bool[n + 1];

	fill(visited, visited + n + 1, false);

	//v1, v2, 모두 -1이 입력되면 연결 중지
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

	//숫자가 작은 것부터 방문하기 위해 sorting
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	doDFS(start, graph, visited);

	return 0;
}