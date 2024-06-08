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
char A, B;
list<char>L;
int main() // 문자 Shift
{
	cin >> A >> B >> N;
	for (i = A; i <= B; i++)
		L.push_back((char)i);
	for (i = 0; i < N - 1; i++)
	{
		L.push_back(L.front());
		L.pop_front();
	}
	for (char ch : L)
		cout << ch;
	return 0;
}
// 1분 57초 50
