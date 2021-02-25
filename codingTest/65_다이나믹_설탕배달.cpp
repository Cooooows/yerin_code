#include <iostream>

using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	int* sugar = new int[n+1]();

	for (int i = 0; i < n + 1; i++)
	{
		sugar[i] = 5001;
	}

	sugar[3] = 1;
	sugar[5] = 1;

	for (int i = 6; i < n + 1; i++)
	{
		sugar[i] = min(sugar[i], sugar[i - 3] + 1);
		sugar[i] = min(sugar[i], sugar[i - 5] + 1);
	}

	if (sugar[n] == 5001)
	{
		cout << -1;
	}
	else
	{
		cout << sugar[n];
	}


	return 0;
}