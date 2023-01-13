/*
공주님의 정원
https://43.200.211.173/contest/17/problem/2996
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int ml[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int mlc[12] = { 0 };
typedef struct _R
{
	int begin; // inclusive
	int end; // EXCLUSIVE
} xy;
int dc(int m, int d)
{
	int t = 0;
	for (int i = 0; i < m - 1; i++)
		t += ml[i];
	t += d;
	return t;
}
int begcmp(xy a, xy b) { return a.begin < b.begin; }
int endcmp(xy a, xy b) { return a.end > b.end; }
int main()
{
	int n; cin >> n;
	int march1st = dc(3, 1), november30th = dc(11, 30);
	xy* arr = new xy[n];
	xy* arr2 = new xy[n];
	for (int i = 0; i < n; i++)
	{
		int mm, md, Mm, Md; cin >> mm >> md >> Mm >> Md;
		arr[i] = arr2[i] = { dc(mm, md), dc(Mm, Md) };
	}
	sort(arr, arr + n, begcmp);
	sort(arr2, arr2 + n, endcmp);
	int fcount = 1;
	int max = -1, max_index = -1;
	for (int i = 0; i < n; i++)
	{
		// 1월1일 until 3월1일
		if (arr[i].begin > march1st)
			break;
		if (arr[i].end > max)
		{
			max = arr[i].end;
			max_index = i;
		}
	}
	while (true)
	{
		if (max > november30th)
			break;
		int prev_max = max;
		max = 0;
		int _max_index = 0;
		for (int i = max_index + 1; i < n; i++)
		{
			// (max_index+1) until prev_max
			if (arr[i].begin >= prev_max + 1) // 내 1시간 30분을 날린 원흉: 여기에 +1을 반드시 붙여야 했었다.
				break;
			if (arr[i].end > max)
			{
				max = arr[i].end;
				_max_index = i;
				if (max > november30th) // this range is what we really needed
					break;
			}
		}
		if (max == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		max_index = _max_index;
		fcount++;
	}
	cout << fcount << endl;
}