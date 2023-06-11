// ICT-1 : 막대기 (문제를 유심히 읽고 예시 여러 개 생각해 보면, 결국 답은 POPCNT이다)
#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	int i;  cin >> i;
	cout << bitset<32>(i).count() << '\n'; // POPCNT
	return 0;
}