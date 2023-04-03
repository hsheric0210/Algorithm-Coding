/*
부품 생산 스케줄링
http://ajit.co.kr/contest/28/problem/80037
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, q, r;
typedef struct _thing {
	int i, v;
} thing;
thing p[1005];
typedef struct _dpe {
	vector<int> left, right;
	int at;
} dpentry;
dpentry dp[1005];
int sum(vector<int>v, int len)
{
	int m = 0;
	for (o = 0; o < len; o++) for (r = 0; r < o; r++) m += v[r]; //left
	return m;
}
int f(vector<int>left, vector<int>right)
{
	return sum(left, left.size()-1) + sum(right, right.size());
}
int main()
{
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> j;
		p[i] = { i, j };
	}
	sort(p, p + n, [](thing a, thing b) {return a.v < b.v; });

	// init @ n=1
	if (n >= 1)
	{
		vector<int>left, right;
		left.push_back(p[0].v);
		dp[0] = { left, right, 0 };
	}

	// init @ n=2
	if (n >= 2)
	{
		vector<int>left, right;
		left.push_back(p[1].v);
		right.push_back(p[0].v);
		dp[1] = { left, right, 0 };
	}

	// init @ n=3
	if (n >= 3)
	{
		vector<int>left_a, right_a, left_b, right_b;
		left_a = left_b = dp[1].left;
		right_a = right_b = dp[1].right;
		left_a.push_back(p[2].v);
		right_b.push_back(p[2].v);
		if (f(left_a, right_a) < f(left_b, right_b))
			dp[2] = { left_a, right_a, 0 }; // A
		else
			dp[2] = { left_b, right_b, 1 }; // B
	}

	for (i = 3; i < n; i++)
	{
		vector<int>lefts[4], rights[4];
		for (j = 0; j < 4; j++)
		{
			dpentry prev = dp[i - 1 - (j <= 1)];
			lefts[j] = prev.left;
			rights[j] = prev.right;
		}
		lefts[0].push_back(p[i].v); // A
		rights[1].push_back(p[i].v); // B
		lefts[2].push_back(p[i].v); // C
		rights[3].push_back(p[i].v); // D

		vector<pair<dpentry, int>> alist;
		for (k = 0; k < 4; k++)
			alist.push_back(make_pair<dpentry, int>({ lefts[k], rights[k], k }, f(lefts[k], rights[k])));
		auto& sel = *max_element(alist.begin(), alist.end(), [](pair<dpentry, int> a, pair<dpentry, int> b) {return a.second > b.second; });
		cerr << "selected " << sel.second << '\n';
		dp[i] = sel.first;
	}

	dpentry ans = dp[n - 1];
	auto l = ans.left;
	cout << f(ans.left, ans.right) << '\n';
	reverse(l.begin(), l.end());
	for (auto a = l.begin(); a != l.end(); a++)
		cout << *a << ' ';
	cout << '\n';
	for (auto a = ans.right.begin(); a != ans.right.end(); a++)
		cout << *a << ' ';
	cout << '\n';
	for (i=0,j=l.size();i<j;i++)
		cout << m - (sum(l, i)) << ' ';
	for (i = 0, j = ans.right.size(); i < j; i++)
		cout << sum(ans.right, i) << ' ';
}