#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int** costs = new int* [n]();
	for (int i = 0; i < n; i++)
		costs[i] = new int[n]();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> costs[i][j];
		}
	}

	int** dp = new int* [n + 1]();
	for (int i = 0; i <= n; i++)
		dp[i] = new int[3]();

	for (int i = 1; i <= n; i++)
	{
		// 0 - Red
		// 1 - Green
		// 2 - Blue
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0]; // �̹��� Red�̸� ������ Green or Blue (�� ���� ���� ���� ���� ���� ������ �ȵ�)
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1]; // �̹��� Green�̸� ������ Red or Blue (�� ���� ���� ���� ���� ���� ������ �ȵ�)
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2]; // �̹��� Blue�̸� ������ Red or Green (�� ���� ���� ���� ���� ���� ������ �ȵ�)
	}

	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;

	for (int i = 0; i <= n; i++)
		delete[] dp[i];
	delete[] dp;

	for (int i = 0; i < n; i++)
		delete[] costs[i];
	delete[] costs;
}