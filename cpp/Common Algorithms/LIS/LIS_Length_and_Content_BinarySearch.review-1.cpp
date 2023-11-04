/*
LIS 길이 구하기 - O(nLog(n)) 알고리즘 - Lower bound 이진 탐색 사용
https://www.acmicpc.net/problem/9252
입력: 수열 길이 N, 수열 S
출력: LIS의 길이와 LIS 문자열
*/
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int i, j, k;
int main()
{
	cin >> k;
	vector<pair<int, int>>arr(k, { -1,-1 }); // 중요! : 반드시 second 원소는 -1과 같은 음수로 초기화해야 한다. 그래야만 백트래킹 끝단 원소에 도달하였을 때 Line 37의 루프 조건에 걸려 실행이 종료되기 때문이다.
	vector<pair<int, int>>v(1, { -1, -1 });
	vector<int>bt(k + 1, -1);
	for (i = 0; i < k; i++)
	{
		cin >> j;
		arr[i] = { j,i };
		if (v.back().first < j)
		{
			bt[i] = v.back().second;
			v.push_back(arr[i]);
		}
		else
		{
			auto a = lower_bound(v.begin(), v.end(), arr[i], [](auto a, auto b) {return a.first < b.first; });
			bt[i] = (a - 1)->second; // 중요! : backtrack reference가 'i -> a'가 아닌, 'i -> (a-1)'이다.
			*a = arr[i];
		}
	}
	//backtrack
	deque<int>q;
	for (i = v.back().second; i >= 0; i = bt[i]) // 구현 실수 I: i 초기화 코드를 'v.back().second'로 설정 (dp의 맨 마지막 원소부터 차례대로 백트래킹)하는 것을 떠올리지 못함
		q.push_front(arr[i].first); // 구현 실수 II: LIS 스택에 'arr[i].first'를 푸시해야 하는데, 대신 'arr[i]'를 푸시하는 바람에 컴파일 오류
	cout << q.size() << endl; // 주의! : 해당 구현에서는 v[0]에 미리 {-1, -1}이라는 값을 넣어 초기화했기 때문에 v.size()를 LIS의 길이로 생각하고 출력하면 틀리게 된다!
	for (auto a = q.begin(); a != q.end(); a++)
		cout << *a << ' ';
	cout << endl;
}
