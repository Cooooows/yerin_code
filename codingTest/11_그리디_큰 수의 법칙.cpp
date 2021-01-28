//�Է°� : N: �迭�� ũ��, M : ���ڰ� �������� Ƚ��, K : �ݺ� ������ Ƚ��
//���� : ���� �ε����� �ִ� ���ڸ� �ִ� K�� ��ŭ �ݺ��Ͽ� ���� �� ���� �� �迭�� ������ N�� ������ �� ���� ū �� ���ϱ�

#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int N, M, K;	//N: �迭�� ũ��, M : ���ڰ� �������� Ƚ��, K : �ݺ� ������ Ƚ��

	cin >> N;
	cin >> M;
	cin >> K;

	int* arr = new int[N];

	//arr �Է�
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//sorting
	sort(arr, arr + N);

	int first = arr[N-1];	//�迭���� ���� ū ��
	int second = arr[N-2];	//�迭���� ���� ���� ��

	int cnt = int(M / (K + 1)) * K;	//first�� �ݺ��ؼ� �������� Ƚ��
	cnt = cnt + (M % (K + 1));	//�ݺ��� �Ŀ� ������ �������� Ƚ��

	int res = 0;
	res = cnt * first;
	res = res + (M - cnt) * second;	//first�� �������� ���� ������ ������ ���� 2��°�� ū ���� ���Ѵ�.

	cout << res << endl;

	delete(arr);
}



/*
int main()
{
	int N, M, K;	//N: �迭�� ũ��, M : ���ڰ� �������� Ƚ��, K : �ݺ� ������ Ƚ��

	cin >> N;
	cin >> M;
	cin >> K;

	int* arr = new int[N];

	int max = -1;
	int max_idx = 0;
	int next_max = -1;

	int cnt = 0;
	int res = 0;

	//arr �Է� + ���� ū �� ã��
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			max_idx = i;
		}
	}

	//�� ��°�� ū �� ã��
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
		if (cnt == K)	//���� ū ���� K����ŭ �ݺ��Ǿ�����
		{
			cnt = 0;
			res = res + next_max;	//2��°�� ū �� ���ϱ�
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
	int N, M, K;	//N: �迭�� ũ��, M : ���ڰ� �������� Ƚ��, K : �ݺ� ������ Ƚ��

	cin >> N;
	cin >> M;
	cin >> K;

	int* arr = new int[N];

	int max = -1;
	int max_idx = 0;
	int k_cnt = 0;

	int res = 0;

	//arr �Է�
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

		//���� ū���� K�� �̻� �ݺ������� �������� ū ���� ã��
		if (k_cnt == K)
		{
			int next_max = -1;

			//�������� ū �� ���ϱ�
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
