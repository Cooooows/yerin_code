#include <iostream>

using namespace std;

int v, e; //v : 노드 수, e : 간선의 수
int parent[100001]; // 부모 테이블 초기화

// 특정 원소가 속한 집합을 찾기
int findParent(int x) 
{
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = findParent(parent[x]);   //연결된 모든 노드의 부모 노드가 root노드가 됨
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b) 
{
    a = findParent(a);  //두 원소의 부모 노드(root노드)를 찾음
    b = findParent(b);
    if (a < b) parent[b] = a;   //더 작은 수의 부모 노드를 같이 가리키게 됨
    else parent[a] = b;
}

int main(void) {
    
    cin >> v >> e;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union 연산을 각각 수행
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // 각 원소가 속한 집합 출력하기
    cout << "각 원소가 속한 집합 : ";
    for (int i = 1; i <= v; i++) 
    {
        cout << findParent(i) << ' ';
    }
    cout << '\n';

    // 부모 테이블 내용 출력하기
    cout << "부모 테이블: ";
    for (int i = 1; i <= v; i++) 
    {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}