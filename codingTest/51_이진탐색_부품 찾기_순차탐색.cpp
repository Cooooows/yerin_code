#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n = 0, m = 0;
	//int* arr = new int[n];
	//int* find = new int[m];

	vector<int> arr;
	vector<int> find;

	cin >> n;
	cin.ignore();

	string input;

	getline(cin, input);
	for (int i = 0; i < n*2; i = i+2)
	{
		arr.push_back(int(input[i]) - '0');
	}

	cin >> m;
	cin.ignore();

	string input2;
	getline(cin, input2);
	for (int i = 0; i < m*2; i = i+2)
	{
		find.push_back(int(input2[i]) - '0');
	}

	
	//----------------------Ã£±â-----


	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
		{

			if (find[i] == arr[j])
			{
				cout << "yes ";
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "no ";
		}
	}
}