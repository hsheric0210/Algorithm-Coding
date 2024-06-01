#include<iostream>
#include<cmath>
using namespace std;
int N;
int main()
{
	cin >> N;
	cout << (int)(round(N * 0.1) * 10) << '\n' << (int)(round(N * 0.01) * 100) << '\n' << (int)(round(N * 0.001) * 1000);
	return 0;
}
