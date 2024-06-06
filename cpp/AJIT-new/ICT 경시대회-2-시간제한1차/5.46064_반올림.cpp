#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
int main()
{
	cin >> N;
	cout << (int)(round(N / 10.0) * 10) << '\n';
	cout << (int)(round(N / 100.0) * 100) << '\n';
	cout << (int)(round(N / 1000.0) * 1000) << '\n';
	return 0;
}
