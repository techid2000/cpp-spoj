//#hard, #ad-hoc, #dp
#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int qy[505][505];
int qb[505][505];
int n,m;

int main() {
    while(true) {
        scanf("%d%d",&n,&m);
        if(n+m==0) return 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&qy[i][j]);
                qy[i][j]+=qy[i][j-1];
            }
        }    
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                scanf("%d",&qb[i][j]);
                qb[i][j]+=qb[i-1][j];
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j]=max(dp[i-1][j]+qy[i][j], dp[i][j-1]+qb[i][j]);
            }
        }
        printf("%d\n",dp[n][m]);
    }
}