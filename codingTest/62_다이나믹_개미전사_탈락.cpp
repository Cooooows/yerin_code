//8
//1 1 3 3 2 1 1 2 
//8

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	vector<pair<int, int>> storage;	//â��

	cin >> n;

	int* arr = new int[n]();	//â�� �о����� Ȯ�����ִ� ģ��

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
		if (arr[storage[i].second] == 0)	//���о���
		{
			if (storage[i].second == 0)	//���� ù��° �ָ�
			{
				if(storage[i+1].first == storage[i].first )	//���� �����ʾֶ� ���ڰ� ������
				if (arr[storage[i].second + 1] == 0)	//�����ʸ� Ȯ��
				{
					add = add + storage[i].first;
					arr[storage[i].second] = -1;
				}
			}
			else if (storage[i].second == n - 1)
			{
				if (arr[storage[i].second - 1] == 0)	//���ʸ�
				{
					add = add + storage[i].first;
					arr[storage[i].second] = -1;
				}
			}
			else 
			{
				if (arr[storage[i].second - 1] == 0 && arr[storage[i].second + 1] == 0)	//�� ���ʵ� ���зȾ�
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