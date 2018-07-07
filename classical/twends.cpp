#include <bits/stdc++.h>
using namespace std;

int n,tc;
int a[1005];
int dp[1005][1005];

int f(int i,int j) {
    if(i>j) return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ma = INT_MIN;
    if(a[i+1] >= a[j])
        ma = max(ma, f(i+2, j) + (a[i] - a[i+1]));
    if(a[j] > a[i+1])
        ma = max(ma, f(i+1, j-1) + (a[i] - a[j]));
    if(a[j-1] > a[i])
        ma = max(ma, f(i, j-2) + (a[j] - a[j-1]));
    if(a[i] >= a[j-1])
        ma = max(ma, f(i+1, j-1) + (a[j] - a[i]));
    return dp[i][j] = ma;
}

int main() {
    while(true) {
        scanf("%d",&n);
        if(n==0) return 0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        memset(dp,-1,sizeof dp);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++tc,f(1,n));
    }
    return 0;
}
