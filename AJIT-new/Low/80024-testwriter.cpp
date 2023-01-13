/*
SCV 자원채취
https://43.200.211.173/contest/17/problem/80024
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
	char* fn = new char[275]{ 0 };
	cin.getline(fn, 260);
	ofstream out; out.open(fn, ios_base::out);
	int n; cin >> n;
	out << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			out << (rand() % 2 == 0 ? 1 : 0) << ' ';
		}
		out << endl;
	}
	out.close();
}