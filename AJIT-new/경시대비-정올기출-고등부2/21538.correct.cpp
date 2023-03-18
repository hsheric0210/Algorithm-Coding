#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

int f(LL a, LL b, LL c, LL d, int s, int t) {
	if (b * c > a * d) return s;
	else return t;
}

int main() {
	LL A[4], p;
	vector<vector<LL> >v(4);
	int n, k, x, y, i, j;
	char ch, dap[5] = "ABCD";
	cin >> n >> k;
	for (i = 0; i < 4; i++) {
		cin >> A[i];
		v[i].push_back(-1);
	}
	for (i = 0; i < n; i++) {
		cin >> ch >> p;
		switch (ch) {
		case 'A': v[0].push_back(p); break;
		case 'B': v[1].push_back(p); break;
		case 'C': v[2].push_back(p); break;
		case 'D': v[3].push_back(p); break;
		}
	}
	for (i = 0; i < 4; i++) sort(v[i].begin(), v[i].end());
	//cout<<"\n\n";
	for (i = 0; i < k; i++) {
		x = f(A[0], A[1], A[0] + v[0].back(), A[1] + v[1].back(), 0, 1);
		y = f(A[2], A[3], A[2] + v[2].back(), A[3] + v[3].back(), 2, 3);
		j = f(A[x], A[y], A[x] + v[x].back(), A[y] + v[y].back(), x, y);
		cout << dap[j] << " " << v[j].back() << '\n';
		A[j] += v[j].back();
		v[j].pop_back();
	}
	return 0;
}