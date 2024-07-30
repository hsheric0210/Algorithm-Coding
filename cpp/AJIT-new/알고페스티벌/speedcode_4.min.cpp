#include<iostream>
#include<set>
#include<vector>
      using              namespace std;    int main(){int    a;cin>>a;for(int b=1;b<=a;++b)
 {vector  <int>               c(31              ,0);                      for(
int           d=1;            d<=30             ;++                       d){set
<int>         e;for          (int               f=1;                       f<=b
;++f)if(d-f>=0)e.            insert            (c[d                        -f]);
int            g=0;          while              (e.                        find
(g)            !=e           .end(               ))                        ++g;
c[d]           =g;}       if(c[30]             ==0)                        cout
                         <<b               <<endl;}return                   0;}
