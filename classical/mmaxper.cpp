#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005][2];
int dp[1005][2];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    dp[1][0]=a[1][1],dp[1][1]=a[1][0];
    for(int i=2;i<=n;i++) {
        dp[i][0] = max(dp[i-1][0]+abs(a[i][0]-a[i-1][0])+a[i][1],
                    dp[i-1][1]+abs(a[i][0]-a[i-1][1])+a[i][1]);
        dp[i][1] = max(dp[i-1][0]+abs(a[i][1]-a[i-1][0])+a[i][0],
                    dp[i-1][1]+abs(a[i][1]-a[i-1][1])+a[i][0]);
    }
    printf("%d\n",max(dp[n][0],dp[n][1]));
}