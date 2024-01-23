// 올림픽
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct T { int a, g, s, b; };
int i, j, k, l, p, q, r, s, N, K;
T A[1005];
int main()
{
	cin >> N >> K;
	for (i = 0; i < N; i++) { cin >> p >> q >> r >> s; A[i] = { p,q,r,s }; }
	sort(A, A + N, [](T a, T b) {return a.g > b.g || (a.g == b.g && a.s > b.s) || (a.g == b.g && a.s == b.s && a.b > b.b); });
	//for (i = 0; i < N; i++)cout << A[i].a << ", " << A[i].g << ", " << A[i].s << ", " << A[i].b << '\n';
	auto t = find_if(A, A + N, [](T a) {return a.a == K; });
	j = find_if(A, A + N, [&t](T a) {return a.g == t->g && a.s == t->s && a.b == t->b; })-A+1; // 맨 위에서부터 해당 국가와 금은동메달 숫자 같은 나라(등수가 같은 나라) 검색 -> find_if가 linear search이기에 가능
	cout << j;
	return 0;
}
