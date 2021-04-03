#include <iostream>

using namespace std;

int n, m; // n : 학생의 마지막 번호(학생 수 = n+1), m : 연산 수
int parent[100001]; // 부모 테이블 초기화

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
    if (a < b)
    {
        parent[b] = a;   //더 작은 수의 부모 노드를 같이 가리키게 됨
    }
    else
    {
        parent[a] = b;
    }
}

int main(void) 
{

    cin >> n >> m;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int cop = 0;
    int a = 0, b = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> cop >> a >> b;
        if (cop == 0)
        {
            //팀합치기
            unionParent(a, b);
        }
        else if (cop == 1)
        {
            //같은 팀 여부 확인
            if (findParent(a) == findParent(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

}

/*
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
*/