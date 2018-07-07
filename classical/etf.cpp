#include <bits/stdc++.h>
using namespace std;

int sieve[1000005];
int n,k,j;
long long a,b;
vector<int>prime;
vector<int>want;
int main()
{
    sieve[1]=1;
    for(int i=2;i<=sqrt(1000000);i++) {
        if(sieve[i]==0) {
            for(int j=i*i; j<=1000000;j+=i) {
                sieve[j]=1;
            }
        }
    }
    for(int i=2;i<=1000000;i++) {
        if(!sieve[i])
            prime.push_back(i);
    }
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&k);
        j=0;
        a=k;
        want.clear();
        while(k > 1) {
            if(!sieve[k]&&(want.size()==0 || want.back()!=k)) {
                want.push_back(k);
                break;
            }
            if(k%prime[j]==0) {
                if(want.size()==0 || want.back()!=prime[j])
                    want.push_back(prime[j]);
                k/=prime[j];
            } else {
                j++;
            }
        }
        b=1;
        for(int i=0;i<want.size();i++) {
            a*=(long long)want[i]-1;
            b*=(long long)want[i];
        }
        printf("%lld\n",a/b);
    }
    return 0;
}
