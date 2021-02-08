#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int n = 0, m = 0;

vector<vector<int>> maze;

void doBFS()
{
	queue<pair<int,int>> que;
	pair<int, int> temp = { 0, 0 };
	que.push(temp);

	int x = 0;
	int y = 0;

	int dir_x[4] = { 1,-1,0,0 };	//»óÇÏÁÂ¿ì
	int dir_y[4] = { 0,0,-1,1 };	

	while(que.empty() == 0)
	{
		temp = que.front();
		que.pop();

		x = temp.first;
		y = temp.second;

		for (int i = 0; i < 4; i++)
		{
			if (x+ dir_x[i] < 0 ||y + dir_y[i] < 0 || x + dir_x[i] > n - 1 || y + dir_y[i] > m - 1)
			{
				continue;
			}
			if (maze[x + dir_x[i]][y + dir_y[i]] == 1)
			{
				maze[x + dir_x[i]][y + dir_y[i]] = maze[x + dir_x[i]][y + dir_y[i]] + maze[x][y];
				temp = { x + dir_x[i],y + dir_y[i] };
				que.push(temp);
			}
		}
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
			temp.push_back(int(input[j]) - 48);
		}
		maze.push_back(temp);
		temp.clear();
	}

	doBFS();

	cout << maze[n-1][m-1] << endl;

	return 0;
}