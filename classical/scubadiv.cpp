#include <bits/stdc++.h>
using namespace std;
int t,oxy,nit,n;
int O[1005],N[1005],W[1005];
int dp[1005][21+1][79+1];
int main()
{
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&oxy,&nit);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&O[i],&N[i],&W[i]);
        fill_n(&dp[0][0][0],1005*22*80,1e9);
        dp[0][0][0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i][0][0] = 0;
            for(int j=0;j<=21;j++) {
                for(int k=0;k<=79;k++) {
                    dp[i][j][k] = min(dp[i-1][j][k],
                    dp[i-1][max(0,j-O[i])][max(0,k-N[i])] + W[i]);
                }
            }
        }
        printf("%d\n",dp[n][oxy][nit]);
    }
    return 0;
}