#include <bits/stdc++.h>
using namespace std;
int d,n,k,a;
int s[40],dp[40][40];
int main() {
    scanf("%d",&d);
    while(d--) {
        scanf("%d%d",&n,&k);
        memset(s,0,sizeof s);
        memset(dp,0,sizeof dp);
        while(k--) {
            scanf("%d",&a);
            s[a]=1;
        }
        dp[1][1] = 1;
        for(int i=2;i<=2*n;i++) {
            for(int j=0;j<=2*n;j++) {
                if(s[i]==1) {
                    if(j > 0)
                        dp[i][j]+=dp[i-1][j-1];
                } else {
                    if(j > 0)
                        dp[i][j]+=dp[i-1][j-1];
                    dp[i][j]+=dp[i-1][j+1];
                }
            }
        }
        printf("%d\n",dp[2*n][0]);
    }
    return 0;
}