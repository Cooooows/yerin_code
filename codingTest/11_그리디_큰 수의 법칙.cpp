//입력값 : N: 배열의 크기, M : 숫자가 더해지는 횟수, K : 반복 가능한 횟수
//문제 : 같은 인덱스에 있는 숫자를 최대 K번 만큼 반복하여 더할 수 있을 때 배열의 값들을 N번 더했을 때 가장 큰 수 구하기

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int N, M, K;	//N: 배열의 크기, M : 숫자가 더해지는 횟수, K : 반복 가능한 횟수

	cin >> N;
	cin >> M;
	cin >> K;

	int* arr = new int[N];

	//arr 입력
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//sorting
	sort(arr, arr + N);

	int first = arr[N-1];	//배열에서 가장 큰 수
	int second = arr[N-2];	//배열에서 가장 작은 수

	int cnt = int(M / (K + 1)) * K;	//first가 반복해서 더해지는 횟수
	cnt = cnt + (M % (K + 1));	//반복한 후에 나머지 더해지는 횟수

	int res = 0;
	res = cnt * first;
	res = res + (M - cnt) * second;	//first가 더해지는 수를 제외한 나머지 수는 2번째로 큰 수를 더한다.

	cout << res << endl;

	delete(arr);
}



/*
int main()
{
	int N, M, K;	//N: 배열의 크기, M : 숫자가 더해지는 횟수, K : 반복 가능한 횟수

	cin >> N;
	cin >> M;
	cin >> K;

	int* arr = new int[N];

	int max = -1;
	int max_idx = 0;
	int next_max = -1;

	int cnt = 0;
	int res = 0;

	//arr 입력 + 가장 큰 수 찾기
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			max_idx = i;
		}
	}

	//두 번째로 큰 수 찾기
	for (int i = 0; i < N; i++)
	{
		if (i == max_idx)
			continue;

		if (next_max < arr[i])
		{
			next_max = arr[i];
		}
	}


	for (int i = 0; i < M; i++)
	{
		if (cnt == K)	//가장 큰 수가 K번만큼 반복되었으면
		{
			cnt = 0;
			res = res + next_max;	//2번째로 큰 수 더하기
			continue;
		}
		cnt++;
		res = res + max;
	}

	cout << res << endl;
	delete(arr);
}
*/


/*
int main()
{
	int N, M, K;	//N: 배열의 크기, M : 숫자가 더해지는 횟수, K : 반복 가능한 횟수

	cin >> N;
	cin >> M;
	cin >> K;

	int* arr = new int[N];

	int max = -1;
	int max_idx = 0;
	int k_cnt = 0;

	int res = 0;

	//arr 입력
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			max_idx = i;
		}
	}


	for (int i = 0; i < M; i++)
	{

		//가장 큰수가 K번 이상 반복됐으면 다음으로 큰 수를 찾아
		if (k_cnt == K)
		{
			int next_max = -1;

			//다음으로 큰 수 구하기
			for (int j = 0; j < N; j++)
			{
				if (j == max_idx)
					continue;

				if (next_max < arr[j])
				{
					next_max = arr[j];
				}
			}
			res += next_max;
			k_cnt = 0;
			continue;
		}
		k_cnt++;
		res += max;
	}

	cout << res << endl;
	delete(arr);
}
*/
