#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
int a[100010];
ll dp[100010];
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        for(int i=n;i>=1;i--){
            dp[i]=max(dp[i+2]+a[i],max(dp[i+4]+a[i]+a[i+1],dp[i+6]+a[i]+a[i+1]+a[i+2]));
        }
        printf("%lld\n",dp[1]);
    }
    return 0;
}