#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll k,d,e,p;
stack<char>s;
int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%lld",&k);
        d = 1,e = 0;
        while(true) {
            p = ceil(1.0*(k-e)/d);
            if(k - e <= 0) break;
            if(p % 2 == 1) s.push('5');
            else s.push('6');
            d <<= 1;
            e += d;
        }
        while(!s.empty()){
            putchar(s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}