#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, S, t, N, C[5], P[5], D[5];
struct V { int index,dir, len; };
V T[10];
V M[2];
int main()
{
	cin >> N;
	for (i = 0; i < 6; i++)
	{
		cin >> p >> q;

		if (p >= 1 && p <= 2 && q > M[0].len) // east-west
		{
			M[0] = { i,p, q };
		}
		if (p >= 3 && p <= 4 && q > M[1].len) // south-north
		{
			M[1] = { i,p,q };
		}

		T[i] = { i,p,q };
	}

	S = M[0].len * M[1].len; // 큰 사각형
	
	// m = w-offset, n = h-offset
	if (M[0].dir == 1) // W.dir==1
	{
		if (M[1].dir == 3) // 3-1
		{
			m = M[0].index + 2;
			n = M[1].index - 2;
		}
		else // 1-4
		{
			m = M[0].index - 2;
			n = M[1].index + 2;
		}
	}
	else // W.dir==2
	{
		if (M[1].dir == 3) // 2-3
		{
			m = M[0].index - 2;
			n = M[1].index + 2;
		}
		else // 4-2
		{
			m = M[0].index + 2;
			n = M[1].index - 2;
		}
	}

	k = (m + 6) % 6;
	l = (n + 6) % 6;
#ifndef ONLINE_JUDGE
	cout << "m=" << M[0].index << " n=" << M[1].index << " a1=" << k << " a2=" << l << '\n';
#endif
	s = T[k].len * T[l].len; // 작은 사각형 (-> 가장 긴 두 변의 다음다음 또는 이전이전 두 변을 변으로 함)
	cout << (S - s) * N;
	return 0;
}
