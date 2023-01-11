/*
SCV 자원채취
https://43.200.211.173/contest/17/problem/80024
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <set>
using namespace std;
int main()
{
	FILE* in = fopen("INPUT.TXT", "r");
	FILE* out = fopen("OUTPUT.TXT", "r");

	char* line = new char[50]{ 0 };
	int n; fscanf(in, "%d", &n);
	bool* arr = new bool[n * n]{ 0 };
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			int b; fscanf(in, " %d", &b);
			arr[y * n + x] = b;
		}
	}

	int ptrPos = 0;
	set<int> visited;
	int expectedSum = atoi(line);
	fscanf(out, "%d", &expectedSum);
	cout << "read sum: " << expectedSum << endl;
	int sum = 0;
	while (true)
	{
		char ch = '\0';
		fscanf(out, " %c", &ch);
		if (!visited.contains(ptrPos))
			sum += arr[ptrPos];
		visited.insert(ptrPos);
		if (ch == 'D')
			ptrPos += n;
		else if (ch == 'R')
			ptrPos++;
		else
			break;
	}

	if (sum != expectedSum)
	{
		cout << "Sum Mismatched" << endl;
		cout << "Expected: " << expectedSum << endl;
		cout << "Actual: " << sum << endl;
		return 1;
	}

	cout << "All right: sum=" << sum << endl;
}