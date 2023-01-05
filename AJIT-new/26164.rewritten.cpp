/*
���� ������
https://43.200.211.173/contest/17/problem/26164

Ʋ�� ����: �������� �˰��� ���� ��ü�� �߸� �����Ͽ� �߸� ������
	-> DBG Ȱ��ȭ�ϰ� ���� �ҽ��� rewritten �ҽ��� ����� ��¸� ���� �� �� ����
*/
#include <iostream>
#include <algorithm>
using namespace std;
//#define DBG
int main()
{
	int e, f, n; cin >> e >> f >> n; f -= e; // f: �� ���� ����
	int dpsz = max(2, f + 1);
	int* dp = new int[dpsz];
	fill(dp, dp + dpsz, 0);
	for (int i = 0; i < n; i++)
	{
		int p, w;
		cin >> p >> w;
#ifdef DBG
		cout << "= Phase #" << (i + 1) << " price=" << p << ", weight=" << w << endl;
#endif
		if (dp[w] == 0 || dp[w] > p)
			dp[w] = p;
		for (int j = w; j <= f; j++)
		{
			if (dp[j - w] == 0) continue;
			int calc = dp[j - w] + p;
			bool overwrite = dp[j] == 0 || dp[j] > calc;
			dp[j] = overwrite ? calc : dp[j];
#ifdef DBG
			cout << "dp[" << j << "] " << (overwrite ? "->" : "==") << ' ' << dp[j] << " (calc=dp[j-w]+p=dp[" << j-w << "]+" << p <<"]=" << dp[j - w] << '+' << p << ')' << endl;
#endif
		}
	}

#ifdef DBG
	for (int i = 0; i <= f; i++)
		cout << "dp[" << i << "] " << (i == f ? "->" : "-=") << ' ' << dp[i] << endl;
#endif

	int l = dp[max(f, 0)];
	cout << (l == 0 ? -1 : l) << endl;
	return 0;
}