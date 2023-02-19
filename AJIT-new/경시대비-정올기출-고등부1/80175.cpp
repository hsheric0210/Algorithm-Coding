/*
비행기 촬영 계획
https://43.200.211.173/contest/17/problem/80175
*/
#include<iostream>
#include<numeric>
#include<queue>
#include<algorithm>
using namespace std;
int i, j, k, l, m, n, o, p, q, r;
int arr[310];
typedef struct _A
{
	int begin, end;
	double avg;
} A;
bool c(A a, A b) {
	return a.avg > b.avg // 평균합 더 큰 것
		|| a.avg == b.avg && (a.end - a.begin) > (b.end - b.begin) // 길이 더 긴 것
		|| a.avg == b.avg && (a.end - a.begin) == (b.end - b.begin) && a.begin < b.begin; // 더 일찍 있는 것
}
vector<A>v;
int main()
{
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	for (i = 1; i < n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (j - i >= k - 1)
			{
				//cout << "push of i=" << i << ", j=" << j << endl;
				v.push_back({ i,j, (double)accumulate(arr + i, arr + j + 1, 0) / (j - i + 1) });
			}
		}
	}
	sort(v.begin(), v.end(), c);
	for (i = 0; i < min(m, (int)v.size()); i++)
	{
		auto tp = v[i];
		cout << tp.begin << ' ' << tp.end << endl;// << " ttl=" << tp.avg << " len=" << (tp.end - tp.begin) << endl;
	}
}