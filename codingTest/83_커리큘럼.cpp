//위상 정렬
//방향 그래프의 모든 노드를 방향성에 거스르지 않도록 순서대로 나열하는 것
//위상 정렬은 DAG(Direct Acyclic Graph) : 순환하지 않는 그래프에서만 수행가능
//위상 정렬에서는 큐에 들어가는 순서에 따라 여러 가지 답이 존재할 수 있음
//모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재한다고 판한 할 수 있음
//스택을 활용한 DFS를 이용해 위상정렬 / 큐를 이용한 위상정렬이 있음

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
// 모든 노드에 대한 진입차수는 0으로 초기화
int indegree[100001];

//수강 시간 저장
int classtime[100001];

// 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화
vector<int> graph[100001];

// 위상 정렬 함수
void topologySort()
{
    vector<int> result; // 알고리즘 수행 결과를 담을 리스트
    queue<int> q;

    // 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0) //진입 차수가 0이면 큐에 삽입
        {
            q.push(i);  //노드 번호를 push
        }
    }

    while (!q.empty())  // 큐가 빌 때까지 반복
    {
        // 큐에서 원소 꺼내기
        int now = q.front();
        q.pop();
        //result[now] = classtime[now];
        printf("???");
        // 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
        for (int i = 0; i < graph[now].size(); i++)
        {
            result[i] = max(result[i], result[now] + classtime[i]);
            printf("result : %d, i : %d", result[i], i);
            indegree[graph[now][i]] -= 1;
            // 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
            if (indegree[graph[now][i]] == 0)
            {
                q.push(graph[now][i]);
            }
        }
    }

    // 위상 정렬을 수행한 결과 출력
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}

int main(void) {
    cin >> n;

    // 방향 그래프의 모든 간선 정보를 입력 받기
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