// ICT-2 : 파도반 수열
// 그냥 규칙 찾고 DP돌리면 됨. 피보나치처럼.
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i, j, k, l, p, q, r, x, y, z, N,T;
unsigned long long P[105];
int main()
{
	P[1] = P[2] = P[3] = 1;
	P[4] = P[5] = 2;
	P[6] = 3;
	P[7] = 4;
	P[8] = 5;
	for (i = 8; i < 100; i++)
		P[i + 1] = P[i] + P[i - 4];
	
	//#define DUMP
#ifdef DUMP
	for (i = 1; i < 100; i++)
		cout << P[i] << ' ';
	cout << '\n';
#endif

	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> N;
		cout << P[N] << '\n';
	}
}