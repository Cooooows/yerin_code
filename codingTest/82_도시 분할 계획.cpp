#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[100001];


vector<pair<int, pair<int, int> > > edges; //cost, < a, b >
int result = 0;

// 특정 원소가 속한 집합을 찾기
int findParent(int x)
{
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void)
{
    cin >> v >> e;
    int max = -1;

    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;  //a -> b의 비용
        edges.push_back({ cost, {a, b} });
    }

    sort(edges.begin(), edges.end());   //cost 기준으로 정렬

    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            if (cost > max)
            {
                max = cost;
            }
            result += cost;
        }
    }

    cout << result - max << '\n';
}

/*
7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4
*/