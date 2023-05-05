#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 501
int A[N][N], B[N], C[N];
using namespace std;
int main() {

	int i, j, k, l, m, n;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &C[i]);
		for (j = 1; j <= i; j++) {
			l = (i + j) / 2;
			for (k = j; k <= i; k++) {
				A[j][i] += (abs)(C[k] - C[l]);//j에서 i까지 구간에 우체국 1개의 최적값
			}
			if (j == 1) B[i] = A[j][i];//1에서i까지의 우체국 누적 최적값
		}
	}
	for (k = 2; k <= m; k++) {
		for (j = n; j >= k; j--) {
			for (i = j; i >= k; i--) {
				B[j] = min(B[j], B[i - 1] + A[i][j]);
			}
		}
	}
	printf("%d", B[n]);
	return 0;
}