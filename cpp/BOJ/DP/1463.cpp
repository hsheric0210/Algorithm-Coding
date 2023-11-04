/*
1로 만들기
https://www.acmicpc.net/problem/1463
*/
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int x;
	cin >> x;
	int size = 3 * x + 1;
	int* arr = new int[size]();
	int inf = 9999999;
	fill(arr, arr + size, inf);
	arr[x] = 0;
	for (int i = x - 1; i > 0; i--)
		arr[i] = min({ arr[i * 3], arr[i * 2], arr[i + 1] }) + 1;
	cout << arr[1] << endl;
	delete[] arr;
}