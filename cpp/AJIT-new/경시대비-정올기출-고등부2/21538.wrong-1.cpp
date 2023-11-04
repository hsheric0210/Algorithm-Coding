/*
초직사각형 - 정올2021
https://43.200.211.173/contest/17/problem/21538
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define L unsigned long long
using namespace std;
int i, j, k, l, n, p, q, r, s, t, u;
char c;
L v[4];
vector<int>a[4];
int main()
{
	cin >> n >> j >> v[0] >> v[1] >> v[2] >> v[3];
	for (i = 0; i < n; i++)
	{
		cin >> c >>t;
		a[c - 'A'].push_back(t);
	}

	for (i = 0; i < 4; i++)
		sort(a[i].begin(), a[i].end(), less<int>()); // 내림차순 (맨 마지막 원소를 pop하기 위해)

	for (i = 0; i < j; i++)
	{
		// 1-pass
		k = a[0].empty() ? -1 : (v[0] + a[0].back()) * v[1]; // A++ 후 AB
		cout << "A++ AB: " << k << endl;
		l = a[1].empty() ? -1 : v[0] * (v[1] + a[1].back()); // B++ 후 AB
		cout << "B++ AB: " << l << endl;
		p = (k < l); // 1-pass index: l이 더 크면 B(1), 아니면 A(0)

		// 2-pass
		k = a[2].empty() ? -1 : (v[2] + a[2].back()) * v[3]; // C++ 후 CD
		cout << "C++ CD: " << k << endl;
		l = a[3].empty() ? -1 : v[2] * (v[3] + a[3].back()); // D++ 후 CD
		cout << "D++ CD: " << l << endl;
		r = (k < l) + 2; // 2-pass index: l이 더 크면 D(3), 아니면 C(2)

		k = (v[p] + a[p].back()) * v[r]; // 1-pass MAX
		cout << (char)(p+'A') << "++ P1*P2: " << k << endl;
		l = v[p] * (v[r] + a[r].back()); // 2-pass MAX
		cout << (char)(r+'A') << "++ P1*P2: " << l << endl;
		t = (k < l) ? r : p; // final index
		cout << "final: " << t << endl;
		k = a[t].back();
		v[t] += k;
		cout << (char)('A' + t) << ' ' << k << endl;
		a[t].pop_back();
	}
}