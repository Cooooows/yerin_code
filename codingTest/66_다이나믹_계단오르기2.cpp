#include <iostream>

using namespace std;

int main() {

	int n = 0;

	cin >> n;

	int* arr = new int[n+1];
	int* m = new int[n+1];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> n;
	for (int i = 1; i < n+1; i++) 
	{
		cin >> arr[i];
	}

	m[1] = arr[1];
	m[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) 
	{
		m[i] = max(arr[i] + arr[i - 1] + m[i - 3], arr[i] + m[i - 2]);
	}
	cout << m[n];

	return 0;
}