#include <bits/stdc++.h>
using namespace std;

struct A {
    int start,end,weight;
    bool operator <(const A &o)const {
        if(end == o.end) return start < o.start;
        return end < o.end;
    }
};

int T,n,lo,hi,mid,ind,ans;
int dp[10005];
A interval[10005];

int main()
{
    scanf ("%d",&T);
    while(T--) {
        memset(dp,0,sizeof dp);
        memset(interval,0,sizeof interval);
        scanf("%d",&n);
        for(int i=1; i<=n; i++) {
            scanf("%d %d %d",&interval[i].start,&interval[i].end,&interval[i].weight);
            interval[i].end += interval[i].start;
        }
        sort(interval+1, interval+1+n);
        ans = 0;
        for(int i=1; i<=n; i++) {
            lo = 0, hi = i-1;
            while(lo <= hi) {
                mid = (lo + hi) >> 1;
                if(interval[mid].end < interval[i].start)
                    ind = mid, lo = mid+1;
                if(interval[mid].end > interval[i].start)
                    hi = mid-1;
                if(interval[mid].end == interval[i].start)
                    ind = mid, hi = mid-1;
            }
            dp[i] = max(dp[i-1], dp[ind] + interval[i].weight);
            ans = max(ans, dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
