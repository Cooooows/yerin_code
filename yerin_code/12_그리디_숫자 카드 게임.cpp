//�Է°� N(���� ����), M(���� ����), N*M �࿭�� ��
//�� ���� �ּҰ��� ���� ū �� ã��
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
	int N, M;	//N: ���� ���� M : ���� ����

	cin >> N;
	cin >> M;

	int** arr = new int* [N];

	for (int i = 0; i < N; ++i)
	{
		arr[i] = new int [M];
		memset(arr[i], 0, sizeof(int) * M);
	}

	//arr �Է�
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

	// �޸� ������ 0���� �ʱ�ȭ }
	//�޸� ���� 
	for (int i = 0; i < N; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

	}
*/
