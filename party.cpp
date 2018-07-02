#include <bits/stdc++.h>
using namespace std;

int budget, parties;
int arr[105][2];
int dp[105][505];
int main()
{
    while(true) {
        scanf("%d%d",&budget,&parties);
        memset(dp,0,sizeof dp);
        if(budget==0&&parties==0)return 0;
        for(int i=1;i<=parties;i++){
            scanf("%d%d",&arr[i][0],&arr[i][1]);
        }
        for(int i=1;i<=parties;i++){
            for(int j=0;j<=budget;j++){
                dp[i][j]=dp[i-1][j];
                if(j-arr[i][0] >= 0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i][0]]+arr[i][1]);
                }
            }
        }
        for(int i=0;i<=budget;i++){
            if(dp[parties][i]==dp[parties][budget]){
                printf("%d ",i);
                break;
            }
        }
        printf("%d\n",dp[parties][budget]);
    }
    return 0;
}
