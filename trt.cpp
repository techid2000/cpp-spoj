#include <bits/stdc++.h>
using namespace std;

int n;
int a[2005];
int dp[2005][2005];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int k=1;k<=n;k++){
        for(int i=1,j;i<=n-k+1;i++){
            j=i+k-1;
            dp[i][j]=max(dp[i+1][j]+a[i]*(n-k+1),dp[i][j-1]+a[j]*(n-k+1));
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
