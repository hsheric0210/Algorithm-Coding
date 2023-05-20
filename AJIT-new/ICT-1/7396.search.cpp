// ICT-1 : ¸·´ë±â
#include<iostream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<numeric>
using namespace std;
int i, j, k, l, m, n, p, q, r, x, y, z;
deque<int>dq;
int main()
{
	dq.push_back(64);
	cin >> x;
	while (x < accumulate(dq.begin(), dq.end(), 0))
	{
		sort(dq.begin(), dq.end()); // WORST SOLUTION TO FIND MIN ELEMENT EVER
		int fr = dq.front();
		dq.pop_front();
		k = accumulate(dq.begin(), dq.end(), fr / 2);
		if (k < x)
			dq.push_back(fr / 2);
		dq.push_back(fr / 2);
	}
	cout << dq.size() << '\n';
}