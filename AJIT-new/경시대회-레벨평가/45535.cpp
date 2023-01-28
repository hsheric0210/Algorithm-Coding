/*
비밀번호-ajit
https://43.200.211.173/contest/19/problem/45535
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int i, j, k, l, m, n, o, p, q, ** arr;
bool pred(int a, int b)
{
	if (min(a, b) == 0)
		return max(a, b) == 8;
	return abs(a - b) == 1 || abs(a - b) == 3;
}
bool chk(int* a, int* b)
{
	bool miss = false;
	for (k = 0; k < 5; k++)
	{
		if (a[k] - b[k] != 0)
		{
			if (!miss && pred(a[k], b[k])) // 구현 실수 I: 만약 두 번호 중 0이 있으면 무조건 0 또는 8이 올 경우만 통과시켜야 하는데, (원래 0 이외의 다른 번호들에게만 적용되는 규칙인) 두 수 사이 차가 1 또는 3일 때도 통과시켜버리도록 코딩하는 바람에, 입력이 '3 00000 00001'이 올 경우, CLOSE가 출력되야 하나, 대신 OPEN이 출력되게 되면서 실패 3패 적립
				miss = true;
			else
				return false;
		}
	}
	return true;
}
int main()
{
	char* line = new char[10]{ 0 };
	cin.getline(line, 10);
	n = atoi(line);
	arr = new int* [n + 1];
	for (i = 0; i <= n; i++)
	{
		arr[i] = new int[5];
		fill(line, line + 10, 0);
		cin.getline(line, 10);
		for (j = 0; j < 5; j++)
		{
			arr[i][j] = line[j] - '0';
		}
		if (i == n)
		{
			bool ok = false;
			for (j = 0; j < n; j++)
			{
				if (chk(arr[j], arr[n]))
				{
					ok = true;
					break;
				}
			}
			if (ok)
				cout << "OPEN" << endl;
			else
				cout << "CLOSE" << endl;
		}
	}
}