#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
list<int>L;
char Begin, End; int N;
int i, j, k, l;
int main()
{
	cin >> Begin >> End >> N;
	for (char ch = Begin; ch <= End; ch++)
		L.push_back(ch);
	N--;
	while (N--)
	{
		L.push_back(L.front());
		L.pop_front();
	}
	for (char ch : L)
		cout << ch;
	return 0;
}
