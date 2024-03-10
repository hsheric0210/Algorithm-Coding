// ICT-1 : 더하기 사이클
// 그냥 구현.
#include<iostream>
#include<cmath>
using namespace std;
int i, j, k, l, m, n, p, q, r;
int digitOf(int n, int i) { return n / (int)pow(10, i) % 10; }
int main()
{
	cin >> n;
	m = n;
	while (1)
	{
		m = 10 * digitOf(m, 0) + (digitOf(m, 0) + digitOf(m, 1))%10;
		p++;
		if (m == n)
			break;
	}
	cout << p << '\n';
}