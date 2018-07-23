#include <bits/stdc++.h>
using namespace std;

int K,L,m,n;
int dp[1000005];
int main()
{
    scanf("%d%d%d",&K,&L,&m);
    for(int i=1; i<=1000000; i++) {
        if(i-1>=0) dp[i] |= dp[i-1]==0;
        if(i-K>=0) dp[i] |= dp[i-K]==0;
        if(i-L>=0) dp[i] |= dp[i-L]==0;
    }
    for(int i=0; i<m; i++) {
        scanf("%d",&n);
        if(dp[n]) putchar('A');
        else putchar('B');
    }
    return 0;
}