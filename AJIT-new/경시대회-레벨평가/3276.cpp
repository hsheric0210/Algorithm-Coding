/*
[기초-배열연습] 2차원 배열 빗금 채우기 3-4
https://43.200.211.173/contest/19/problem/3276
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, i, j, c, d, x, y, ** arr;
int main()
{
	cin >> n >> m;
	arr = new int* [n];
	for (i = 0; i < n; i++)
		arr[i] = new int[m] {0, };

	i = 0; j = m - 1;
	arr[i][j] = ++c;
	while (true)
	{
		i--; j--;
		if (i < 0 || j < 0)
		{
			// if oob occurs


			d++; // increment oob count
			if (d >= n) // 만약 더 이상 아래로 내려갈 수 없다면 (아래로 내려가게 되면 oob 발생), 대신 왼쪽으로 간다
			{
				i = n - 1;
				j = m - (d - n) - 2;
			}
			else
			{
				i = d;
				j = m - 1;
			}
		}
		arr[i][j] = ++c;

		if (i == n - 1 && j == 0)
		{
			for (y = 0; y < n; y++)
			{
				for (x = 0; x < m; x++)
					cout << arr[y][x] << ' ';
				cout << endl;
			}
			return 0;
		}
	}
}