#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[100001];


vector<pair<int, pair<int, int> > > edges; //cost, < a, b >
int result = 0;

// Ư�� ���Ұ� ���� ������ ã��
int findParent(int x)
{
    // ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ��
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
        cin >> a >> b >> cost;  //a -> b�� ���
        edges.push_back({ cost, {a, b} });
    }

    sort(edges.begin(), edges.end());   //cost �������� ����

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