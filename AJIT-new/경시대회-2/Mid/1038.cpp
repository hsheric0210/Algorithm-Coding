/*
숫자 고르기
https://43.200.211.173/contest/18/problem/1038
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int* e;
int n, i;
int main()
{
	cin >> n;
	e = new int[n + 1]{ 0 };
	for (i = 1; i <= n; i++)
		cin >> e[i];  // 간선 입력
	
	// 위상 정렬의 구현
	while (true)
	{
		bool change = false;
		for (i = 1; i <= n; i++) // 모든 node에 대해서
		{
			if (e[i] < 0) continue;
			int *found = find(e + 1, e + n + 1, i);
			if (found == e + n + 1) // 해당 노드를 가르키는 간선이 없다면
			{
				// 해당 노드와, 해당 노드를 시점으로 하는 간선 삭제 (가르키는 node를 -1로 설정)
				e[i] = -1;
				change = true;
			}
		}
		// 만약 그래프가 변경되지 않았다면 모든 과정이 완료된 것임
		if (!change)
			break;
	}

	vector<int> v;
	for (int i = 1; i <= n; i++)
		if (e[i] > 0)
			v.push_back(i);
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (auto a = v.begin(); a != v.end(); a++)
		cout << *a << endl;
	cout << endl;
}