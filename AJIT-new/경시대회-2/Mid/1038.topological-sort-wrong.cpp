/*
숫자 고르기
https://43.200.211.173/contest/18/problem/1038
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
using namespace std;
int* arr; int* dp;
int n, i, j, k, M, m;
int main()
{
	cin >> n;
	arr = new int[n + 1]{ 0 };
	dp = new int[n + 1]{ 0 };
	for (i = 1; i <= n; i++) cin >> arr[i];

	// dump indexes
	cout << "indx=";
	for (i = 1; i <= n; i++)
		cout << i << ' ';
	cout << endl;

	// dump values
	cout << "data=";
	for (i = 1; i <= n; i++)
		cout << arr[i] << ' ';
	cout << endl;

	int sameCount = 0;
	deque<int> sames;
	for (i = 1; i <= n; i++)
	{
		if (arr[i] == i) // data==index인 항목들은 그 자체로 하나의 사이클이기에 미리미리 추가해놓기
		{
			sameCount++;
			sames.push_back(i);
		}
	}

	auto [min, Max] = minmax_element(arr + 1, arr + n + 1);
	m = *min;
	M = *Max;

	// make combination
	int* counts = new int[n] { 0 };
	deque<int>* visits = new deque<int>[n];
	for (i = 1; i <= n; i++)
	{
		deque<int> q;
		deque<int> visited;
		q.push_back(i);
		visited.push_back(i);
		cout << "push begin " << i << endl;
		int count = 1;
		while (!q.empty())
		{
			int fr = q.front();
			q.pop_front();
			if (fr >= 0 && fr < n + 1 && arr[fr] != fr && find(visited.begin(), visited.end(), arr[fr]) == visited.end())
			{
				cout << "found (Type I): " << arr[fr] << endl;
				q.push_back(arr[fr]);
				visited.push_back(arr[fr]);
			}
			if (n >= m && n <= M)
			{
				int index = find(arr, arr + n + 1, fr) - arr;
				if (arr[index] != index && find(visited.begin(), visited.end(), index) == visited.end())
				{
					cout << "found (Type II): " << index << endl;
					q.push_back(index);
					visited.push_back(index);
				}
			}
			count++;
		}
		counts[i - 1] = count;
		visits[i - 1] = visited;
	}

	int* maxpos = max_element(counts, counts + n);
	cout << *maxpos << endl;
	auto maxvisited = visits[maxpos - counts];
	while (!sames.empty())
	{
		maxvisited.push_back(sames.front());
		sames.pop_front();
	}
	sort(maxvisited.begin(), maxvisited.end());
	for (auto a = maxvisited.begin(); a != maxvisited.end(); a++)
		cout << *a << endl;
}