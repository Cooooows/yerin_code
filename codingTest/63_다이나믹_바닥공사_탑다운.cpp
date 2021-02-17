#include <iostream>

using namespace std;

int* arr;

int tile(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (arr[n] > 0) return arr[n];

    arr[n - 1] = tile(n - 1);
    arr[n - 2] = tile(n - 2);
    return (arr[n - 1] + 2 * arr[n - 2]) % 796796;
}

int main()
{
	int n = 0;

	cin >> n;

	arr = new int[n + 1]();

    int res = tile(n);
    cout << res;
    
    return 0;
}