/*
부녀회장이 될테야
https://www.acmicpc.net/problem/2775
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int k, n;
		cin >> k >> n;

		int** floors = new int* [k + 1];
		for (int i = 0; i <= k; i++)
			floors[i] = new int[n + 1];

		for (int a = 0; a <= k; a++)
		{
			if (a == 0)
			{
				// First floor initialization
				for (int b = 1; b <= n; b++)
					floors[a][b] = b;
			}
			else
			{
				// Non-first floor
				int* housePopulation = new int[n + 1]();
				memset(housePopulation, 0, (n + 1) * sizeof(int));

				// Build recurrence formula
				housePopulation[1] = floors[a - 1][1];
				for (int b = 2; b <= n; b++)
					housePopulation[b] = housePopulation[b - 1] + floors[a - 1][b];

				memcpy(floors[a], housePopulation, (n + 1) * sizeof(int));
			}
		}

		cout << floors[k][n] << endl;

		for (int i = 0; i <= k; i++)
			delete[] floors[i];
		delete[] floors;
	}
}