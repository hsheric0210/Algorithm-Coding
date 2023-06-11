//���������
#include <iostream>
#include <algorithm>
#include <cmath>
#include<iomanip>
typedef unsigned long long ll;
#define LIMIT (ll)1000000007
using namespace std;
//��� ����Ʈ�� �ִ� ������ 50000����������, 50000=n(n+1)/2 �� ������ ���� n�� 320���ٵ� �۴�.
//�� �ִ�� ����� �� �� �ִ� ���ɿ��� ������ 320���� ä �ȵȴٴ� ���̴�.
int i, j, k, l, p, q, r, s, t, T, A, B, S[1005], x, y;
ll Z, D[505][50005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// S[n] = �� n���� ����� ���� �ʿ��� �ּ� ����Ʈ ����
	for (i = 1; i < 1000; i++)
		S[i] = i * (i + 1) / 2; // �������� �հ���

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
		if (S[r] > q) // lower_bound�� ã�� ���� Q���� '���ų� �� ū ����'�̱⿡, '���ų� �׺��� �ٷ� ���� ����'�� ���ϱ� ���ؼ��� �̿� ���� ����� �ʿ���
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