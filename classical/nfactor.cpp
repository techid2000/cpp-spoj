#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int sieve[N];
int qs[11][N];
int a,b,t,c;
int main() {
    for(int i=2;i<=1000000;i++) {
        if(sieve[i]==0) {
            for(int j=i; j<=1000000; j+=i) {
                sieve[j]++;
            }
        }
    }
    for(int i=1;i<=1000000;i++) {
        qs[sieve[i]][i]++;
        for(int j=0;j<=10;j++)
            qs[j][i]+=qs[j][i-1];
    }
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",qs[c][b]-qs[c][a-1]);
    }
    return 0;
}