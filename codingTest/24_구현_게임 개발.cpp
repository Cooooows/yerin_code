/*
4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1

cnt = 3
*/

#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int r = 0, c = 0;	//���� ũ��
	int x = 0, y = 0;	//������ġ
	int d = 0; //����

	//int dir[4] = { 0,1,2,3 }; //��,��,��,�� ����
	int move_x[4] = { 0,1,0,-1 };
	int move_y[4] = { 1,0,-1,0 };

	cin >> r >> c;
	cin >> x >> y >> d;

	vector<vector<int>> map;
	vector<int> temp;

	int turn = 0;
	int cnt = 1;
	
	int input;
	for (int i = 0; i < r; i++) 
	{
		for (int j = 0; j < c; j++) 
		{
			cin >> input;
			temp.push_back(input);
		}
		map.push_back(temp);
		temp.clear();
	}
	
	map[x][y] = 2;

	while (1)
	{
		d = (d + 3) % 4;
		turn++;
		if (map[x + move_x[d]][y + move_y[d]] == 0)
		{
			x = x + move_x[d];
			y = y + move_y[d];
			map[x][y] = 2; //�湮������ 2
			turn = 0;	//���������ϱ� turn�� �ٽ� 0
			cnt++; //�̵������ϱ� cnt++
			
		}

		if (turn == 4)	//4�������� �� ��������
		{
			if (map[x - move_x[d]][y - move_y[d]] != 1)	//�ٴٸ� ������
			{
				break;
			}
			//�ڷ� �̵�
			x = x - move_x[d];
			y = y -  move_y[d];
			turn = 0;
		}

	}

	cout << cnt << endl;

	return 0;
}

