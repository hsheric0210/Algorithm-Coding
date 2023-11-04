#include <stdio.h>
#define LL long long
LL a[1000001];
int main() {
	LL i,j,k,n,odd=0,even=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//홀수
	for(i=0,j=0;i<n;i++){
		if(a[i]%2==1){
			odd+=(i-j);
			j++;
		}
	}
	//짝수
	for(i=0,j=0;i<n;i++){
		if(a[i]%2==0){
			even+=(i-j);
			j++;
		}
	}
	if(odd<even) k=odd;
	else k=even;
	printf("%lld",k);
	return 0;
}