// Olympiad > 한국정보올림피아드 > KOI 1996 > 중등부 2번
#include<iostream>
#include<deque>
#include<regex>
using namespace std;
int i, j, k, l, x, y, z;
char str[200];
deque<char> q[200];
//(100~1~|01)~
int main()
{
	cin.getline(str, 190);
	regex reg("((100+1+)|(01))+");
	for (i = 0, j = strlen(str); i < j; i++)
	{
		// 전체 문장 그대로 Regex 넣고 돌리면 '100+1+' 부분에서 '1+'이 다음 '100+1+'에 매칭시킬 '1'마저 잡아먹어버리는 문제 발생
	    // 해결: '100' 만나면 그 부분에서 split
		if (str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '0')
			k++;
		q[k].push_back(str[i]);
	}

	x = 1;
	for (i = 0; i <= k; i++)
	{
		if (q[i].empty()) continue;
		x &= y = regex_match(q[i].begin(), q[i].end(), reg);
		//cout << "part'" << string(q[i].begin(), q[i].end()) << "' -> " << y << '\n';
	}

	if (x)
		cout << "SUBMARINE\n";
	else
		cout << "NOISE\n";
	return 0;
}