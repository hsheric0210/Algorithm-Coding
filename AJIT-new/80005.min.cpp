/*
만날 가능성 체크
https://43.200.211.173/contest/17/problem/80005
C-Minifier-friendly version
*/
#include <iostream>
using namespace std;
typedef struct _r { int n;	int z; } r;
r i(r a, r b)
{
	if (a.n < 0 || a.z < 0 || b.n < 0 || b.z < 0)
		return { -1, -1 };
	if (a.z < b.n || b.z < a.n)
		return { -1, -1 };
	int d = max(a.n, b.n);
	return { d, d + 9 };
}
int d(r r)
{
	if (r.n < 0 || r.z < 0)
		return 0;
	return (r.z - r.n) + 1;
}
int main()
{
	int _a, _b, _c; cin >> _a >> _b >> _c;
	r a = { _a, _a + 9 };
	r b = { _b,_b + 6 };
	r c = { _c,_c + 3 };
	r r1 = i(i(a, b), c);
	r r2 = i(i(b, c), a);
	r r3 = i(i(a, c), b);
	if (d(r1) + d(r2) + d(r3) > 0)
		cout << "meet" << endl;
	else
		cout << "cannot" << endl;
	return 0;
}