#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int A[100], B[100], nTestCases, Max = 0;
void recursive_search(int accumulated_i, int previous_green_r, int x, int y, int depthLimit /*i 깊이 제한: 만약 이전에 A[i]에서 결과를 찾았다면, 그 다음 재귀에서는 적어도 A[i] 이하의 값을 더해서 수를 찾을 수 있을 것이다.*/)
{
	if (previous_green_r >= x && previous_green_r <= y) // 이전 초록 칸의 결과가 x..y 범위 안에 들어있다면
	{
		if (Max < accumulated_i)
			Max = accumulated_i; // 최댓값은 적어도 누적된 i보다는 클 것이다
	}

	if (previous_green_r >= y) // 만약 이전 성공 결과가 범위와 *같거나* 초과했다면 STOP
		return;

	for (int i = 1; i <= depthLimit; i++) // TODO: lower_bound를 이용한 최적화
	{
		if (i == depthLimit /*깊이제한에 걸렸거나*/ || previous_green_r + A[i] > y /*이전 결과에다 더 추가하면 범위 초과하는 경우*/)
		{
			if (previous_green_r + A[i] >= x && previous_green_r + A[i] <= y && Max < accumulated_i + B[i]) // `m+A[i]`이 x..y의 범위 내에 있는 경우: i는 초록색 칸이 될 수 있는가? 만약 가능하다면, 누적 i는 적어도 이보다는 클 것이다.
				Max = accumulated_i + B[i];

			if (previous_green_r + A[i - 1] >= x && previous_green_r + A[i - 1] <= y && Max < accumulated_i + B[i - 1]) // `m+A[i-1]`이 x..y의 범위 내에 있는 경우: i-1는 초록색 칸이 될 수 있는가? 만약 가능하다면, 누적 i는 적어도 이보다는 클 것이다.
				Max = accumulated_i + B[i - 1];

			if (i == depthLimit)
				recursive_search(accumulated_i + (i - 1), previous_green_r + A[i - 1], x, y, i - 1); // i 깊이 제한에 걸렸다면, 깊이제한 1 감소시키고 다음 재귀
			else
				recursive_search(accumulated_i + (i - 1), previous_green_r + A[i - 1], x, y, i); // 다음 재귀

			break;
		}
	}
}
int t, i, c, d, e, x, y;
int main()
{
	// Desync iostreams to speed up i/o
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> nTestCases;

	// Initialize lookup arrays
	B[1] = 1;
	for (i = 0; i <= 30; i++)
	{
		A[i] = /*pow(2, i)*/ (1 << i) - 1; // SKILL: 2^n은 1<<n으로 최적화될 수 있다 (2진법의 특징)
		if (i > 1)
			B[i] = (i - 1) + B[i - 1];
	}

	for (t = 0; t < nTestCases; t++)
	{
		cin >> x >> y;
		Max = 0;
		for (i = 0; i <= 30; i++) // TODO: lower_bound를 이용한 최적화
		{
			if (A[i] > y)
				break;

			if (x <= A[i] && A[i + 1] - 1 <= y) // 만약 x..y 사이에 a[i]..(a[i+1]-1)이 끼어 있다면 (B[i+1]이 해당 범위 안의 최댓값을 의미한다고 판단할 수 있는 경우)
			{
				if (Max < B[i + 1])
					Max = B[i + 1]; // B[i+1]에는 i=A[i]..(A[i+1]-1) 사이 범위의 최댓값이 담겨 있으므로, 못해도 이보다는 커야 할 것이다
			}
			else if (A[i + 1] >= x) // '튀어나온 부분' 발견!
				recursive_search(i, A[i], x, y, i);
		}
		cout << Max << endl;
	}
}