/*
야구경기
https://43.200.211.173/contest/17/problem/80013
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cfloat>
using namespace std;
int main()
{
	char* _n = new char[5];
	cin.getline(_n, 5);
	int n = atoi(_n);
	char* s = new char[n + 1]{ 0 };
	cin.getline(s, n + 1);
	int sl = strlen(s);

	double amin = DBL_MAX, amax = 0;
	int iamin = -1, iamax = -1, sum = 0;
	for (int pos = 0; s[pos] != 0; pos++)
	{
		sum += s[pos] == 'W';
		if (pos < 2)
			continue;
		double avg = (double)sum / (pos + 1);
		if (avg <= amin)
		{
			amin = avg;
			iamin = pos + 1;
		}
		if (avg >= amax)
		{
			amax = avg;
			iamax = pos + 1;
		}
	}
	cout << iamax << ' ' << iamin << endl;
}