#include <bits/stdc++.h>
using namespace std;

long long a,b;

long long amount(long long a, long long b) {
    long long dv = a/b;
    long long md = a%b;
    if(dv < 10) {
        return (dv*(dv-1)/2)*b + dv*(md+1); 
    }
    return (dv/10)*45*b + ((dv%10)*(dv%10-1)/2)*b + (dv%10)*(md+1) + amount(a,b*10);
}
int main() {
    while(true) {
        scanf("%lld %lld",&a,&b);
        if(a==-1 && b==-1) return 0;
        printf("%lld\n",amount(b,1)-amount(a-1,1));
    }

    return 0;
}