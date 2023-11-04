/*
BYTE-range (8-bit) POPCNT lookup table builder.
Copy-paste STDOUT to your code.
*/
#include <iostream>
using namespace std;
int i, j, k, l;
// simple but very slow impl. of POPCNT
int popcnt_slow(unsigned char a)
{
	int c = 0;
	for (; a != 0; a >>= 1)
		if (a & 1)
			c++;
	return c;
}
int main()
{
	cout << "unsigned char lookup[256]= {";
	for (i = 0; i < 256; i++)
		cout << popcnt_slow(i) << ',';
	cout << "};";
	return 0;
}