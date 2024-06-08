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
list<int>A, B;
int main() // car racing
{
	cin >> N; k = 1;
	while (N--) { cin >> j; A.push_back(j); }
	while (!A.empty() || !B.empty())
	{
		if (!A.empty() && A.front() == k) { A.pop_front(); k++; }
		else if (!B.empty() && B.front() == k) { B.pop_front(); k++; }
		else if (!A.empty()) { B.push_back(A.front()); A.pop_front(); }
		else { cout << "NO"; return 0; }
	}
	cout << "YES";
	return 0;
}
// 2Ка 43УЪ 80
