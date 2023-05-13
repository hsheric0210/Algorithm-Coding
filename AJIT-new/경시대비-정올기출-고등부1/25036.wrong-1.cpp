/*
피하자-정올2022
https://43.200.211.173/contest/17/problem/25036
*/
#include<iostream>
#include<cstring>
using namespace std;
int i, j, k, l, n, p, q;
int arr[1000005];

/*
11
1 2 4 8 3 6 5 7 9 11 13
짝수 -> (1-0) + (2-1) + (3-2) + (5-3)
홀수 -> (0-0) + (4-1) + (5-3)
*/
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];

	j = 0;
	// 짝수 앞에 몰기
	for (i = 0; i < n; i++)
	{
		for (k = i; k < n; k++) // find even number to bring at front
		{
			if (arr[k] % 2 == 0)
			{
				p += k - j;
				cout << "even push " << k << "-" << j << endl;
				j++;
				goto ext1_skip; // break and skip the finish
			}
		}
		goto ext1; // if none of even values avail, this will finish the entire loop
	ext1_skip:
		;
	}
ext1:

	j = 0;
	// 홀수 앞에 몰기
	for (i = 0; i < n; i++)
	{
		for (k = i; k < n; k++) // find odd number to bring at front
		{
			if (arr[k] % 2 != 0)
			{
				q += k - j;
				cout << "odd push " << k << "-" << j << endl;
				j++;
				goto ext2_skip; // break and skip the finish
			}
		}
		goto ext2; // if none of odd values avail, this will finish the entire loop
	ext2_skip:
		;
	}
ext2:

	cout << min(p, q) << endl;
}