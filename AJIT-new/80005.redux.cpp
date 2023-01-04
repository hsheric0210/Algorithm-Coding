/*
만날 가능성 체크
https://43.200.211.173/contest/17/problem/80005
*/
#include <iostream>
using namespace std;
typedef struct _r
{
	int min; // inclusive
	int max; // inclusive
} r; // 닫힌 구간
r i(r a, r b)
{
	// range check
	if (a.min < 0 || a.max < 0 || b.min < 0 || b.max < 0)
		return { -1, -1 };
	if (a.max < b.min || b.max < a.min) // not intersects
		return { -1, -1 };
	int minInc = max(a.min, b.min);
	return { minInc, minInc + 9 }; // (4)
}
int d(r r)
{
	if (r.min < 0 || r.max < 0)
		return 0;
	return (r.max - r.min) + 1;
}
int main()
{
	int _a, _b, _c; cin >> _a >> _b >> _c;

	r a = { _a, _a + 9 }; // (1)
	r b = { _b,_b + 6 }; // (2)
	r c = { _c,_c + 3 }; // (3)

	r ab = i(a, b);
	r bc = i(b, c);
	r ac = i(a, c);

	r r1 = i(ab, c);
	r r2 = i(bc, a);
	r r3 = i(ac, b);
	if (d(r1) + d(r2) + d(r3) > 0)
		cout << "meet" << endl;
	else
		cout << "cannot" << endl;
	return 0;
}