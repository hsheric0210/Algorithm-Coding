// ICT-1 : ����� (������ ������ �а� ���� ���� �� ������ ����, �ᱹ ���� POPCNT�̴�)
#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	int i;  cin >> i;
	cout << bitset<32>(i).count() << '\n'; // POPCNT
	return 0;
}