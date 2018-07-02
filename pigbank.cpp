#include <bits/stdc++.h>
using namespace std;

int T,e,f,n,p[505],w[505];
int dp[10005];

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&e,&f);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i],&w[i]);
        }
        for(int i=1;i<=f-e;i++){
            dp[i]=1e9;
            for(int j=1;j<=n;j++){
                if(i-w[j]>=0){
                    dp[i]=min(dp[i],dp[i-w[j]]+p[j]);
                }
            }
        }
        if(dp[f-e]==1e9){
            printf("This is impossible.\n");
        } else {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
        }
    }
    return 0;
}
