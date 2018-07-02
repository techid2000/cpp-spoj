#include <bits/stdc++.h>
using namespace std;

int tc,n,m,k,Q,a,b;
int dp[10005][110];
int par[10005];
int in[10005];
int h[10005];
int root;
vector<int>g[10005];

void findpar(int node,int prev,int height){
    h[node]=height;
    par[node]=prev;
    dp[node][0]=prev;
    for(int i=1;i<11;i++){
        dp[node][i]=dp[dp[node][i-1]][i-1];
    }
    for(auto next : g[node]){
        findpar(next,node,height+1);
    }
}

int main() {
    scanf("%d",&tc);
    for(int tcc=1;tcc<=tc;tcc++){
        //clear
        memset(dp,0,sizeof dp);
        memset(par,0,sizeof par);
        memset(in,0,sizeof in);
        memset(h,0,sizeof h);
        //clear
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            g[i].clear();
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                scanf("%d",&k);
                g[i].push_back(k);
                in[k]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0)
            {root=i;break;}
        }
        findpar(root,root,0);
        printf("Case %d:\n",tcc);
        scanf("%d",&Q);
        while(Q--){
            scanf("%d%d",&a,&b);
            int i;
            while(h[a]!=h[b]){
                if(h[a]<h[b]){
                    for(i=0;i<11 && h[a]<=h[dp[b][i]];i++);
                    b=dp[b][i-1];
                } else {
                    for(i=0;i<11 && h[b]<=h[dp[a][i]];i++);
                    a=dp[a][i-1];
                }
            }
            if(a==b)printf("%d\n",a);
            else {
                while(dp[a][0]!=dp[b][0]){
                    for(i=0;i<11 && dp[a][i]!=dp[b][i];i++);
                    a=dp[a][i-1], b=dp[b][i-1];
                }
                printf("%d\n",dp[a][0]);
            }
        }
    }
    return 0;
}


