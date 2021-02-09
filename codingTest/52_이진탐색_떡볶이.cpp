//6 7
//19 15 10 17 16 11 13 14 => 15

//10 11 13 14 15 16 17 19

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0, m = 0;

unsigned int BS(unsigned int* _arr)
{
	int _start = 0;
	int _end = n - 1;
	int mid = 0, add = 0;
	while (1)
	{
		mid = (_start + _end) / 2;
		add = 0;

		for (int i = 0; i < n; i++)
		{
			if (_arr[i] > _arr[mid])
			{
				add += _arr[i] - _arr[mid];
			}
		}
		if (add == m)
		{
			break;
		}
		else if(add > m)
		{
			_start = mid + 1;
		}
		else
		{
			_end = mid - 1;
		}
	}

	return _arr[mid];
}

int main()
{
	cin >> n >> m;
	
	unsigned int* arr = new unsigned int[n];

	unsigned int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}

	sort(arr, arr+n);

	unsigned int res = BS(arr);

	cout << res << endl;

	return 0;
}