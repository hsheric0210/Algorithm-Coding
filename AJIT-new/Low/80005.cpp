/*
만날 가능성 체크
https://43.200.211.173/contest/17/problem/80005
*/
#include <iostream>
#include <algorithm>
#undef DBG
using namespace std;
typedef struct _closedRange
{
	int min; // inclusive
	int max; // inclusive
} closedRange; // 닫힌 구간
closedRange intersect(closedRange a, closedRange b)
{
	// range check
	if (a.min < 0 || a.max < 0 || b.min < 0 || b.max < 0)
		return { -1, -1 };
	if (a.max < b.min || b.max < a.min) // not intersects
		return { -1, -1 };
	int minInc = max(a.min, b.min);
	// int maxInc = min(a.max, b.max);
	return { minInc, minInc + 9 }; // (4)
}
int distance(closedRange r)
{
	if (r.min < 0 || r.max < 0)
		return 0;
	return (r.max - r.min) + 1;
}
void printRange(closedRange range)
{
	cout << range.min << ".." << range.max << endl;
}
int main()
{
	int _a, _b, _c; cin >> _a >> _b >> _c;
	closedRange a = { _a, _a + 9 }; // (1)
	closedRange b = { _b,_b + 6 }; // (2)
	closedRange c = { _c,_c + 3 }; // (3)
#ifdef DBG
	cout << "a: "; printRange(a);
	cout << "b: "; printRange(b);
	cout << "c: "; printRange(c);
#endif

	closedRange ab = intersect(a, b);
	closedRange bc = intersect(b, c);
	closedRange ac = intersect(a, c);
#ifdef DBG
	cout << "ab: "; printRange(ab);
	cout << "bc: "; printRange(bc);
	cout << "ac: "; printRange(ac);
#endif

	closedRange r1 = intersect(ab, c);
	closedRange r2 = intersect(bc, a);
	closedRange r3 = intersect(ac, b);

#ifdef DBG
	cout << "ab+c: "; printRange(r1);
	cout << "bc+a: "; printRange(r2);
	cout << "ac+b: "; printRange(r3);
#endif

	if (distance(r1) + distance(r2) + distance(r3) > 0)
		cout << "meet" << endl;
	else
		cout << "cannot" << endl;
	return 0;
}