#include <bits/stdc++.h>
using namespace std;

int tc;
int n,m,ok;
char s[15]="ALLIZZWELL";
char a[105][105];
int mark[105][105];
int d[] = {0,1,-1};
void dfs(int i,int j,int k) {
    if(k==9) {
        ok=1;
        return;
    }
    int ni,nj;
    mark[i][j]=1;
    for(int p=0; p<3; p++) {
        for(int q=0; q<3; q++) {
            if(p==0 && q==0) continue;
            ni=i+d[p], nj=j+d[q];
            if(ni >= 1 && ni <= n && nj >= 1 && nj <= m) { 
                if(s[k+1]==a[ni][nj] && !mark[ni][nj]) {
                    dfs(ni,nj,k+1);
                }
            }
        }
    }
    mark[i][j]=0;
}

int main()
{
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) {
            scanf(" %s",a[i]+1);
        }
        ok=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(a[i][j]=='A') {
                    dfs(i,j,0);
                    if(ok) break;
                }
            }
            if(ok) break;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}