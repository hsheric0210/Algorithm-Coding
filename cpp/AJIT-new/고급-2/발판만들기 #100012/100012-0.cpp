#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,k,l,p,q,r,H[100005], A[100005];
vector<int>D;
int main()
{
	cin>>N; for(i=1;i<=N;i++) cin>>H[i];
	for(i=1;i<=N;i++)
	{
		// 비었거나 더 클 경우, 항상 넣기
		// 더 작을 경우, 나보다 작은 것들 중 가장 작은 것 찾아 이를 포함 이전 모든 것 빼기
		if (!D.empty() && D.back() > H[i])
		{
			for(j=D.size()-1,k=H[i],l=-1;j>0;j--) if(D[j]<k) { k=D[j]; l=j; }
			if(l>0&&l!=i) // 나보다 작은 것이 있고, 이가 나 자신이 아님
				D.erase(D.begin(), D.begin()+l+1); // 해당원소 포함 날리기
		}
		D.push_back(H[i]);
		j=*min_element(D.begin(), D.end());
		A[i] = j*D.size();
	}
	cout<<*max_element(A+1,A+N+1);
	return 0;
}