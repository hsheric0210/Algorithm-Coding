/*
암호해독
https://43.200.211.173/contest/17/problem/80008
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	char k[30]{ 0 };
	char c[200]{ 0 };
	char p[200]{ 0 };
	cin.getline(k, 30);
	cin.getline(c, 200);
	for (int i = 0; i < 200; i++)
	{
		char d = c[i];
		if (c[i] >= 'a' && c[i] <= 'z')
			d = find(k, k + 30, c[i]) - k + 'a';
		else if (c[i] >= 'A' && c[i] <= 'Z')
			d = find(k, k + 30, c[i] - 'A' + 'a') - k + 'A';
		p[i] = d;
	}
	cout << p << endl;
	return 0;
}