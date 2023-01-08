/*
°³¹Ì
https://43.200.211.173/contest/17/problem/80011
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
	ofstream out; out.open("INPUT.80013.TXT");
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		out << i << ' ' << (rand() % 2 == 0 ? 'L' : 'D') << endl;
	out.close();
}