#include <iostream>

using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	int* arr = new int[n+1]();
	int* m = new int[n+1]();

	for (int i = 1; i < n+1; i++)
	{
		cin >> arr[i];
	}

	m[n] = arr[n];
	m[n - 1] = arr[n] + arr[n - 1];
	m[n - 2] = max(m[n-1], m[n] + arr[n-2]);
	//m[n - 3] = max(arr[n - 3] + m[n - 1], arr[n - 3] + m[n - 2]);

	for (int i = n-3; i > 0; i--)
	{
		m[i] = max(m[i + 3] + arr[i+1] + arr[i], m[i + 2] + arr[i]);
		//cout << i << " : " << m[i] << endl;
	}

	/*
		for (int i = 1; i < n+1; i++)
	{
		cout << n-i << " : " << m[n - i] << endl;
	}
	*/

	cout << m[1];

	return 0;
}

