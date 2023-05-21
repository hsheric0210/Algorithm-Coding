// ICT-1 : 한수
#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
int i, j, k, l, m, n, p, q, r;
ll x, y, z;
#define IMAX 0x7FFFFFFF
bool chk(int n)
{
	if (n <= 99) // 두 자리 이하 숫자는 항상 등차수열을 이룰 수 밖에 없다(수열에 원소가 2개 이하이면 두 수 사이의 비가 곧 항상 공비가 되기 때문)
		return true;
	q = -1; // previous digit
	r = IMAX; // previous delta
	for (j = 0, l = log10(n); j <= l; j++)
	{
		p = n / (int)pow(10, j) % 10;
		if (q >= 0) // previous digit avail.
		{
			if (r != IMAX && r != p - q) // delta avail. & changed -> not an arithmetic progression
				return false;
			r = p - q;
		}
		q = p;
	}
	return true;
}
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)if (chk(i))m++;
	cout << m << '\n';
	return 0;
}