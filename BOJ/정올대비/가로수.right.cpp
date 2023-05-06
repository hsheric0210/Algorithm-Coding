#include <bits/stdc++.h>
// 드디어! 내 힘으로 풀었어!
using namespace std;
int i,j,k,l,n, p, q;
int a[100000];
int d[100000];
int gcd(int a, int b)
{
	int alpha, beta = a, gamma = b;
	while(1)
	{
		alpha = beta % gamma;
		if (alpha == 0)
			return gamma;
		beta = gamma;
		gamma = alpha;
	}
	return 1;
}
int main()
{
	cin >> n;
	l = 0x7FFFFFFF; // int_max
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	// beware off-by-one problem
	for (i = 0; i < n-1; i++)
	{
		d[i] = a[i+1] - a[i];
	}
	
	for (i = 0; i < n-2; i++)
	{
		int g = gcd(d[i], d[i+1]);
		l = min(l, g);
		if (l <= 1)
			break;
	}
	
	// todo: optimize
	//for (i = a[0]; i <= a[n-1]; i+=l)
	//{
	//	if (*lower_bound(a, a+n, i) != i) // binary search
	//		p++;
	//}
	
	for (i = 0; i < n-1; i++)
	{
		p += d[i] / l - 1;
	}
	
	cout << p << '\n';
}