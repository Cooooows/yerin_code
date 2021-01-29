#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	int cnt = 0;

	cin >> n;


	for (int h = 0; h < n+1; h++)
	{
		for (int m = 0; m < 60; m++)
		{
			for (int s = 0; s < 60; s++)
			{
				if ((h/10) == 3 || (h % 10) == 3)
				{
					cnt++;
				}
				else if ((m / 10) == 3 || m % 10 == 3)
				{
					cnt++;
				}
				else if ((s / 10) == 3 || s % 10 == 3)
				{
					cnt++;
				}
			}
		}
	}
	
	cout << cnt << endl;
}