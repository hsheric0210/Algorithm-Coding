// 이친수 찾기 (Fi-binary Number)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;
bool bits[1005];
unsigned long long i,j,k,l,K, Gs[1005], Ge[1005];
int main()
{
	Gs[1]=Ge[1] = 1, Gs[2]=Ge[2] = 2;
	for (i = 3; i < 1000; i++)
	{
		Gs[i] = Gs[i - 2] + Gs[i - 1]; // 그룹의 시작 수의 서수
		Ge[i] = Ge[i - 2] + Ge[i - 1] + 1; // 그룹의 끝 수의 서수
	}

	j = -1;
	cin >> K;
	while (K > 0)
	{
		l = lower_bound(Ge, Ge + 1000, K) - Ge;
		//cout << "group: " << l << '\n';
		if (j == -1)j = l;
		bits[l] = 1;
		K = K - Gs[l];
	}
	for (i = j; i > 0; i--)
		cout << bits[i];
	return 0;
}