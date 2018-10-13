#include <bits/stdc++.h>
using namespace std;

int T,k,n,h[20005],mn;

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%d",&h[i]);
        }
        sort(h,h+n);
        mn = INT_MAX;
        for(int i=0;i<n-k+1;i++) {
            mn = min(mn,h[i+k-1]-h[i]);
        }
        printf("%d\n",mn);
    }
}