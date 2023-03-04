#include<algorithm>
#include<iostream>

using namespace std;

//제작자: terrasphere (https://www.acmicpc.net/user/terrasphere)

int query(int x, int y)
{
    if (y < 2)
        return y;

    int B = 30;
    while (y < (1 << B) - 1) // SKILL: 2^n = 1<<n, d*(2^n) = d << n, d/(2^n) = d >> n (이진수의 법칙; 2의 곱이나 나눔셈, 거듭제곱 연산을 최적화하는 것에 많이 사용됨)
        B--;

    int bound = (1 << B) - 1;

    if (x >= bound)
        return query(x - bound, y - bound) + B;
    int cans = B;

    for (int i = B - 2; i >= max(0, B - 1 - (bound - x)); i--)
        cans += i;

    return max(query(0, y - bound) + B, cans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << "\n"; // SKILL: endl은 buffer flush를 수행하기에 느리다. 단순히 줄바꿈 위해서라면 '\n'으로 충분하다.
    }

    return 0;
}