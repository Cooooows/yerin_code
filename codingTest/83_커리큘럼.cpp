//���� ����
//���� �׷����� ��� ��带 ���⼺�� �Ž����� �ʵ��� ������� �����ϴ� ��
//���� ������ DAG(Direct Acyclic Graph) : ��ȯ���� �ʴ� �׷��������� ���డ��
//���� ���Ŀ����� ť�� ���� ������ ���� ���� ���� ���� ������ �� ����
//��� ���Ҹ� �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ�� �����Ѵٰ� ���� �� �� ����
//������ Ȱ���� DFS�� �̿��� �������� / ť�� �̿��� ���������� ����

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
// ��� ��忡 ���� ���������� 0���� �ʱ�ȭ
int indegree[100001];

//���� �ð� ����
int classtime[100001];

// �� ��忡 ����� ���� ������ ��� ���� ���� ����Ʈ �ʱ�ȭ
vector<int> graph[100001];

// ���� ���� �Լ�
void topologySort()
{
    vector<int> result; // �˰��� ���� ����� ���� ����Ʈ
    queue<int> q;

    // ó�� ������ ���� ���������� 0�� ��带 ť�� ����
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0) //���� ������ 0�̸� ť�� ����
        {
            q.push(i);  //��� ��ȣ�� push
        }
    }

    while (!q.empty())  // ť�� �� ������ �ݺ�
    {
        // ť���� ���� ������
        int now = q.front();
        q.pop();
        //result[now] = classtime[now];
        printf("???");
        // �ش� ���ҿ� ����� ������ ������������ 1 ����
        for (int i = 0; i < graph[now].size(); i++)
        {
            result[i] = max(result[i], result[now] + classtime[i]);
            printf("result : %d, i : %d", result[i], i);
            indegree[graph[now][i]] -= 1;
            // ���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
            if (indegree[graph[now][i]] == 0)
            {
                q.push(graph[now][i]);
            }
        }
    }

    // ���� ������ ������ ��� ���
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}

int main(void) {
    cin >> n;

    // ���� �׷����� ��� ���� ������ �Է� �ޱ�
    for (int i = 1; i < n+1; i++)
    {
        cin >> classtime[i];
        int input = 0;
        while(1)
        {
            cin >> input;
            if (input == -1)
            {
                break;
            }
            indegree[i] += 1;
            graph[input].push_back(i);
        }
    }

    topologySort();
}

/*
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

*/