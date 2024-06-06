#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int i, j, k, l, F, V, I[105][105], D[105][105];
list<int>H;
int main()
{
	cin >> F >> V;
	for (i = 1; i <= F; i++) for (j = 1; j <= V; j++) { cin >> I[i][j]; }
	for (i = 1; i <= F; i++) for (j = 1; j <= V; j++) if (i <= j) D[i][j] = max(D[i - 1][j - 1] + I[i][j], D[i][j - 1] );
	cout << D[F][V] << '\n';
	for (i = F, k = V; i > 0; i--) for (j = k; j > 0; j--) if (D[i][j - 1] < D[i][j])
	{
		H.push_front(j);
		k = j - 1;
		break;
	}
	for (int h : H)
		cout << h << "  ";
	return 0;
}
