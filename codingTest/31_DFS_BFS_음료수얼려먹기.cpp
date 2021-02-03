#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n = 0, m = 0;

vector<vector<int>> icePack;

int DFS(int x, int y)
{
	if (x >= n || x < 0 || y >= m || y < 0)
	{
		return -1;
	}

	if (icePack[x][y] == 0)
	{
		icePack[x][y] = 1;

		DFS(x - 1, y);	//╩С
		DFS(x + 1, y);	//го
		DFS(x, y - 1);	//аб
		DFS(x, y + 1);	//©Л
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	cin >> n >> m;
	cin.ignore();

	vector<int> temp;
	string input;
	for (int i = 0; i < n; i++)
	{
		getline(cin, input);
		for (int j = 0; j < m; j++)
		{
			temp.push_back(int(input[j])-48);
		}
		icePack.push_back(temp);
		temp.clear();
	}

	int res = 0;
	int ice = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res = DFS(i, j);
			if (res == 1)
			{
				ice++;
			}
		}
	}

	cout << ice << endl;
	return 0;
}

/*
4 5
00110
00011
11111
00000

15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111

*/