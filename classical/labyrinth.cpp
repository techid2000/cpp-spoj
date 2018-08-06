#include <bits/stdc++.h>
using namespace std;

int tc,r,c,maxx;
char tbl[1005][1005];
bool pass[1005][1005];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector <pair<int,int>>v[1005][1005];
vector <pair<int,int>>all;
int mem[1005][1005][2];
void dfs(int i,int j) {
    pass[i][j] = true;
    all.push_back({i, j});
    int ni, nj;
    for(int k = 0; k < 4; k++) {
        ni = i + dir[k][0];
        nj = j + dir[k][1];
        if(ni >= 1 && ni <= r && nj >= 1 && nj <= c && tbl[ni][nj]=='.' && !pass[ni][nj]) {
            v[i][j].push_back({ni,nj});
            v[ni][nj].push_back({i,j});
            dfs(ni,nj);
        }
    }
}
void dfs2(int i,int j,int pi, int pj) {
    if(v[i][j].size()==1 && v[i][j][0].first==pi && v[i][j][0].second == pj) {
        mem[i][j][0] = 0;
        mem[i][j][1] = 0;
        return;
    }
    int ni, nj;
    mem[i][j][0] = mem[i][j][1] = -1;
    for(auto adj : v[i][j]) {
        ni = adj.first, nj = adj.second;
        if(ni==pi && nj==pj) continue;
        dfs2(ni, nj, i, j);
        if(mem[ni][nj][0] > mem[i][j][0]) {
            mem[i][j][1] = mem[i][j][0];
            mem[i][j][0] = mem[ni][nj][0];
        } else if(mem[ni][nj][0] > mem[i][j][1]) {
            mem[i][j][1] = mem[ni][nj][0];
        }
    }
    if(mem[i][j][0] != -1)
        mem[i][j][0]++;
    if(mem[i][j][1] != -1)
        mem[i][j][1]++;
    maxx = max(maxx, (mem[i][j][0]!=-1?mem[i][j][0]:0) + (mem[i][j][1]!=-1?mem[i][j][1]:0));
}
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d %d",&c,&r);
        for(int i=1; i<=r; i++)
            scanf(" %s",tbl[i]+1);
        for(int i=0; i<all.size(); i++) {
            pass[all[i].first][all[i].second] = false;
            v[all[i].first][all[i].second].clear();
        }
        all.clear();
        maxx = 0;
        for(int i=1,j; i<=r; i++) {
            for(j=1; j<=c; j++) {
                if(tbl[i][j] == '.' && pass[i][j]==false) {
                    dfs(i,j);
                    dfs2(i,j,i,j);
                }
            }
        }
        printf("Maximum rope length is %d.\n",maxx);
    }
    return 0;
}