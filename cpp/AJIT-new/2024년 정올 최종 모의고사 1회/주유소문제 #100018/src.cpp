#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, N, M, A1[10005], A2[10005], AbsDistance[10005];
struct C { int dist, cost; };
deque<C>T;
C a, b, c;
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) cin >> A1[i];
	for (i = 0; i < N; i++) cin >> A2[i];
	for (i = 0; i < N; i++)T.push_back({ A1[i], A2[i] });
	T.push_back({ A1[N], 0x7fffffff }); // ������

	for (i=0;i<T.size();i++)AbsDistance[i] = (i > 0 ? AbsDistance[i - 1] : 0) + T[i].dist;

	// n = ���� ��ġ�� ���� #
	// k = ���� ���� ���ᷮ\
	// a = ���� ��ġ�� ����
	// z = ���� ���� ���
	a = T.front();
	k = M - T.front().dist;
	n = z = 0;
	while (true)
	{
		if (T.size() <= n + 1) break; // ���� ����

#ifndef ONLINE_JUDGE
		cout << "BEGIN @ City #" << n << "(dist=" << a.dist << ", cost=" << a.cost << ") remain_fuel=" << k << "\n";
#endif
		// ����ܰ� �� �� ���� ã��
		// (����ܰ� �� �� ����: ���� �������� �� �ִٰ� �����ϰ� ������ �̵��� �� ������ �� ���õ� �� ���� ������ ����ܰ����� �� �� ����ܰ��� ���� ù ��° ����)
		// p = ����ܰ� �� �� ������ ����ܰ�
		// x = ����ܰ� �� �� ���� #
		l = 0; p = a.cost; x = -1;
		for (i = n + 1; i < T.size(); i++)
		{
			auto v = T[i];

			l += v.dist; // �ش� ���÷� �̵� (���� �Ҹ�)
			if (l > M) break; // ���� ���� ���¿��� �� �� �ִ� �ִ� �Ÿ� ����

			if (p > v.cost) // �ش� ���ð� ����ܰ� �� �� �������� �˻�
			{
				p = v.cost;
				x = i;
				break;
			}
		}

		// ���� �� �Ǵ� �Ϻ� ä���� �������� �ٷ� �� �� �ִ� ��� -> ���� �� ä�� �ʿ� ����
		r = AbsDistance[T.size() - 1] - AbsDistance[n];
#ifndef ONLINE_JUDGE
		cout << "Distance to Destination: " << r << '\n';
#endif
		if (x == -1 && r <= M)
		{
			// �������� �ٷ� ����
			x = T.size() - 1;
			p = -1;
		}

		if (x > 0) // ����ܰ� ���� ���� ����
		{
			q = p; // p�� ���

			// ���� ���� ���� ���÷� ���� ���� ��ŭ�� ���� ����
			y = max(0, l - k);
			p = y * a.cost;  z += p;
#ifndef ONLINE_JUDGE
			cout << "cheap city AVAIL. dist=" << l << " min_cost=" << q << " required_fuel=" << y << " cost=(+$" << p << " = " << z << ") pos=" << x << '\n';
#endif
			k += y;


			a = T[n = x]; // ���� ���� ���÷� �̵�
			k -= l; // ���� �Ҹ�
			continue;
		}

		// ����ܰ� ���� ���� no min avail -> full fill fuel & go to the next city

		// charge
		p = max(0, M - k) * a.cost;  z += p; // fully fill the fuel
		k = M;
#ifndef ONLINE_JUDGE
		cout << "cheap city N/A (fully fill fuel) cost=(+$" << p << " = " << z << ") next_pos=" << n + 1 << "\n";
#endif

		// move
		a = T[++n];
		k -= a.dist;
	}
	cout << z;

	return 0;
}
