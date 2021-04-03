//신장 트리
//그래프에서 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프
//신장트리의 간선의 수 = 노드의 수 - 1
//가장 짧은 간선부터 선택하여 처리

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 노드의 개수(V)와 간선(Union 연산)의 개수(E)
// 노드의 개수는 최대 100,000개라고 가정
int v, e;
int parent[100001]; // 부모 테이블 초기화
// 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
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

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= v; i++) 
    {
        parent[i] = i;
    }

    // 모든 간선에 대한 정보를 입력 받기
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;  //a -> b의 비용
        edges.push_back({ cost, {a, b} });
    }

    // 간선을 비용순으로 정렬
    sort(edges.begin(), edges.end());

    // 간선을 하나씩 확인하며
    for (int i = 0; i < edges.size(); i++) 
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        // 사이클이 발생하지 않는 경우에만 집합에 포함
        if (findParent(a) != findParent(b)) 
        {
            unionParent(a, b);
            result += cost;
        }
    }

    cout << result << '\n';
}