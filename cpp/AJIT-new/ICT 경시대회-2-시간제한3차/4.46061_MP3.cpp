#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<list>
#include<numeric>
#include<deque>
#include<iomanip>
#include<cmath>
using namespace std;
int i, j, k, l, N, p;
int main()
{
	cin >> N;
	while (N--) { cin >> i >> j; l += j - k; p = max(p, l);  k = i; }
	cout << p;
	return 0;
}
// 8Ка 03УЪ
