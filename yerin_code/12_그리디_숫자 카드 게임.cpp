//입력값 N(행의 개수), M(열의 개수), N*M 행열의 값
//각 행의 최소값중 가장 큰 값 찾기
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;

	cin >> N;
	cin >> M;

	int max = -1;
	for (int i = 0; i < N; i++)
	{
		int min = 999;
		for (int j = 0; j < M; j++)
		{
			int input = 0;
			cin >> input;
			if (input < min)
			{
				min = input;
			}

		}
		if (min > max)
		{
			max = min;
		}
	}
	cout << max << endl;
}

/*
int main()
{
	int N, M;	//N: 행의 개수 M : 열의 개수

	cin >> N;
	cin >> M;

	int** arr = new int* [N];

	for (int i = 0; i < N; ++i)
	{
		arr[i] = new int [M];
		memset(arr[i], 0, sizeof(int) * M);
	}

	//arr 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int max = -1;
	for (int i = 0; i < N; i++)
	{
		int min = 999;

		for (int j = 0; j < M; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
			}
		}

		if (max < min)
		{
			max = min;
		}
	}

	cout << max << endl;

	// 메모리 공간을 0으로 초기화 }
	//메모리 해제 
	for (int i = 0; i < N; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

	}
*/
