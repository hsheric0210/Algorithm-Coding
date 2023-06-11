// ICT-2 : 비밀편지
// 구현: Data-decode with Error-tolerance
#include<iostream>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
int i, j, k, l, p, q, r, x, y, z, m, n;
int LOOKUP[8] = {
	0b000000,//A
	0b001111,//B 
	0b010011,//C
	0b011100,//D
	0b100110,//E
	0b101001,//F
	0b110101,//G
	0b111010 //H
};
vector<char>o;
int delta(bitset<6>x, bitset<6>y)
{
	for (p = 0, r = 0; p < 6; p++)
	{
		if (x[p] != y[p])
			r++;
	}
	return r;
}
int main()
{
	cin >> m;
	for (i = 1; i <= m; i++)
	{
		char s[7] = { 0 };
		for (j = 0; j < 6; j++)
			cin >> s[j];
		for (j = 0, y = 1000; j < 8; j++)
		{
			x = delta(bitset<6>(s, 6), bitset<6>(LOOKUP[j]));
			if (x < y)
			{
				y = x;
				z = j;
			}
		}
		if (y <= 1) 
			o.push_back(z + 'A'); // match the smallest delta
		else
		{
			// unrecognized
			cout << i;
			return 0;
		}
	}
	for (char c : o)
		cout << c;
	return 0;
}