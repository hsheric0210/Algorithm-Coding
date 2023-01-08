/*
°³¹Ì
https://43.200.211.173/contest/17/problem/80011
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _ant
{
	int pos; char dir;
} ant;
int main()
{
	int l, t, n; cin >> l >> t >> n;
	ant* arr = new ant[n]{ 0 };
	for (int i = 0; i < n; i++)
	{

		int p; char d; cin >> p >> d;
		arr[i] = { p,d };
	}

	// simulation
	for (int i = 0; i < t; i++)
	{
		// move
		for (int j = 0; j < n; j++)
		{
			ant* a = arr + j;
			a->pos += a->dir == 'D' ? 1 : -1;
		}
		// collision check
		ant** positions = new ant * [l + 1]{ 0 };
		for (int j = 0; j < n; j++)
		{
			ant* a = arr + j;
			ant* prev = positions[a->pos];
			if (prev == 0) // empty
				positions[a->pos] = a;
			else
			{
				// collision

				// change dir
				prev->dir = prev->dir == 'L' ? 'D' : 'L';
				a->dir = a->dir == 'L' ? 'D' : 'L';

				// move one block
				prev->pos += prev->dir == 'D' ? 1 : -1;
				a->pos += a->dir == 'D' ? 1 : -1;
			}
		}
		delete[] positions;
	}

	for (auto i = 0; i < n; i++)
		cout << arr[i].pos << ' ';
	cout << endl;
}