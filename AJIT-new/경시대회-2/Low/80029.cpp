/*
풍선_ajit
https://43.200.211.173/contest/18/problem/80029
*/
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
typedef unsigned long long ll;
int n, m, i, j, * ans;
typedef struct _s
{
	int i, j, k;
} s;
s* arr;
int jcmp(s a, s b)
{
	return a.j > b.j;
}
int icmp(s a, s b)
{
	return a.i > b.i;
}
// in: 4 8
//     2 3 1 8
// out: 2 3 1 2   or   2 2 1 3
int main()
{
	cin >> n >> m;
	arr = new s[n];
	for (i = 0; i < n; i++)
	{
		cin >> j; arr[i] = { i, j, 0 };
	}
	stable_sort(arr, arr + n, jcmp);
	ll total = 0;
	int height = 0;
	for (i = 0; i < n; i++)
	{
		int hdelta = arr[i].j - height;
		int usage = 0;
		for (j = hdelta; j > 0; j--)
		{
			ll newtotal = total + (ll)(n - i) * j;
			if (newtotal <= m)
			{
				total = newtotal;
				usage = j;
				break;
			}
		}
		if (j == 0)
		{
			usage = 0;
			for (j = 0; j < (n - i) && total < m; j++)
			{
				total++;
				usage++;
			}
		}
		height += arr[i].j;
		arr[i].k = usage;
	}
	sort(arr, arr + n, icmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].k << ' ';
	cout << endl;
}