#include <bits/stdc++.h>
using namespace std;

int n,m,ok,cnt;
int ch[1005][1005];
char a[1005][1005];
map<char,pair<int,int>>d;
void dfs(int i,int j) {
    ch[i][j]=1;
    int ni=i+d[a[i][j]].first;
    int nj=j+d[a[i][j]].second;
    if(ni>=1&&ni<=n&&nj>=1&&nj<=m) {
        if(ch[ni][nj]==0) {
            dfs(ni,nj);
        } else if(ch[ni][nj]==2) {
            ok=0;
        }
    }
    ch[i][j]=2;
}
int main() {
    function<void()> DEBUG = []() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                printf("%d",ch[i][j]);
            }
        printf("\n");
        }
    };
    d['N']={-1,0};
    d['E']={0,1};
    d['S']={1,0};
    d['W']={0,-1};
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf(" %s",a[i]+1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(ch[i][j]==0) {
                ok=1;
                dfs(i,j);
                if(ok)cnt++;
                //DEBUG();
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}