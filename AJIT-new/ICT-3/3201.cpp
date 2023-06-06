// �������
#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;
int i, j, k, l, x, y, z, N, M, A[305][25], D[305][25], B[305][25];
int maxElemExcept()
{
	int c = 0;
	for (k = 0; k < M; k++)
		if (k != j)
			c = max(c, D[i][k]);
	return c;
}
int main()
{
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		cin >> x;
		for (j = 1; j <= M; j++)
		{
			cin >> A[x][j];
			if (j == 1)
				D[x][j] = A[x][j]; // ù ��° ȸ�翡'��' �����ϴ� ���, �����ش� �׻� ù ��° ȸ���� �Ͱ� ����
		}
	}

	for (i = 2; i <= M; i++) // �� ��° ȸ����� ����ؼ� �ٿ�������...
	{
		for (j = 1; j <= N; j++)
		{
			for (k = 0, x = 0; k <= j; k++)
			{
				l = A[j - k][i] + D[k][i - 1];
				if (l > x)
				{
					x = l;
					y = j-k;
				}
			}
			D[j][i] = x;
			B[j][i] = y;
		}
	}

	/*for (i = 0; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			cout <<setw(3)<< D[i][j] << '('<<A[i][j]<<')' << ' ';
		}
		cout << '\n';
	}*/

	cout << D[N][M] << '\n';
	
	x = N, y = M, z = N;
	deque<int>v;
	while (y > 1)
	{
		v.push_back(B[x][y]);
		x = z - B[x][y];
		y--;
		z = x;
	}
	v.push_back(z);
	while (!v.empty())
	{
		cout << v.back() << ' ';
		v.pop_back();
	}

	return 0;
}