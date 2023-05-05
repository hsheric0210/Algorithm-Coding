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
				A[j][i] += (abs)(C[k] - C[l]);//j���� i���� ������ ��ü�� 1���� ������
			}
			if (j == 1) B[i] = A[j][i];//1����i������ ��ü�� ���� ������
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