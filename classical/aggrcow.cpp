#include <bits/stdc++.h>
using namespace std;

int t,n,c,i;
int p,q;
int l,r,m;
int a[100005];

int main()
{
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&c);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        l=0,r=1e9;
        while(l<r) {
            m = (l+r+1) >> 1;
            p = 0;
            for(i=0;i<c-1;i++) {
                p = lower_bound(a,a+n,a[p]+m)-a;
                if(p>=n) break;
            }
            if(i<c-1) r = m-1;
            else l = m;
        }
        printf("%d\n",l);
    }
    return 0;
}
