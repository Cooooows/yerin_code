#include <iostream>

using namespace std;

int v, e; //v : ��� ��, e : ������ ��
int parent[100001]; // �θ� ���̺� �ʱ�ȭ

// Ư�� ���Ұ� ���� ������ ã��
int findParent(int x) 
{
    // ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = findParent(parent[x]);   //����� ��� ����� �θ� ��尡 root��尡 ��
}

// �� ���Ұ� ���� ������ ��ġ��
void unionParent(int a, int b) 
{
    a = findParent(a);  //�� ������ �θ� ���(root���)�� ã��
    b = findParent(b);
    if (a < b) parent[b] = a;   //�� ���� ���� �θ� ��带 ���� ����Ű�� ��
    else parent[a] = b;
}

int main(void) {
    
    cin >> v >> e;

    // �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union ������ ���� ����
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    // �� ���Ұ� ���� ���� ����ϱ�
    cout << "�� ���Ұ� ���� ���� : ";
    for (int i = 1; i <= v; i++) 
    {
        cout << findParent(i) << ' ';
    }
    cout << '\n';

    // �θ� ���̺� ���� ����ϱ�
    cout << "�θ� ���̺�: ";
    for (int i = 1; i <= v; i++) 
    {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}