#include <bits/stdc++.h>
using namespace std;

int tc,ds,n,k;
int dp[105][105][2];

int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d%d%d",&ds,&n,&k);
        memset(dp,0,sizeof(dp));
        dp[1][0][0] = dp[1][0][1] = 1;
        for(int i=2;i<=n;i++) {
            for(int j=0; j<=k; j++) {
                dp[i][j][0] = dp[i-1][j][1] + dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][0];
                if(j > 0)
                dp[i][j][1] += dp[i-1][j-1][1];
            }
        }
        printf("%d %d\n",ds,dp[n][k][0]+dp[n][k][1]);
    }
    return 0;
}