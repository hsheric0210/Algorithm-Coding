// Olympiad > �ѱ������ø��ǾƵ� > KOI 2003 > �ߵ�� 1��: ����ã��
// in progress...
#include<iostream>
#include<vector>
#define INF 0xBADF00D
using namespace std;
int i, j, k, l,N,M, D[105][105],p,q,r;
int main()
{
	cin >> N;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			D[i][j] = (i == j) ? 0 : INF;
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> j >> k;
		D[j][k] = 1; // ���� �׷���: j(bigger) -> k(smaller), ����ġ=1
	}
	//FW
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			for (k = 1; k <= N; k++)
				D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
	
	//CHECK: NO OUTGOING OR NO INCOMING
	for (i = 1; i <= N; i++)
	{
		p = 0, q = 0;
		for (j = 1; j < i; j++)
			p |= D[i][j] != INF;
		for(j=i+1; j <= N; j++)
			q |= D[i][j] != INF;
		if (!p || !q) r++;
	}
	cout << r;
	return 0;
}