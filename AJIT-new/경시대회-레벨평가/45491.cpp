/*
나무 자르기
https://43.200.211.173/contest/19/problem/45491
*/
#include<iostream>
#include<set>
using namespace std;
typedef struct _A
{
	int offset, length;
} A;
#define ASET set<A, decltype(acmp)*>
bool acmp(A a, A b) { return a.length < b.length; }
int i, j, k, l, m, n, o, p, q, * arr;
ASET* dp;
int main()
{
	cin >> l >> n;
	arr = new int[n];
	for (i = 0; i < n; i++)
		cin >> arr[i];
	dp = new ASET[l];
	for (i = 2; i <= l; i++) // l = piece_length
	{
		ASET prev = dp[i - 1];
		ASET cur;
		if (i == 2)
		{
			// 2-block init
			for (j = 0; j + i - 1 < l; j++)
				cur.insert({ j, i });
		}
		else
		{
			// 3~n blocks
			for (j = 0; j + i - 1 < l; j++)
			{
				// access previous

			}
		}
		dp[i] = cur;
	}
}