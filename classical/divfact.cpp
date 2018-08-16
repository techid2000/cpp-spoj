#include <bits/stdc++.h>
#define ll long long
const ll mod = 1000000007;
using namespace std;

vector<int>primes;
int b[50005],cnt,tc,n;
ll a[50005];
int main() {
    primes.push_back(2);
    for(int i=3,j; i<=50000; i++) {
        for(j=2; j<=sqrt(i); j++) {
            if(i%j==0) {
               break; 
            }
        }
        if(j>sqrt(i))primes.push_back(i);
    }
    for(int i = 0; i<=50000; i++)
        a[i] = 1LL;
    for(int i=0, k; i<primes.size(); i++) {
        memset(b,0,sizeof b);
        for(ll j=primes[i]; j<=50000; j+=primes[i]) {
            b[j] = 1 + b[j/primes[i]];
        }
        for(int j=primes[i]; j<=50000; j++) {
            b[j]+=b[j-1];
            a[j]*=b[j]+1LL;
            a[j]%=mod;
        }
    }
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}