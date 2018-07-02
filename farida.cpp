#include <bits/stdc++.h>
using namespace std;

int T,n;
long long dp[10005],a[10005];
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%lld",a+i);
        }
        dp[1]=a[1];
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        }
        printf("Case %d: %lld\n",t,dp[n]);
    }
    return 0;
}
