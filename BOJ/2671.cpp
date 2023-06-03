// Olympiad > �ѱ������ø��ǾƵ� > KOI 1996 > �ߵ�� 2��
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
		// ��ü ���� �״�� Regex �ְ� ������ '100+1+' �κп��� '1+'�� ���� '100+1+'�� ��Ī��ų '1'���� ��ƸԾ������ ���� �߻�
	    // �ذ�: '100' ������ �ڸ���
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