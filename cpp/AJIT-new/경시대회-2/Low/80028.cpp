/*
돌다리 건너기(ROCK)
https://43.200.211.173/contest/18/problem/80028
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int n, m, i, j;
int* arr;
int dpmin(int* arr, int off)
{
	int min = 999999;
	for (int i = 0; i < 3; i++) if (arr[i] < min && arr[i] >= 0) min = arr[i];
	return min == 999999 ? -1 : (min + off);
}
int main()
{
	cin >> n >> m;
	int** dp = new int* [n + 2]{ 0 };
	arr = new int[n+1] {0}; // dp[n+1]칸에 총 결과가 저장되는데, 이때 arr[n]에 엑세스하게 되면서 오류가 나는 것을 방지하기 위해 arr를 n+1의 크기로 초기화
	for (i = 0; i <= n + 1; i++) dp[i] = new int[3]{ 0 };
	for (i = 0; i < n; i++) cin >> arr[i];
	for (i = 1; i <= n+1; i++)
	{
		if (arr[i - 1] < 0) // 현재 칸에 돌다리 없음
			fill(dp[i], dp[i] + 3, -1);
		else
		{
			dp[i][0] = dpmin(dp[i - 1], arr[i - 1]); // 한 칸 점프
			dp[i][1] = i - 2 >= 0 ? dpmin(dp[i - 2], arr[i - 1]) : dp[i][0]; // 두 칸 점프
			dp[i][2] = i - 3 >= 0 ? dpmin(dp[i - 3], arr[i - 1]) : dp[i][1]; // 세 칸 점프
		}
	}

	int md = dpmin(dp[n+1], 0);

	//constexpr int pad = 3;
	//cout << "arr=      ";
	//for (i = 0; i < n; i++)
	//	cout << setw(pad) << arr[i] << ' ';
	//cout << endl;
	//
	//for (j = 0; j < 3; j++)
	//{
	//	cout << "dp[" << j << "]=";
	//	for (i = 0; i <= n+1; i++)
	//		cout << setw(pad) << dp[i][j] << ' ';
	//	cout << endl;
	//}
	//cout << "min_dmg=" << md << endl;

	if (m - md >= 0)
		cout << md << endl;
	else
		cout << -1 << endl;
}