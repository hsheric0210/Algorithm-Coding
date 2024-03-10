/*
문제명: 컬러볼
교실: 고급-2
AJIT 정답; 백준 65% 시간초과
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int N, i, j, k, l, m, n, o, p, q, r, C[200005], S[200005], T[200005], TS[200005];
bool PREP[200005];
vector<int>V[200005], VS[200005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (i = 0, j = 0; i < N; i++)
	{
		cin >> C[i] >> S[i];
		T[i] = S[i];
		V[C[i]].push_back(S[i]);
	}
	sort(T, T + N);
	for (i = 0; i < N; i++)
		TS[i] = (i == 0 ? 0 : TS[i-1]) + T[i]; // 전체누적합
	for (i = 0; i < N; i++)
	{
		if (!PREP[C[i]])
		{
			sort(V[C[i]].begin(), V[C[i]].end());
			vector<int>sum;
			for (j = 0, k = V[C[i]].size(); j < k; j++)
				sum.push_back((j == 0 ? 0 : sum.back()) + V[C[i]][j]); // 특정 색 누적합
			VS[C[i]] = sum;
			PREP[C[i]] = 1;
		}

		auto l = V[C[i]];
		int a = lower_bound(T, T + N, S[i]) - T;
		int b = lower_bound(l.begin(), l.end(), S[i]) - l.begin();
		//cout << "a:" << a << " b:" << b << '\n';
		//cout << accumulate(T, T + a, 0) - accumulate(l.begin(), l.begin() + b, 0) << '\n';
		//cout << "av:" << TS[a] << " bv:" << VS[C[i]][b] << '\n';
		cout << TS[a] - VS[C[i]][b] << '\n'; // 전체누적합 - 해당색 누적합
	}

	return 0;
}
