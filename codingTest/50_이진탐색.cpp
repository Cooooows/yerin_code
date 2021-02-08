#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if(arr[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
		return -1;
	}
}

int main()
{
	int n, target;
	vector<int> arr;

	//n : 원소의 개수, target : 찾는 값
	cin >> n >> target;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int result = binarySearch(arr, target, 0, n - 1);
	if (result == -1)
	{
		cout << "원소가 존재하지 않습니다." << endl;
	}
	else
	{
		cout << result + 1 << endl;
	}

	return 0;
}