#include <bits/stdc++.h>
using namespace std;
int tc;
int r,c,si,sj,di,dj,dot,ok;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int pass[25][25];
char maze[25][25];
void dfs(int i,int j) {
    pass[i][j]=1;
    if(i==di&&j==dj){
        ok=1;
        return;
    }
    int ni,nj;
    if(!ok){
        for(int k=0;k<4;k++) {
            ni=i+dir[k][0];
            nj=j+dir[k][1];
            if(ni>=1&&ni<=r&&nj>=1&&nj<=c&&
            maze[ni][nj]=='.'&&!pass[ni][nj]){
                dfs(ni,nj);
            }
        }
    }
    pass[i][j]=0;
}
int main() {
    scanf("%d",&tc);
    while(tc--){
        memset(pass,0,sizeof pass);
        dot=0;
        ok=0;
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                scanf(" %c",&maze[i][j]);
                if(i==1||j==1||i==r||j==c){
                    if(maze[i][j]=='.'){
                        dot++;
                        if(dot==1){
                            si=i,sj=j;
                        } else {
                            di=i,dj=j;
                        }
                    }
                }
            }
        }
        if(dot==2) {
            dfs(si,sj);
            if(ok){
                printf("valid\n");
            } else {
                printf("invalid\n");
            }
        } else {
            printf("invalid\n");
        }
    }
    return 0;
}