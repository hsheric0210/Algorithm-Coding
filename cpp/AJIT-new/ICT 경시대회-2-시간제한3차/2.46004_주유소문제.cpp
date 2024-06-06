#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<list>
#include<numeric>
#include<deque>
#include<iomanip>
#include<cmath>
using namespace std;
int i, j, k, l, N, M, ci, t, T, D[10005]; // ci:currentCityIndex, t:currentFuelTank, T:totalCost, D:distanceSumArray
struct Z { int dist, cost; };
Z C[10005]; // C:Cities
int main()
{
	cin >> N >> M;
	for (i = 0; i <= N; i++) { cin >> j; D[i + 1] = D[i] + j; }
	for (i = 0; i < N; i++) { cin >> j; C[i] = { D[i + 1] - D[i],j }; }
	t = M - C[0].dist; // ù ��° ���ô� �׻� ����
	while (ci < N)
	{
		// ��������Ž�� (j=�������ðŸ�, k=��������index)
		for (i = ci + 1, j = 0, k = -1; i < N; i++)
		{
			j += C[i].dist;
			if (j > M) break;
			if (C[i].cost < C[ci].cost)
			{
				k = i;
				break;
			}
		}

		// ���������� �Ÿ� �˻�
		l = D[N + 1] - D[ci + 1];
		if (k < 0 && l < M)
		{
			k = N;
			j = l;
		}

		// �������ð� ����
		if (k > 0)
		{
			// �� �ʿ��� ��ŭ�� ����
			l = max(0, j-t) * C[ci].cost;
			T += l;
			t = max(t, j);

			// �������÷� �̵�
			ci = k;
			t -= j;
			continue;
		}

		// �������ð� ����

		// �������� ����
		l = (M - t) * C[ci].cost;
		T += l;
		t = M;

		// �ٷ� ���� ���÷� �̵�
		ci++;
		t -= C[ci].dist;
	}
	cout << T;
	return 0;
}
// 12�� 39��
