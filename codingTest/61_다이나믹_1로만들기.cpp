#include <iostream>

using namespace std;

int* arr;

int makeOne(int n)
{
	if (n == 1)
	{
		arr[n] = 0;
	}
	else if (n == 2 || n == 3 || n == 5)
	{
		arr[n] = 1;
	}
	else if (arr[n] == 0)
	{
		if (n % 5 == 0 && n % 3 == 0 && n % 2 == 0)
		{
			int _min = min(makeOne(n / 2), makeOne(n / 3));
			arr[n] = 1+ min(_min, makeOne(n / 5));
			//arr[n] = 1 + min(makeOne(arr, n/5),makeOne(arr, n / 3), makeOne(arr, n / 2));
		}
		else if (n % 5 == 0)
		{
			arr[n] = 1 + min(makeOne(n / 5), makeOne(n - 1));
		}
		else if (n % 3 == 0)
		{
			arr[n] = 1 + min(makeOne(n / 3), makeOne(n - 1));
		}
		else if (n % 2 == 0)
		{
			arr[n] = 1 + min(makeOne(n / 2), makeOne(n - 1));
		}
		else 
		{
			arr[n] = 1 + makeOne(n - 1);
		}
	}
	return arr[n];
}


int main()
{
	int x = 0;
	cin >> x;
	arr = new int[x+1]();	//0으로 초기화하려면 뒤에 ()이거 해줘야됨

	cout << makeOne(x);

	return 0;
}