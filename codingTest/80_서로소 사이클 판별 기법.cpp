#include <iostream>

using namespace std;

int v, e; //v : ��� ��, e : ������ ��
int parent[100001]; // �θ� ���̺� �ʱ�ȭ

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
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    bool cycle = false; // ����Ŭ �߻� ����

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        // ����Ŭ�� �߻��� ��� ����
        if (findParent(a) == findParent(b)) {
            cycle = true;
            break;
        }
        // ����Ŭ�� �߻����� �ʾҴٸ� ������(Union) ���� ����
        else {
            unionParent(a, b);
        }
    }

    if (cycle) 
    {
        cout << "����Ŭ�� �߻��߽��ϴ�." << '\n';
    }
    else 
    {
        cout << "����Ŭ�� �߻����� �ʾҽ��ϴ�." << '\n';
    }
}