#include <bits/stdc++.h>
using namespace std;

int T,h,w,maxx;
int dp[200][200],a[105][105];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&h,&w);
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0; i<=h+1;i++){
            for(int j=0;j<=w+1;j++){
                if(i>=1&&i<=h&&j>=1&&j<=w)
                    if(i==h)
                        dp[i][j]=a[i][j];
                    else
                        dp[i][j]=0;
                else
                    dp[i][j]=-1e9;
            }
        }

        for(int i=h-1;i>=1;i--){
            for(int j=1;j<=w;j++){
                dp[i][j]=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]))+a[i][j];
            }
        }
        maxx = -1e9;
        for(int i=1;i<=w;i++){
            maxx = max(maxx, dp[1][i]);
        }
        printf("%d\n",maxx);
    }
    return 0;
}
