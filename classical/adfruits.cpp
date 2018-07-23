#include <bits/stdc++.h>
using namespace std;

char sa[2005];
char sb[2005];
int dp[2005][2005];
int pre[2005][2005][2];
int la,lb;

void track(int i,int j) {
    if(i==0&&j==0) return;
    track(pre[i][j][0],pre[i][j][1]);
    if(pre[i][j][0]==i-1&&pre[i][j][1]==j-1)
        putchar(sa[i]);
    else if(pre[i][j][0]==i-1) putchar(sa[i]);
    else if(pre[i][j][1]==j-1) putchar(sb[j]);
}

int main() { 
    while(scanf(" %s %s",sa+1,sb+1)!=EOF) {
        memset(pre,0,sizeof pre);
        memset(dp,0,sizeof dp);
        la=strlen(sa+1), lb=strlen(sb+1);
        for(int i=1;i<=la;i++)
            dp[i][0] = i,pre[i][0][0] = i-1, pre[i][0][1] = 0;;
        for(int i=1;i<=lb;i++)
            dp[0][i] = i,pre[0][i][0] = 0, pre[0][i][1] = i-1;
        for(int i=1;i<=la;i++) {
            for(int j=1;j<=lb;j++) {
                if(sa[i]==sb[j]) {
                    pre[i][j][0] = i-1, pre[i][j][1] = j-1;
                    dp[i][j]=dp[i-1][j-1]+1;
                } else {
                    if(dp[i-1][j]<dp[i][j-1]) {
                        pre[i][j][0] = i-1, pre[i][j][1] = j;
                        dp[i][j] = dp[i-1][j] + 1;
                    } else {
                        pre[i][j][0] = i, pre[i][j][1] = j-1;
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                }
            }
        }
        track(la, lb);
        putchar('\n');
    }
}