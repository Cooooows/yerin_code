#include <iostream>

using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	int* arr = new int[n + 1]();

	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i < n + 1; i++)
	{
		arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 796796;
	}

	//arr[n] = arr[n] % 10007;
	cout << arr[n];

	return 0;
}