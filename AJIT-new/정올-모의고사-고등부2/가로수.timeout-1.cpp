#include <bits/stdc++.h>
using namespace std;
int i,j,k,l,n, p, q;
int a[100000];
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
	
	for (i = 0; i < n-2; i++)
	{
		int g = gcd(a[i+1] - a[i], a[i+2] - a[i+1]);
		l = min(l, g);
		if (l <= 1)
			break;
	}
	
	for (i = a[0]; i <= a[n-1]; i+=l)
	{
		if (*lower_bound(a, a+n, i) != i) // binary search -> time out
			p++;
	}
	cout << p << '\n';
}