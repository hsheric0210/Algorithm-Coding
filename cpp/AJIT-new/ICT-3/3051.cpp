// 예산
// 이진 탐색, 그러나 STL lower_bound를 사용할 수 없는
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int i, j, k, l, p, q, r, N, M, A[10005], B[10005], t, v;
int accum_with_limit(int limit)
{
	for (l = 0, v = 0; l < N; l++)
		v += min(A[l], limit);
	return v;
}
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)cin >> A[i];
	cin >> M;

	j = accumulate(A, A + N, 0);
	k = *max_element(A, A + N);
	if (j <= M) // no need to calc :)
	{
		cout << k;
		return 0;
	}

	// custom impl of lower_bound. original source avail @ https://en.cppreference.com/w/cpp/algorithm/lower_bound
	p = k; // count
	q = 0; // step
	r = 1; // first (ptr)
	t = 0; // it
	while (p > 0)
	{
		t = r;
		q = p / 2;
		t += q;
		j = accum_with_limit(t);
		//cout << "Trying t=" << t << ". sum is " << j << ", the cap is " << M << '\n';
		if (j < M) // too small -> select right part
		{
			r = ++t;
			p -= q + 1;
		}
		else if (j > M)  // still too large -> seleft left part
		{
			p = q;
		}
	}
	cout << r-1 << '\n';
	return 0;
}