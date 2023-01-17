#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct A { int input, number; }A;
bool cmp(const A& x, const A& y) {
	if (x.input < y.input) return true;
	else if (x.input == y.input && x.number < y.number) return true;
	else return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, k, l, m, n, x, y, z, sum = 0, cnt = 0;
	scanf("%d %d", &m, &n);
	int* G = (int*)malloc((m + 1) * sizeof(int));
	A* B = (A*)malloc((m + 1) * sizeof(A));
	for (i = 1; i <= m; i++) {
		scanf("%d", &G[i]);
		sum += G[i];
		B[i].input = G[i];
		B[i].number = i;
	}
	if (sum <= n) {
		for (i = 1; i <= m; i++) printf("%d ", G[i]);
		return 0;
	}
	sort(B + 1, B + m + 1, cmp);
	x = 0;
	for (i = 1; i <= m; i = j) {
		l = m - i + 1;
		k = B[i].input - x;
		if (n - (l * k) >= 0) {
			n -= (l * k);
			x = B[i].input;
		}
		else break;
		for (j = i + 1; j <= m; j++) {
			if (B[i].input < B[j].input) break;
		}
	}
	y = n / l;
	z = n % l;
	for (i = 1; i <= m; i++) {
		if (G[i] <= x) printf("%d ", G[i]);
		else {
			cnt++;
			if (cnt <= z) printf("%d ", x + y + 1);
			else printf("%d ", x + y);
		}
	}
	return 0;
}