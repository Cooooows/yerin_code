#include <iostream>

using namespace std;


int main()
{
	int N, K;
	int res = 0;

	cin >> N >> K;

	while (N != 1)
	{
		if (N % K != 0)
		{
			int mod = N % K;
			N = N - mod;
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
