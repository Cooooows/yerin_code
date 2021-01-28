#include <iostream>
#include <algorithm>

using namespace std;

//뭔가 이상해
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

	int first = arr[N-1];
	int second = arr[N-2];

	int cnt = int(M / (K + 1)) * K;	//first가 반복해서 더해지는 횟수
	cnt = cnt + (M % (K + 1));	//반복한 후에 나머지 더해지는 횟수

	int res = 0;
	res = cnt * first;
	res = res + (M - cnt) * second;

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
		if (cnt == K)
		{
			cnt = 0;
			res = res + next_max;
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
