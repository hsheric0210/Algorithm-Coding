/*
������: �������� �Ͼ��� ����
�˰���: ���, DP
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
using namespace std;
typedef unsigned char uc;
int N, L, P, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
uc DP[105][105];
string S;
void recurse(int begin, int end)
{
	for (int i = begin + 1; i < end; i += 2)
	{
		if (S[begin] == S[i]) continue;
		recurse(begin + 1, i - 1); // (begin+1)..(i-1) - ���� ����
		recurse(i + 1, end); // (i+1)..L - ���� �ٱ��� ������
		DP[begin][end] = min(DP[begin][end], (uc)(DP[begin + 1][i - 1] + DP[i + 1][end]));
	}
}
int main()
{
	memset(DP, 0xFFFF, sizeof(char) * 105 * 105); // fill dp table
	cin >> N >> S;
	L = S.length();
	recurse(0, L);
	cout << DP[0][L];
	return 0;
}