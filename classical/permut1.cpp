#include <bits/stdc++.h>
using namespace std;

int T,n,k;
int dp[15][100];

int f(int a, int b) {
    if(a==1) {
        if(b==0) return dp[a][b] = 1;
        else return dp[a][b] =  0;
    }
    if(dp[a][b] != -1)
        return dp[a][b];
    int sum = 0;
    for(int i=0; i<=a-1; i++) {
        sum += f(a-1, b-i);
    }
    return sum;
}

int main()
{
    memset(dp,-1,sizeof dp);
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&k);
        printf("%d\n",f(n,k));
    }
    return 0;
}