// ���̰���
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
typedef struct _rng
{
	int begin, end;
	bool includes(int val) { return val >= begin && val <= end; }
}range;
using namespace std;
int i, j, k, l, N,p,q,r;
vector<range>A;
int conv2min(int n) { return n % 100 + (n / 100 * 60); }
int main()
{
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> k >> l;
		A.push_back({ p=conv2min(k) - 10, q=conv2min(l) + 10 });
		//cout << "mod: " << p << ' ' << q << '\n';
	}

	// sort & merge
	sort(A.begin(), A.end(), [](range a, range b) {return a.begin < b.begin; });
	for (i = 0; i < A.size()-1; i++)
	{
		// ���� �Ǽ�: ���� ���� ������ ��ø�Ǿ� ���� ���, �� �� ���� ù��° ������ ���յǴ� ���װ� �־��� (while�� ��� if�� ������� ��)
		while (i < A.size() - 1 && A[i].includes(A[i + 1].begin))
		{
			//cout << "[" << A[i].begin << ", " << A[i].end << "] merge [" << A[i + 1].begin << ", " << A[i + 1].end << "]\n";
			A[i] = { min(A[i].begin, A[i + 1].begin), max(A[i].end, A[i + 1].end) };
			A.erase(A.begin() + i + 1);
		}
	}

	k = max(q=A[0].begin - 10 * 60, // �ϰ����۽ð�, ����10��
		r=22 * 60 - A.back().end); // �ϰ�����ð�, ����10�� (22��)
	//cout << "bef: " << q << " aft: " << r << '\n';
	for (i = 0; i < A.size() - 1; i++)
	{
		k = max(k, p = A[i + 1].begin - A[i].end);
		//cout << "dlt: " << p << '\n';
	}
	cout << k;
	return 0;
}