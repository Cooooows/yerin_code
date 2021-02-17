#include <iostream>

using namespace std;

int n;
int* arr;
int* money;

void currencyComposition(int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = arr[i]; j < m+1; j++)
		{
			money[j] = min(money[j], money[j - arr[i]] + 1);
		}
	}

	
}

int main()
{
	int m = 0;
	
	cin >> n >> m;
	
	arr = new int[n]();
	money = new int[m+1];

	for (int i = 0; i < m + 1; i++)
	{
		money[i] = 1001;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		money[arr[i]] = 1;
	}


	currencyComposition(m);

	if (money[m] == 1001)
	{
		cout << -1;
	}
	else
	{
		cout << money[m];
	}
	

	return 0;
}