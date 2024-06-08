#include<iostream>
#include<iomanip>
#include<algorithm>
#include<utility>
#include<numeric>
#include<memory>
#include<vector>
#include<list>
#include<deque>
#include<bitset>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
int i, j, k, l, N;
int main() // 반올림
{
	cin >> N;
	cout << (int)(round(N / 10.0) * 10) << '\n';
	cout << (int)(round(N / 100.0) * 100) << '\n';
	cout << (int)(round(N / 1000.0) * 1000) << '\n';
	return 0;
}
// 1분 03초 69
