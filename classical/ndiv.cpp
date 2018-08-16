#include <bits/stdc++.h>
using namespace std;
int a,b,n,st,cnt;
int sieve[10005];
int main() {
    cin >> a >> b >> n;
    for(int i=1; i<=sqrt(b); i++) {
        st = a - (a%i);
        if(st < a) st += i;
        for(int j=st; j<=b; j+=i) {
            if(j/i == i) sieve[j-a]++;
            else if(j/i > i) sieve[j-a]+=2;
        }
    }
    for(int i=a; i<=b; i++) {
        if(sieve[i-a] == n) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}