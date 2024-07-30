#include<iostream>
#include<vector>
using namespace std;int main()
{int                    N,i,j
,cnt                    =0;
vector                  <bool>
chk                    (200000
,true                    );cin
>>N;                     for(i
=2;                      cnt<
N;i++                    ){if(
chk                      [i])
{cout                    <<i<<
' ';                     cnt++
;for                     (j=i*
2;j<200000;j+=i){chk[j]=false;}}}}
