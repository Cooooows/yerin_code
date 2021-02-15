//8
//1 2 3 3 1 1 1 2 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	vector<pair<int, int>> storage;

	cin >> n;

	int* arr = new int[n]();

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		storage.push_back(make_pair(input,i));
	}

	//int max = *max_element(storage.begin(), storage.end());
	sort(storage.begin(), storage.end());

	int add = 0;
	for (int i = n-1; i >= 0; i--)
	{
		if (arr[storage[i].second] == 0)	//안털었고
		{
			if (storage[i].second == 0)	//제일 첫번째 애면
			{
				if(storage[i+1].first == storage[i].first )	//나랑 오른쪽애랑 숫자가 같으면
				if (arr[storage[i].second + 1] == 0)	//오른쪽만 확인
				{
					add = add + storage[i].first;
					arr[storage[i].second] = -1;
				}
			}
			else if (storage[i].second == n - 1)
			{
				if (arr[storage[i].second - 1] == 0)	//왼쪽만
				{
					add = add + storage[i].first;
					arr[storage[i].second] = -1;
				}
			}
			else 
			{
				if (arr[storage[i].second - 1] == 0 && arr[storage[i].second + 1] == 0)	//내 양쪽도 안털렸어
				{
					add = add + storage[i].first;
					arr[storage[i].second] = -1;
				}
			}
			
		}

	}

	cout << add << endl;

	return 0;
}