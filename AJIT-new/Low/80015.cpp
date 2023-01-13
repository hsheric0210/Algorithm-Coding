/*
유전자 배열
https://43.200.211.173/contest/17/problem/80015
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
int l, al, bl, i, msz, any = 0;
void chk(char* _a, char* _b, int off, int len)
{
	msz = sizeof(char) * len;
	char* a = new char[len + 1]{ 0 };
	strncpy(a, _a + off, len);
	char* ar = new char[len + 1]{ 0 };
	memcpy(ar, a, msz);
	reverse(ar, ar + len); // strrev

	char* b = new char[len + 1]{ 0 };
	strncpy(b, _b + off, len);
	char* br = new char[len + 1]{ 0 };
	memcpy(br, b, msz);
	reverse(br, br + len); // strrev

	if (!memcmp(a, ar, msz) && !memcmp(b, br, msz))
	{
		cout << (off + 1) << ' ' << a << ' ' << b << endl;
		any = 1;
	}

	delete[] a, ar, b, br;
}
int main()
{
	char a[101], b[101], _l[10];
	cin.getline(a, 101); cin.getline(b, 101); cin.getline(_l, 10);
	l = atoi(_l);
	al = strlen(a);
	bl = strlen(b);
	for (i = 0; i < min(al, bl) - l + 1; i++) chk(a, b, i, l);
	if (!any) cout << -1 << endl;
}