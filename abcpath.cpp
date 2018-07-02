#include <bits/stdc++.h>
using namespace std;

char tbl[55][55];
int ch[55][55],n,m,u,v,ma,tc;
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
void recur(int i,int j,char c) {
    ch[i][j]=1;
    int newi,newj,maxx=0;
    if(c=='Z') return;
    for(int k=0;k<8;k++) {
        newi=i+dir[k][0], newj=j+dir[k][1];
        if(newi >= 1 && newi<= n && newj>=1 && newj<=m && tbl[newi][newj]==c+1) {
            if(ch[newi][newj]==0)
                recur(newi, newj, c+1);
            maxx = max(maxx, ch[newi][newj]);
        }
    }
    ch[i][j]=maxx+1;
}

int main() {
    while(true) {
        scanf("%d%d",&n,&m);
        if(!(n+m))return 0;
        memset(ch,0,sizeof ch);
        ma=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                scanf(" %c",&tbl[i][j]);
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(tbl[i][j]=='A') {
                    recur(i,j,'A');
                    ma = max(ma, ch[i][j]);
                }
            }
        }
        printf("Case %d: %d\n",++tc,ma);
    }
    return 0;
}
