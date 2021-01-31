/*
	//map을 사용해서 해보자
	map<char, vector<int>> dir;

	dir['U'] = vector<int>{ -1,0 };
	dir['D'] = vector<int>{ 1,0 };
	dir['L'] = vector<int>{ 0,-1};
	dir['R'] = vector<int>{ 0,1 };
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int main()
{
	int n = 0;
	int x = 1, y = 1;
	string course;

	cin >> n;

	cin.ignore();

	getline(cin, course);

	for (int i = 0; i < course.length(); i = i+2)
	{
		if (course[i] == 'L')
		{
			if (y == 1)
			{
				continue;
			}
			y = y - 1;
		}
		else if (course[i] == 'R')
		{
			if (y == n)
			{
				continue;
			}
			y = y + 1;
		}
		else if (course[i] == 'U')
		{
			if (x == 1)
			{
				continue;
			}
			x = x - 1;
		}
		else if (course[i] == 'D')
		{
			if (x == n)
			{
				continue;
			}
			x = x + 1;
		}
		else
		{
			cout << "error" << endl;
			break;
		}

	}

	cout << x << " " << y << endl;
}
