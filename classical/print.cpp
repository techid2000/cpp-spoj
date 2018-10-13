#include <bits/stdc++.h>
using namespace std;

int t;
int L,U,st;
int sieve[1000005];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&L,&U);
        memset(sieve,0,sizeof sieve);
        for(int k=2; k<=sqrt(U); k++) {
            st = L-(L%k);
            if(st < L) st+=k;
            for(int i=st; i<=U; i+=k) {
                if(i==k) continue;
                sieve[i-L]=1;
            }
        }
        for(int i=L; i<=U; i++) {
            if(!sieve[i-L]) {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}