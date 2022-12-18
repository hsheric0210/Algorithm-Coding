#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

/*
s  0   10   20   15 25 10 20
dp 0   10  10+20 35 ...
                 ^ (dp[0] + s[2] + s[3])
*/

int main()
{
    // 계단 갯수
    int n = 0;
    cin >> n;

    // 계단 점수
    int* s = new int[max(n + 1, 3)]{ 0, };
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    int* dp = new int[max(n + 1, 3)]();
    dp[0] = 0;
    dp[1] = s[1];
    dp[2] = s[1] + s[2];

    for (int i = 3; i <= n; i++)
    {
        int a = dp[i - 2] + s[i];
        int b = dp[i - 3] + s[i - 1] + s[i];
        dp[i] = max(a, b);
    }

    cout << dp[n] << endl;

    // 메모리 해제
    delete[] dp;
    delete[] s;
}