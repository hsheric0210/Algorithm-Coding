#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int i, j, k, l, m, n, o, q, r;
typedef struct _thing {
	int i, v, k;
} thing;
thing p[1005];
typedef struct _dpe {
	vector<thing> left, right;
	int at;
} dpentry;
dpentry dp[1005];
int k_dp[1005];
int sum(vector<thing>v, int len)
{
	int m = 0;
	for (o = 0; o < len; o++) for (r = 0; r <= o; r++)
		m += v[r].v;
	return m;
}
int f(vector<thing>left, vector<thing>right)
{
	return sum(left, left.size() - 1) + sum(right, right.size());
}
int main()
{
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> j;
		p[i] = { i, j, 0 };
	}
	sort(p, p + n, [](thing a, thing b) {return a.v < b.v; });

	// init @ n=1
	if (n >= 1)
	{
		vector<thing>left, right;
		left.push_back(p[0]);
		dp[0] = { left, right, 0 };
	}

	// init @ n=2
	if (n >= 2)
	{
		vector<thing>left, right;
		left.push_back(p[1]);
		right.push_back(p[0]);
		dp[1] = { left, right, 0 };
		k_dp[1] = f(left, right);
	}

	// init @ n=3
	if (n >= 3)
	{
		vector<thing>left_a, right_a, left_b, right_b;
		left_a = left_b = dp[1].left;
		right_a = right_b = dp[1].right;
		left_a.push_back(p[2]);
		right_b.push_back(p[2]);
		int fa = f(left_a, right_a), fb = f(left_b, right_b);
		if (fa < fb)
		{
			dp[2] = { left_a, right_a, 0 }; // A
			k_dp[2] = fa;
		}
		else
		{
			dp[2] = { left_b, right_b, 1 }; // B
			k_dp[2] = fb;
		}
	}

	for (i = 3; i < n; i++)
	{
		vector<thing>lefts[4], rights[4];
		int* k_pos = new int[4] {0};
		for (j = 0; j < 4; j++)
		{
			dpentry prev = dp[i - 1 - (j <= 1)];
			lefts[j] = prev.left;
			rights[j] = prev.right;
			k_pos[j] = k_dp[i - 1 - (j <= 1)];
		}
		rights[0].push_back(p[i - 1]);
		k_pos[0] += accumulate(lefts[0].begin(), lefts[0].end(), 0, [](int sum, thing add) {return sum + add.v; }) + accumulate(rights[0].begin(), rights[0].end(), 0, [](int sum, thing add) {return sum + add.v; });
		lefts[0].push_back(p[i]); // A

		rights[1].push_back(p[i]); // B
		k_pos[1] += accumulate(lefts[1].begin(), lefts[1].end(), 0, [](int sum, thing add) {return sum + add.v; }) + accumulate(rights[1].begin(), rights[1].end(), 0, [](int sum, thing add) {return sum + add.v; });
		lefts[1].push_back(p[i - 1]);

		k_pos[2] += accumulate(lefts[2].begin(), lefts[2].end(), 0, [](int sum, thing add) {return sum + add.v; });
		lefts[2].push_back(p[i]); // C

		rights[3].push_back(p[i]); // D
		k_pos[3] += accumulate(rights[3].begin(), rights[3].end(), 0, [](int sum, thing add) {return sum + add.v; });

		vector<pair<dpentry, int>> alist;
		for (k = 0; k < 4; k++)
		{
			dpentry entry = { lefts[k], rights[k], k };
			auto fv = k_pos[k];
			alist.push_back(make_pair(entry, fv));
		}
		auto sel = max_element(alist.begin(), alist.end(), [](pair<dpentry, int> a, pair<dpentry, int> b) {return a.second > b.second; });
		k_dp[i] = k_pos[sel - alist.begin()];
		dp[i] = sel->first;
	}
	dpentry ans = dp[n - 1];
	auto l = ans.left;
	cout << k_dp[n-1] << '\n';
	reverse(l.begin(), l.end());
	vector<thing>buffer;
	int left_offset = m - accumulate(l.begin(), l.end(), 0, [](int total, thing add) {return total + add.v; });
	for (auto a = l.begin(); a != l.end(); a++)
		buffer.push_back({ a->i, a->v, left_offset + sum(l, a - l.begin()) });
	for (auto a = ans.right.begin(); a != ans.right.end(); a++)
		buffer.push_back({ a->i, a->v,m + sum(ans.right, a - ans.right.begin()) });
	sort(buffer.begin(), buffer.end(), [](thing a, thing b) {return a.i < b.i; });
	for (auto a = buffer.begin(); a != buffer.end(); a++)
		cout << a->k << ' ';
}