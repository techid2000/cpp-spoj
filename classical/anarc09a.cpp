#include <bits/stdc++.h>
using namespace std;
char s[2005];
int len,dp[2005][2005],tc;
int main()
{
    while(true){
        tc++;
        scanf(" %s",s+1);
        if(s[1]=='-')return 0;
        len=strlen(s+1);
        for(int i=1;i<=len;i++)
            for(int j=0;j<=len;j++)
                dp[i][j]=1e9;
        if(s[1]=='}')
            dp[1][1]=1;
        else
            dp[1][1]=0;
        for(int i=2;i<=len;i++){
            for(int j=0;j<=i;j++){
                if(j-1>=0) {
                    if(s[i]=='{') dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
                if(j+1<=len) {
                    if(s[i]=='}')dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
                    else dp[i][j]=min(dp[i][j],dp[i-1][j+1]+1);
                }
            }
        }
        printf("%d. %d\n",tc,dp[len][0]);
    }
    return 0;
}
