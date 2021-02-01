#include <iostream>

using namespace std;

int main()
{
	char coord[3] = { NULL };

	cin.getline(coord, 3);

	char r = coord[0];
	char c = coord[1];

	int res = 8;

	if (r + 2 > 'h' || r - 2 < 'a')
	{
		res = res-2;
		if (c - 1 < '1')
		{ 

			res--;
		}
		if (c + 1 > '8')
		{
			res--;
		}
	}
	if (c - 2 < '1' || c + 2 > '8')
	{
		res = res - 2;
		if (r - 1 < 'a')
		{
			res--;
		}
		if (r + 1 > 'h')
		{
			res--;
		}
	}
	
	std::cout << res << endl;

	return 0;
}