//���� Ʈ��
//�׷������� ��� ��带 �����ϸ鼭 ����Ŭ�� �������� �ʴ� �κ� �׷���
//����Ʈ���� ������ �� = ����� �� - 1
//���� ª�� �������� �����Ͽ� ó��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����� ����(V)�� ����(Union ����)�� ����(E)
// ����� ������ �ִ� 100,000����� ����
int v, e;
int parent[100001]; // �θ� ���̺� �ʱ�ȭ
// ��� ������ ���� ����Ʈ��, ���� ����� ���� ����
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

    // �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
    for (int i = 1; i <= v; i++) 
    {
        parent[i] = i;
    }

    // ��� ������ ���� ������ �Է� �ޱ�
    for (int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;  //a -> b�� ���
        edges.push_back({ cost, {a, b} });
    }

    // ������ �������� ����
    sort(edges.begin(), edges.end());

    // ������ �ϳ��� Ȯ���ϸ�
    for (int i = 0; i < edges.size(); i++) 
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        // ����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ����
        if (findParent(a) != findParent(b)) 
        {
            unionParent(a, b);
            result += cost;
        }
    }

    cout << result << '\n';
}