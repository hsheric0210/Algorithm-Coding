//헬기착륙장
#include <iostream>
#include <algorithm>
#include <cmath>
#include<iomanip>
typedef unsigned long long ll;
#define LIMIT (ll)1000000007
using namespace std;
//비록 페인트의 최대 개수가 50000까지이지만, 50000=n(n+1)/2 에 대입해 보면 n은 320보다도 작다.
//즉 최대로 만들어 질 수 있는 동심원의 개수는 320개도 채 안된다는 말이다.
int i, j, k, l, p, q, r, s, t, T, A, B, S[1005], x, y;
ll Z, D[505][50005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// S[n] = 원 n개를 만들기 위해 필요한 최소 페인트 개수
	for (i = 1; i < 1000; i++)
		S[i] = i * (i + 1) / 2; // 등차수열 합공식

	// DP
	D[0][0] = 1;
	for (i = 1; i < 500; i++)
	{
		D[i][0] = 1;
		for (j = 1; j < 50000; j++)
			D[i][j] = (D[i - 1][j] + (i <= j ? D[i - 1][j - i] : 0)) % LIMIT;
	}

#ifndef ONLINE_JUDGE
	cout << "S-table(0~30):\n";
	for (i = 0; i < 30; i++)
		cout << S[i] << ' ';
	cout << "\nDP table (0~20):\n";
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++)
			cout << setw(3) << D[i][j] << ' ';
		cout << '\n';
	}
#endif

	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> A >> B;
		p = min(A, B), q = max(A, B);
		r = lower_bound(S, S + 1000, q) - S;
		if (S[r] > q) // lower_bound가 찾는 것은 Q보다 '같거나 더 큰 숫자'이기에, '같거나 그보다 바로 작은 숫자'를 구하기 위해서는 이와 같은 방법이 필요함
			r--;
		Z = 0;
		t = r;
		l = r + 1;
		for (y = 0; y <= p; y++)
		{
			if (q + y >= S[l])
			{
				cout << "Chg @ " << q + y << " l=" << l << '\n';
				r++;
				l++;
			}
			for (x = 1; x <= r; x++)
			{
				Z = (Z + D[x][y]) % LIMIT;
			}
		}
		cout << Z % LIMIT << '\n';
	}
	return 0;
}