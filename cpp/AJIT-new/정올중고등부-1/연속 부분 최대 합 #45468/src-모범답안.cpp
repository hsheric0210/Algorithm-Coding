#include <stdio.h>

int main(){
	int i,j,k,st=1,en=1,s,e,gap,con;
	scanf("%d",&k);
	for(i=1,s=1,e=1;i<=k;i++){
		scanf("%d",&j);
		if(i==1){
			gap=j;
			con=j;
		}
		else{
			if(j<con+j){
				con+=j;
				e=i;
			}
			else{
				con=j;
				s=i;
				e=i;
			}
			if(gap<con){
				gap=con;
				st=s;
				en=e;
			}
		}
	}
	printf("%d %d %d",st,en,gap);
	return 0;
}
