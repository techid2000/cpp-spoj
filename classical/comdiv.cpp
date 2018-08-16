#include <bits/stdc++.h>
using namespace std;
int sieve[1000000],t,a,b;
int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}
int main() {
    for(int i=1; i<=1000000; i++) {
        for(int j=i; j<=1000000; j+=i) {
            sieve[j]++;
        }
    }
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&a,&b);
        printf("%d\n",sieve[gcd(a,b)]);
    }
    return 0;
}