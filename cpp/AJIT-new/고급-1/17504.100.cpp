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
unordered_map<int, int>V;
vector<int>S;
void R(int offset, int prev)
{
	for (int i = offset; i < K; i++)
	{
		int val = prev + G[i];
		V[val] = 1;
		S.push_back(val);
		R(i+1,val);
	}
}
int main()
{
	cin >> K;
	for (i = 0; i < K; i++) { cin >> G[i]; l += G[i]; }
	R(0, 0); // 재귀로 1 채우기

	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end()); // nordered_set에다가 넣고(중복제거), 다시 set으로 옮기고(정렬) 하는 것보다는 그냥 sort 후 unique 하는 것이 훨씬 빠름.

	for (i = 1, j = S.size(); i < j; i++) // 그리디로 2 채우기
	{
		for (k = 0; k < i; k++)
		{
			x = S[i] - S[k];
			if (x > 0 && !V[x])
			{
				V[x] = 2;
				S.push_back(x); // no needs to be checked for duplicates
			}
		}
	}
	cout << l - S.size() << '\n';
	return 0;
}