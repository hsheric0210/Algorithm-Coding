/*
문제명: 제로
교실: 고급-1
난이도: Mid
알고리즘: 구현
*/
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int K, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
vector<int>V;
int main()
{
	cin >> K;
	for (i = 0, p=0; i < K; i++)
	{
		cin >> j;
		if (j)
			V.push_back(j);
		else
			V.pop_back();
	}
	cout << accumulate(V.begin(), V.end(),0);
	return 0;
}