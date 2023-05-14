/*
박 터뜨리기_고등-정올2020
https://43.200.211.173/contest/17/problem/19734
소요시간: 2시간40분 남짓
*/
#include<iostream>
using namespace std;
int i, j, k, l, n, m, r;
int main()
{
	cin >> n >> k;
	do
	{
		m = 0;
		for (i = 1; i < k+(r>0); i++) // 만약 r>0이라면 수열 {1,2,...,k-1}에서 원소 r이 제거되었으므로 이를 보상하기 위해 맨 마지막에 k를 붙인다 (ex: r=2일 때 {1,3,4,5,...,k-1,k})
		{
			if (i == r)
				continue;
			m += i;
			//cout << "+" << i;
		}
		//cout << "=" << m << "(excluded " << r << ")" << endl;
		j = (n + m) / k;
		if (j < k)
		{
			cout << -1 << endl;
			return 0;
		}
		l = r;
	} while ((r = (n + m) % k) != 0);
	//cout << "n=" << j << endl;
	//cout << "r=" << l << endl;
	if (j - k + 1 < 1) // 공의 갯수가 최소인 바구니의 공 갯수가 1개 이상이어야만 한다
		cout << -1 << endl;
	else if (l != 0)
		cout << k << endl; // 예외: 무언가 수열에서 제외한 경우
	else
		cout << k - 1 << endl; // 공식에 따라서
}