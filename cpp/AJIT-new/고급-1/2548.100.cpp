/*
문제명: 트리 순회
교실: 고급-1
난이도: Mid
알고리즘: 배열로 표현된 이진 트리, 전위/중위/후위 순회
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

#define C2I(c) (c-'A'+1)
#define I2C(i) ((char)(i+'A'-1))

int N, T[1000], i, j, k, l, m, n, o, p, q, r, s, t;
char X, Y, Z, _TMP;
void a(int node)
{
	if (T[node] <= 0) return;
	cout << I2C(T[node]);
	a(node * 2);
	a(node * 2 + 1);
}
void b(int node)
{
	if (T[node] <= 0) return;
	b(node * 2);
	cout << I2C(T[node]);
	b(node * 2 + 1);
}
void c(int node)
{
	if (T[node] <= 0) return;
	c(node * 2);
	c(node * 2 + 1);
	cout << I2C(T[node]);
}
int main()
{
	cin >> N;
	T[1] = 1; // root node
	for (i = 0; i < N; i++)
	{
		cin >> X >> Y >> Z;
		p = 0;
		for (j = 0, k = C2I(X); j < 1000; j++) // linear-search the position of root node
			if (T[j] == k)
			{
				p = j;
				break;
			}
		if (p) // if root is available
		{
			T[p * 2] = Y == '.' ? 0 : C2I(Y); // left
			T[p * 2 + 1] = Z == '.' ? 0 : C2I(Z); // right
		}
	}
	
	/*for (i = 0; i < 30; i++)
		cout << (char)(T[i]+'A'-1) << ' ';
	cout << '\n';*/

	a(1); cout << '\n';
	b(1); cout << '\n';
	c(1); cout << '\n';
	return 0;
}