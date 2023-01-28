/*
기차 교차로
https://43.200.211.173/contest/19/problem/3805
*/
#include<iostream>
#include<deque>
using namespace std;
int n, i, j, * arr, c = 1;
deque<int> departure, buffer;
deque<char> op;
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> j;
		departure.push_back(j);
	}

	while (true)
	{
		bool update = false;
		if (!buffer.empty())
		{
			// 버퍼(교차로)가 비어 있지 않고, 그 버퍼의 top에서 열차를 꺼내 바로 도착지로 보낼 수 있다면 (top의 열차의 번호가 c라면)
			int b_fr = buffer.front();
			if (b_fr == c)
			{
				// 도착지로 열차를 보낸다 (c 증가)
				buffer.pop_front();
				op.push_back('X');
				c++;
				update = true;
			}
		}

		if (!update && !departure.empty())
		{
			// 버퍼에서 열차를 꺼낼 수 없고 (업데이트가 이루어지지 않았고), 출발지에 열차가 남아 있다면
			int t1_fr = departure.front();
			departure.pop_front();
			buffer.push_front(t1_fr); // 버퍼에 열차 집어넣기
			op.push_back('S');
			update = true;
		}

		if (update && c == n + 1) // 만약 이번의 업데이트로 모든 열차가 성공적으로 도착했다면 (출발열차갯수 == 도착열차갯수)
		{
			// 지금까지의 op들 출력
			for (auto a = op.begin(); a != op.end(); a++)
				cout << *a;
			cout << endl;
			break;
		}
		else if (!update) // 만약 이번 틱에 업데이트가 이루어지지 않았다면 (무한루프 방지)
		{
			cout << "IMPOSSIBLE" << endl; // 실★패
			return 0;
		}
	}
}