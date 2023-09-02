/*
������: ��ȣ
����: ���-1
���̵�: Mid
�˰���: Nested bracket counting
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, i, j, k, l, m, n;
int main()
{
	cin >> T;
	string txt;
	txt.reserve(55);
	for (i = 0; i < T; i++)
	{
		l = 0;
		cin >> txt;
		for (char c : txt)
		{
			if (c == '(')
				l++;
			else if (c == ')')
				l--;
			if (l < 0) break;
		}
		if (l) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}