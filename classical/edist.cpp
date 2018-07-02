#include <bits/stdc++.h>
using namespace std;

int T,la,lb,opt;
char a[2005],b[2005];
int dp[2005][2005];

int main()
{
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof dp);
        scanf(" %s",a+1);
        scanf(" %s",b+1);
        la=strlen(a+1);
        lb=strlen(b+1);
        for(int i=1;i<=la;i++)
            dp[i][0]=i;
        for(int i=1;i<=lb;i++)
            dp[0][i]=i;
        for(int i=1;i<=la;i++){
            for(int j=1;j<=lb;j++){
                if(a[i]!=b[j])
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                else
                    dp[i][j]=dp[i-1][j-1];
            }
        }
        printf("%d\n",dp[la][lb]);
    }
    return 0;
}
