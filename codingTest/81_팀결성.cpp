#include <iostream>

using namespace std;

int n, m; // n : �л��� ������ ��ȣ(�л� �� = n+1), m : ���� ��
int parent[100001]; // �θ� ���̺� �ʱ�ȭ

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
    if (a < b)
    {
        parent[b] = a;   //�� ���� ���� �θ� ��带 ���� ����Ű�� ��
    }
    else
    {
        parent[a] = b;
    }
}

int main(void) 
{

    cin >> n >> m;

    // �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
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
            //����ġ��
            unionParent(a, b);
        }
        else if (cop == 1)
        {
            //���� �� ���� Ȯ��
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