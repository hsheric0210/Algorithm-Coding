#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int i, j, k, l, m;
char s1[1005], s2[1005];
typedef struct _a
{
	int x1, y1, x2, y2;
} a;
int levenshtein[1005][1005];
int main()
{
	cin.getline(s1, 1005);
	cin.getline(s2, 1005);
	k = strlen(s1), l = strlen(s2);

	for (i = 0; i < k; i++) levenshtein[i][0] = i;
	for (i = 0; i < l; i++) levenshtein[0][i] = i;

	// dp - levenshtein distance
	a* as = new a[3];
	for (i = 0; i < k; i++)
		for (j = 0; j < l; j++)
		{
			levenshtein[i + 1][j + 1] = min({ levenshtein[i][j + 1], levenshtein[i + 1][j], levenshtein[i][j] + (s1[i] != s2[j]) });
		}

	cout << levenshtein[i][j] << '\n';

	// dump dp table
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < l; j++)
		{
			cout << levenshtein[i][j] << ' ';
		}
		cout << '\n';
	}

	//backtrack
	deque<pair<int, int>>q;
	deque<string>ed; // Edit Distance
	ed.push_front(s2);
	q.push_back({ i - 1,j - 1 });
	while (!q.empty())
	{
		auto bk = q.back();
		q.pop_back();
		i = bk.first, j = bk.second;
		if (i == 0 && j == 0) // ���� �Ǽ� III: '&&'�� ��� �� ���� '||'�� ���� �ٶ��� ��� ���̶� zero�� �Ǿ� ������ ���� loop�� ����Ǿ� ���̰� �ٸ� �� ���ڿ��� ���� Edit Distance Backtracking�� ����� �̷������ �ʾҴ�.
			break;
		if (i - 1 >= 0 && j - 1 >= 0 && s1[i - 1] == s2[j - 1])
		{
			q.push_back({ i - 1, j - 1 });
			continue;
		}
		tuple<int, int, int, int> m2[3] = {
			{ i - 1 < 0 ? 999 : dp[i - 1][j], i - 1, j, 0 }, // insert
			{ j - 1 < 0 ? 999 : dp[i][j - 1], i, j - 1, 1 }, // delete
			{ (i - 1 < 0 || j - 1 < 0) ? 999 : dp[i - 1][j - 1], i - 1, j - 1, 2 } // replace
		};
		auto m = *min_element(m2, m2 + 3, [](auto a, auto b) {return get<0>(a) < get<0>(b); });
		q.push_back({ get<1>(m), get<2>(m) });

		// simulate
		string prv = ed.front();
		switch (get<3>(m))
		{
		case 0: // insert
			prv.insert(prv.begin() + j, a[i - 1]);
			break;
		case 1: // remove
			prv.erase(prv.begin() + j - 1, prv.begin() + j);
			break;
		case 2: // replace
			prv[j - 1] = s1[i - 1];
			break;
		}
		ed.push_front(prv);
	}
	while (!ed.empty())
	{
		cout << ed.front() << endl;
		ed.pop_front();
	}

	delete[] as;
}