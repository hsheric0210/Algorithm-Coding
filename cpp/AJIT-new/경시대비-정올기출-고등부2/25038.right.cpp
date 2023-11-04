#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
	int x, ct = 0;
	queue<int> A, B, C;
	string s;

	cin >> s;
	for (x = 0; x < s.size(); x++) {
		if (s[x] == 'A') A.push(x);
		else if (s[x] == 'B') B.push(x);
		else if (s[x] == 'C') C.push(x);
	}
	while (1) {
		if (B.empty() == true || C.empty() == true) break;
		else {
			if (B.front() < C.front()) {
				ct++;
				B.pop();
			}
			C.pop();
		}
	}
	while (1) {
		if (B.empty() == true || A.empty() == true) break;
		else {
			if (A.front() < B.front()) {
				ct++;
				A.pop();
			}
			B.pop();
		}
	}
	cout << ct;
	return 0;
}