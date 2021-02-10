//8 7
//19 15 10 17 16 11 13 14 => 15

/*
unsigned int search(unsigned int* arr)
{
	int max = arr[n - 1];
	int add = 0;
	int i = 0;
	for (i = 0; i < max; i++)
	{
		add = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > i)
			{
				add = add + (arr[j] -i);
			}
		}

		if (add == m)
		{
			break;
		}
		else if (add < m)
		{
			i = i - 1;
			break;
		}
	}

	return i;
}
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n = 0, m = 0;


unsigned int search(vector<long long>& arr)
{
	long long max = *max_element(arr.begin(), arr.end());
	long long min = 0 , mid = (min + max) / 2;
	long long add = 0;
	long long result = 0;

	while (max >= min)
	{
		add = 0;
		mid = (min + max) / 2;

		for (int j = 0; j < n; j++)
		{
			if (arr[j] > mid)
			{
				add = add + (arr[j] - mid);
			}
		}

		if (add == m)
		{
			result = mid;
			break;
		}
		else if (add > m)
		{
			result = mid;
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}

	}
	return result;
}

int main()
{
	cin >> n >> m;

	vector<long long> arr;

	long long temp = 0;
	for (int i = 0; i < n; i++)
	{	
		scanf("%lld", &temp);
		arr.push_back(temp);
	}

	//sort(arr, arr + n);

	long long res = search(arr);

	cout << res << endl;

	return 0;
}