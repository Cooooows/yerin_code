//�Է°� : N(1�� �Ǿ���ϴ� ��) K(������ ��)
//���� : 1. N�� K�� ���������� ������ N���� 1�� �A��. 2. N�� K�� ���������� ������. 1��, 2���� N�� 1�� �ɶ����� �ݺ�
//��°� : N�� 1�� �ɶ����� action�� ���� Ƚ��
#include <iostream>

using namespace std;

//babo

int main()
{
	int N, K;
	int res = 0;

	cin >> N >> K;

	while (N != 1)
	{
		if (N % K != 0)
		{
			int mod = N % K;	//������ ������ == ������ 1�� �� ��
			N = N - mod;		//������ ���� ���� �ǵ��� ���ش�.
			res = res + mod;
		}
		else
		{
			N = N / K;
			res++;
		}
	}

	cout << res << endl;
}


/*
int main()
{
	int N, K;
	int res = 0;

	cin >> N >> K;

	while (N != 1)
	{
		if (N % K == 0)
		{
			N = N / K;
			res++;
			continue;
		}
		N = N - 1;
		res++;
	}

	cout << res << endl;
}

*/
