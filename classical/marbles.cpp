#include <bits/stdc++.h>
using namespace std;

long long n,k,a,b,c,u,d;
int opt[1000005];
int T;
int main()
{
    scanf("%d",&T);
    while(T--) {
        memset(opt,0,sizeof opt);
        scanf("%lld %lld",&n,&k);
        a = n-1, b = k-1, c = a-b;
        if(c > b) swap(b,c);
        for(long long i=a; i>b; i--) {
            u = i;
            for(long long j=2; j<=sqrt(i); j++) {
                while(u % j == 0) {
                    opt[j]++;
                    u /= j;
                }
            }
            if(u > 1)
                opt[u]++;
        }
        for(long long i=1; i<=c; i++) {
            u = i;
            for(long long j=2; j<=sqrt(i); j++) {
                while(u % j == 0) {
                    opt[j]--;
                    u /= j;
                }
            }
            if(u > 1)
                opt[u]--;
        }
        u = 1, d = 1;
        for(int i=2; i<=1000000; i++)
            if(opt[i] > 0)
                for(int j=0; j<opt[i]; j++)
                    u *= i;
            else if(opt[i] < 0)
                for(int j=0; j>opt[i]; j--)
                    d *= i;
        printf("%lld\n",u/d);
    }
    return 0;
}