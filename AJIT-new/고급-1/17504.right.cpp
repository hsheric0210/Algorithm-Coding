#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, g;

void hap(int p, int s) {
	int i, j;
	if (p == v.size()) return;
	for (i = p; i < v.size(); i++) {
		j = s + v[i];
		g.push_back(j);
		hap(i + 1, j);
	}
}

int main() {
	int i, j, k, l, m, n, p;
	scanf("%d", &n);
	for (i = 0, l = 0; i < n; i++) {
		scanf("%d", &m);
		l += m;
		v.push_back(m);
	}

	// '1' ä���
	vector<int> x(l + 1);
	hap(0, 0);
	sort(g.begin(), g.end());
	g.erase(unique(g.begin(), g.end()), g.end());
	for (i = 0, k = 0; i < g.size(); i++) {
		x[g[i]] = 1;
		k++;
	}
	// '2' ä���
	for (i = 1; i < g.size(); i++) {
		for (j = i - 1; j >= 0; j--) {
			p = g[i] - g[j];
			if (x[p] == 0) {
				x[p] = 1;
				k++;
			}
		}
	}

	printf("%d", l - k); // 1�� 2�� ä������ ���� ���� �� ä��� ��.
	return 0;
}