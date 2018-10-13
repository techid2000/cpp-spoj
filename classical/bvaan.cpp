#include <bits/stdc++.h>
using namespace std;

int t,l1,l2,k,ans;
char s1[105],s2[105];
int dp[105][105][105];

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf(" %s %s",s1+1,s2+1);
        scanf("%d",&k);
        l1=strlen(s1+1);
        l2=strlen(s2+1);
        fill_n(&dp[0][0][0],105*105*105,-1e9);
        for(int i=0;i<=l1;i++) {
            for(int j=0;j<=l2;j++) {
                dp[i][j][0] = 0;
            }
        }
        for(int i=1; i<=l1; i++) {
            for(int j=1;j<=l2;j++) {
                for(int p=1;p<=k;p++) {
                    if(s1[i]==s2[j])
                        dp[i][j][p]=max(dp[i][j][p],dp[i-1][j-1][p-1]+(int)s1[i]);
                    dp[i][j][p]=max(dp[i][j][p],max(dp[i-1][j][p],dp[i][j-1][p]));
                }
            }
        }
        ans = 0;
        for(int i=1;i<=l1;i++) {
            for(int j=1;j<=l2;j++) {
                ans = max(ans, dp[i][j][k]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}