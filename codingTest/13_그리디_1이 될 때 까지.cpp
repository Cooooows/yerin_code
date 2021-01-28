//입력값 : N(1이 되어야하는 수) K(나누는 수)
//문제 : 1. N이 K로 나누어지지 않으면 N에서 1을 뺸다. 2. N이 K로 나누어지면 나눈다. 1번, 2번을 N이 1이 될때까지 반복
//출력값 : N이 1이 될때까지 action을 행한 횟수
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
			int mod = N % K;	//나누고 남은수 == 앞으로 1을 뺄 수
			N = N - mod;		//나누어 지는 수가 되도록 뺴준다.
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
