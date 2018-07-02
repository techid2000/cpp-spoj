#include <bits/stdc++.h>
using namespace std;

long long d[8000005];
long long k;
int t,a;
long long f(int i) {
    if(i<=8000000) return d[i];
    long long k=i;
    k=max(k,(long long)i/2+i/3+i/4);
    k=max(k,f(i/2)+i/3+i/4);
    k=max(k,i/2+f(i/3)+i/4);
    k=max(k,i/2+i/3+f(i/4));
    k=max(k,f(i/2)+f(i/3)+i/4);
    k=max(k,f(i/2)+i/3+f(i/4));
    k=max(k,i/2+f(i/3)+f(i/4));
    k=max(k,f(i/2)+f(i/3)+f(i/4));
    return k;
}
int main() {
    for(int i=1;i<=8000000;i++) {
        k=i;
        k=max(k,(long long)i/2+i/3+i/4);
        k=max(k,d[i/2]+i/3+i/4);
        k=max(k,i/2+d[i/3]+i/4);
        k=max(k,i/2+i/3+d[i/4]);
        k=max(k,d[i/2]+d[i/3]+i/4);
        k=max(k,d[i/2]+i/3+d[i/4]);
        k=max(k,i/2+d[i/3]+d[i/4]);
        k=max(k,d[i/2]+d[i/3]+d[i/4]);
        d[i]=k;
    }
    for(t=0;t<10;t++) {
        scanf("%d",&a);
        printf("%lld\n",f(a));
    }
}
