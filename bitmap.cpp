#include <bits/stdc++.h>
using namespace std;

int n,m,t;
int Map[200][200];
int ans[200][200];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
vector<pair<int,int>>w1;
vector<pair<int,int>>w2;

struct state{
    int i,j,step,turn,ldir;
};
queue<state>q;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        w1.clear();
        w2.clear();
        scanf("%d%d",&n,&m);
        char cc;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&cc);
                Map[i][j]=cc-'0';
                if(Map[i][j]==1){
                    w1.push_back(make_pair(i,j));
                }
            }
        }
        for(auto x:w1){
            int k;
            for(k=0;k<4;k++){
                if(x.first+dir[k][0]>=1 && x.first+dir[k][0]<=n &&
                   x.second+dir[k][1]>=1 && x.second+dir[k][1]<=m){
                    if(Map[x.first+dir[k][0]][x.second+dir[k][1]]==0){
                        break;
                    }
                }
            }
            if(k<4){
                w2.push_back(x);
            }
        }
        memset(ans,-1,sizeof ans);
        for(auto x:w2){
            ans[x.first][x.second]=0;
            q.push({x.first,x.second,0,0,-1});
        }
        while(!q.empty()){
            int ni=q.front().i;
            int nj=q.front().j;
            int nstep=q.front().step;
            int nturn=q.front().turn;
            int nldir=q.front().ldir;
            q.pop();
            if(nturn==0){
                for(int k=0;k<4;k++){
                    int mi=ni+dir[k][0],mj=nj+dir[k][1];
                    if(mi>=1 &&mi<=n &&mj>=1 && mj<=m && Map[mi][mj]==0 && ans[mi][mj]==-1){
                        ans[mi][mj]=nstep+1;
                        q.push({mi,mj,nstep+1,(nldir!=-1 && k!=nldir),k});
                    }
                }
            } else {
                int mi=ni+dir[nldir][0],mj=nj+dir[nldir][1];
                if(mi>=1 &&mi<=n &&mj>=1 && mj<=m && Map[mi][mj]==0 && ans[mi][mj]==-1){
                    ans[mi][mj]=nstep+1;
                    q.push({mi,mj,nstep+1,1,nldir});
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d ",max(ans[i][j],0));
            }
            printf("\n");
        }
    }
    return 0;
}
