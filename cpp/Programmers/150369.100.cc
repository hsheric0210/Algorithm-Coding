#include <vector>
#define f(x) (x-1)
using namespace std;
int i,j,k;
long long solution(int c, int n, vector<int> d, vector<int> p) {
    long long a = 0;
    for(i=n;i>0;i--)
    {
        j=j+d[f(i)];
        k=k+p[f(i)];
        while(j>0||k>0)
        {
            a=a+(i<<1);
            j=j-c;
            k=k-c;
        }
    }
    return a;
}