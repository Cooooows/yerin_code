#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int* arr, int target, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
		
	int mid = (start + end) / 2;
	if (arr[mid] == target)
	{
		return 1;
	}
	else if (arr[mid] > target)
	{
		return binarySearch(arr, target, start, mid - 1);
	}
	else
	{
		return binarySearch(arr, target, mid+1, end);
	}
	return -1;
}

int main()
{
	int n, m;

	cin >> n;

	int* arr = new int[n];

	int input = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+n);

	cin >> m;

	int* find = new int[m];
	for (int i = 0; i < m; i++)
	{	
		cin >> find[i];
	}
	

	//-----Ã£±â-----

	for (int i = 0; i < m; i++)
	{
		int result = binarySearch(arr, find[i], 0, n - 1);
		if (result == -1)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << 1 << endl;
		}
	}
	
	return 0;
}