/*
십자카드 문제
https://43.200.211.173/contest/19/problem/9821
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int i, j, k, l, m, n, o, p, q, r, * arr, * dp;
int composeNum(int* ar)
{
	int v = 0, n = 1;
	for (m = 0; m < 4; m++)
	{
		v += ar[3 - m] * n;
		n *= 10;
	}
	return v;
}
int* decomposeNum(int num)
{
	int* ar = new int[4], n = 1;
	for (m = 0; m < 4; m++)
	{
		ar[3-m] = num / n % 10;
		n *= 10;
	}
	return ar;
}
int clockNumOf(int* ar)
{
	int cnum = 9999;
	for (k = 0; k < 4; k++)
	{
		int* cpy = new int[4];
		for (l = 0; l < 4; l++)
			cpy[(k + l) % 4] = ar[l];
		int cpynum = composeNum(cpy);
		if (cnum > cpynum)
			cnum = cpynum;
		delete[]cpy;
	}
	return cnum;
}
int main()
{
	arr = new int[4];
	for (i = 0; i < 4; i++)
		cin >> arr[i];
	int cnum = clockNumOf(arr);
	set<int> dupchk;
	int comparand = 1111;
	for (i = 1;; i++)
	{
		//cout << "check for " << comparand << endl;
		if (cnum == comparand)
		{
			cout << i << endl;
			return 0;
		}
		dupchk.insert(clockNumOf(decomposeNum(comparand)));
		comparand++;
		while (true) // 끝자리가 0인경우
		{
			int* dec = decomposeNum(comparand);
			bool rs1 = find(dec, dec + 4, 0) != dec + 4; // 0 포함
			bool rs2 = find(dupchk.begin(), dupchk.end(), clockNumOf(dec)) != dupchk.end(); // 이미 검사한 시계수 목록에 포함
			if (!rs1 && !rs2)
				break;
			comparand++;
		}
	}
}