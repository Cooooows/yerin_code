#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;	
	cin >> n;

	int* arr = new int[n]();	//â�� ���� ����
	int* m = new int[n]();	//�ִ밪 ģ��

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	m[0] = arr[0];
	m[1] = max(arr[0],arr[1]);

	for (int i = 2; i < n; i++)
	{
		m[i] = max(m[i - 1], m[i - 2] + arr[i]);
	}

	cout << m[n - 1];

	return 0;
}