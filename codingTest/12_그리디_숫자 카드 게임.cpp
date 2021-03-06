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
			if (input < min)	//각 행에서 가장 작은 값 찾기
			{
				min = input;
			}

		}
		if (min > max)	//각 행에서 가장 작은 값끼리 비교해서 큰 값만 남기기
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

	int** arr = new int* [N];	//2차원 배열 선언

	//2차원 배열 초기화
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

		for (int j = 0; j < M; j++)	//각 행에서 가장 작은 수 구하기
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
			}
		}

		if (max < min)	//가장 작은 애들끼리 비교하기
		{
			max = min;
		}
	}

	cout << max << endl;

	//메모리 해제 
	for (int i = 0; i < N; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

	}
*/
