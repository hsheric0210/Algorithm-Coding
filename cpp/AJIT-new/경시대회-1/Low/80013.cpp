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
int n, sl, i, im = -1, iM = -1, sum = 0;
double m = DBL_MAX, M = 0, avg;
int main()
{
	char* _n = new char[5];
	cin.getline(_n, 5);
	n = atoi(_n);

	char* s = new char[n + 1]{ 0 };
	cin.getline(s, n + 1);
	sl = strlen(s);

	for (i = 0; s[i] != 0; i++)
	{
		sum += s[i] == 'W';
		if (i < 2)
			continue;
		avg = (double)sum / (i + 1);
		if (avg <= m)
		{
			m = avg;
			im = i + 1;
		}
		if (avg >= M)
		{
			M = avg;
			iM = i + 1;
		}
	}
	cout << iM << ' ' << im << endl;
}