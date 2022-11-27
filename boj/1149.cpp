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
	
	int totalCostMin = 99999;
	int prev = -1;
	for (int k = 0; k < 3; k++)
	{
		prev = k;
		for (int i = 1; i < n; i++)
		{
			int* currentCost = costs[i];
			int min = 99999;
			int minIndex = -1;
			for (int j = 0; j < 3; j++)
			{
				if (currentCost[j] < min && prev != j)
				{
					min = currentCost[j];
					minIndex = j;
				}
			}
			if (min < totalCostMin)
				totalCostMin = min;
			prev = minIndex;
		}
	}

	for (int i = 0; i < n; i++)
		delete[] costs[i];
	delete[] costs;

	cout << totalCost << endl;
}