#include <bits/stdc++.h>
using namespace std;

int n,tc;
int love[25][100];
long long dp[5100000];

long long td(int a,int b) {
    if(a==0&&b==0)
        return 1;
    if(dp[b]!=-1) return dp[b];
    long long sum = 0;
    for(int j=1;j<=n;j++) {
        if(love[a][j] && (b&(1<<j))>0)
            sum += td(a-1,b-(1<<j));
    }
    return dp[b]=sum;
}


int main() {
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&love[i][j]);
            }
        }
        memset(dp,-1,sizeof dp);
        printf("%lld\n",td(n,((1<<n)-1)<<1));
    }
}
