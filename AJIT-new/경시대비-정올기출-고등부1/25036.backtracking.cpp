/*
피하자-정올2022
https://43.200.211.173/contest/17/problem/25036
백트래킹을 이용한 풀이 (전체 배열 하나하나 다 밀어보기) -> 성능 대폭 하락 및 시간 초과
*/
#include<iostream>
#include<cstring>
using namespace std;
int i, j, k, l, n, p, q;
int a1[1000000]; // 짝앞 홀뒤
int a2[1000000]; // 홀앞 짝뒤
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> j;
		a1[i] = a2[i] = j;
	}

	while (1)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (a1[i] % 2 == 0)
				continue;
			if (a1[i] % 2 != 0 && a1[i + 1] % 2 != 0) // swapping changes nothing
				continue;
			p++;
			swap(a1[i], a1[i + 1]);
		}
		j = 0, k = 1;
		for (i = 0; i < n - 1; i++)
		{
			if (j && a1[i] % 2 == 0) // if subsequent is not odd -> need more swap
			{
				k = 0;
				break;
			}
			if (a1[i] % 2 != 0)
				j = 1; // now all subsequent nums should be odds
		}
		if (k)
			break;
	}

	while (1)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (a2[i] % 2 != 0)
				continue;
			if (a2[i] % 2 == 0 && a2[i + 1] % 2 == 0) // swapping changes nothing
				continue;
			q++;
			swap(a2[i], a2[i + 1]);
		}
		j = 0, k = 1;
		for (i = 0; i < n - 1; i++)
		{
			if (j && a2[i] % 2 != 0) // if subsequent is not even -> need more swap
			{
				k = 0;
				break;
			}
			if (a2[i] % 2 == 0)
				j = 1; // now all subsequent nums should be evens
		}
		if (k)
			break;
	}

	cout << min(p, q) << endl;
}