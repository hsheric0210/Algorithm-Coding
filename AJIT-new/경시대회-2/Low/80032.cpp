/*
최장 증가 부분수열(Longest Increasing subsequence)
https://43.200.211.173/contest/18/problem/80032
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
int n, i, j;
int main()
{
	cin >> n;
	int* arr = new int[n]{0};
	int* lis_len = new int[n]{1};
	for (i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> *lis_data = new vector<int>[n];
	for (i = 0; i < n; i++)
	{
		int lenMax = 0;
		for (j = 0; j < i; j++)
			if (arr[i] < arr[j] && lis_len[j] > lenMax)
				lenMax = j;
		lis_len[i] = lis_len[lenMax] + 1;
		auto prev = lis_data[lenMax];
		for (auto a = prev.begin(); a != prev.end(); a++)
			lis_data[i].push_back(*a);
		lis_data[i].push_back(arr[i]);
	}
	int *Mpos = max_element(lis_len, lis_len + n);
	cout << *Mpos << endl;
	auto lis = lis_data[Mpos - lis_len];
	for (auto a = lis.begin(); a != lis.end(); a++)
		cout << *a << ' ';
	cout << endl;
}