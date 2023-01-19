/*
ǳ��_ajit
https://43.200.211.173/contest/18/problem/80029
*/
#include<iostream>
#include<algorithm>
#include<vector>
typedef struct A {
	int input, index;
};
int acmp(A a, A b)
{
	if (a.input < b.input) return true;
	return a.input == b.input && a.index < b.index;
}
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;

	int *arr = new int[n + 1]{ 0 };
	A* a_arr = new A[n + 1];

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i]; sum += arr[i];
		a_arr[i].input = arr[i]; a_arr[i].index = i;
	}

	if (m >= sum) // �䱸�� �հ谡 �� ��� ������ε� ������ �� ���� ���
	{
		// ��ü�� �Է¹��� ���� �״�� ����ϰ� ����
		for (int i = 1; i <= n; i++)
			cout << arr[i] << ' ';
		cout << endl;
		return 0;
	}

	sort(a_arr + 1, a_arr + n + 1, acmp);
	
	int height = 0, remaining_element_count, next_loop_index; // height
	for (int i = 1; i <= n; i = next_loop_index) // SKILL: Dynamic loop index incremental (j)
	{
		remaining_element_count = n - i + 1; // 
		int height_delta = a_arr[i].input - height; // ���� ����
		int new_m = m - height_delta * remaining_element_count; // ���ο� �հ�
		if (new_m >= 0) // check if the total count doesn't overflow
		{
			m = new_m;
			height = a_arr[i].input;
		}
		else break; // �̹� �ִ� 

		// SKILL: Dynamic loop index incremental (j)
		// ���� ���� ��ȭ�� �Ͼ�� index�� ���Ͽ� j�� �����Ѵ�
		for (next_loop_index = i + 1; next_loop_index <= n; next_loop_index++)
			if (a_arr[i].input < a_arr[next_loop_index].input)
				break;
	}

	int j = m / remaining_element_count;
	int k = m % remaining_element_count;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] <= height) printf("%d ", arr[i]);
		else {
			count++;
			if (count <= k) printf("%d ", height + j + 1);
			else printf("%d ", height + j);
		}
	}
}