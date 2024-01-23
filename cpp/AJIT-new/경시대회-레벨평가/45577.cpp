/*
주사위쌓기-ajit
https://43.200.211.173/contest/19/problem/45577
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int i, j, k, l, m, n, o, p, q, * arr, * prevDownward, * prv, ** upward, * maxs;
int opposite(int side)
{
	switch (side)
	{
	case 0:
		return 5;
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 1;
	case 4:
		return 2;
	case 5:
		return 0;
	}
}
int main()
{
	cin >> n;
	arr = new int[6];
	upward = new int* [6];
	prv = new int[6]{ 0 };
	maxs = new int[6]{ 0 };
	for (i = 0; i < 6; i++)
		upward[i] = new int[n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 6; j++)
		{
			cin >> arr[j];
			if (i == 0)
			{
				upward[j][0] = arr[j]; // 1번 주사위를 어떻게 놓느냐에 따라 총 6가지 경우로 분기된다
			}
		}
		if (i == 0)
		{
			for (j = 0; j < 6; j++)
			{
				int mx = 0;
				for (p = 0; p < 6; p++)
				{
					if (p == j || p == opposite(j)) // 윗면 또는 아랫면은 회전시킬 수 없으므로, 두 면을 제외한 나머지 4개 면들의 숫자들 중 최댓값
						continue;
					if (arr[p] > mx)
						mx = arr[p];
				}
				maxs[j] += mx;
			}
		}
		else
		{
			for (j = 0; j < 6; j++) // 각 1번 주사위의 가능한 배치 6가지에 대하여
			{
				k = upward[j][i - 1]; // 이전 단계에서의 주사위 윗면의 숫자 = 이번 단계에서의 주사위 아랫면의 숫자
				o = find(arr, arr + 6, k) - arr; // 이번 단계에서의 주사위 아랫면 숫자 index
				m = opposite(o); // 이번 단계에서의 주사위 윗면 숫자 index
				upward[j][i] = arr[m];

				int mx = 0;
				for (p = 0; p < 6; p++)
				{
					if (p == o || p == m) // 윗면 또는 아랫면은 회전시킬 수 없으므로, 두 면을 제외한 나머지 4개 면들의 숫자들 중 최댓값
						continue;
					if (arr[p] > mx)
						mx = arr[p];
				}
				maxs[j] += mx;
			}
		}
		memcpy(prv, arr, sizeof(int) * 6);
	}
	cout << *max_element(maxs, maxs + 6) << endl;
}