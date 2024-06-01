#include<iostream>
#include<algorithm>
using namespace std;
int i, j, k, l, N,prevD,nextD,nextV;
int main()
{
	cin >> N;
	while (N--) {
		cin >> nextD >> nextV;
		k += nextV - prevD;
		l = max(l, k);
		prevD = nextD;
	}
	cout << l;
	return 0;
}
