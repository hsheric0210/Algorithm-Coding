/*
문제명: 양팔저울
교실: 고급-1
난이도: Mid
알고리즘: Top-down DP + 그리디
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;

int K, i, j, k, l, m, n, o, p, q, r, s, t, x, y, z;
int G[15];
vector<int>S;
void R(int offset, int prev)
{
	for (int i = offset; i < K; i++)
	{
		int val = prev + G[i];
		S.push_back(val);
		R(i + 1, val);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> K;
	for (i = 0; i < K; i++) { cin >> G[i]; l += G[i]; }
	R(0, 0); // 재귀로 1 채울 위치 목록 

	vector<int>V(l + 1);

	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end()); // python처럼 vector->unordered_set->vector 변환하는 것 보다는 이 방법이 훨씬 더 빠름

	// 1 채우고 칸 개수 세기
	for (i = 0; i < S.size(); i++)
	{
		V[S[i]] = 1;
		z++;
	}

	// 그리디로 2 채우고 칸 개수 세기
	for (i = 1, j = S.size(); i < j; i++)
	{
		//for (k = 0; k < i; k++)
		for (k = i - 1; k >= 0; k--)
		{
			x = S[i] - S[k];
			if (!V[x])
			{
				V[x] = 2;
				z++;
			}
		}
	}
	cout << l - z << '\n';
	return 0;
}