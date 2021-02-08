#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
		else if (arr[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int n, m;
	vector<int> arr;
	vector<int> find;

	//n : 원소의 개수
	cin >> n;
	cin.ignore();

	string input;
	getline(cin, input);
	for (int i = 0; i < n * 2; i = i + 2)
	{
		arr.push_back(int(input[i]) - '0');
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	cin.ignore();

	string input2;
	getline(cin, input2);
	for (int i = 0; i < m * 2; i = i + 2)
	{
		find.push_back(int(input2[i]) - '0');
	}


	//-----찾기----

	for (int i = 0; i < m; i++)
	{
		int result = binarySearch(arr, find[i], 0, n - 1);
		if (result == -1)
		{
			cout << "no ";
		}
		else
		{
			cout << "yes ";
		}
	}

	return 0;
}