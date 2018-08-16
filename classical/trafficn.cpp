#include <bits/stdc++.h>
using namespace std;
int tc;
int u,v,w,a,b,c;
int n,m,k,s,t;
int dst[10005][2];
vector<pair<pair<int,int>,int>>g[10005];
priority_queue<pair<int,pair<int,int>>>q;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=0;i<m;i++) {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back({{v,w},0});
        }
        for(int i=0;i<k;i++) {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back({{v,w},1});
            g[v].push_back({{u,w},1});
        }
        memset(dst,-1,sizeof dst);
        q.push({0,{s,0}});
        while(!q.empty()) {
            w=-q.top().first;
            u=q.top().second.first;
            k=q.top().second.second;
            q.pop();
            if(dst[u][k]==-1) {
                dst[u][k]=w;
                if(u == t) {
                    printf("%d\n",w);
                    while(!q.empty()) q.pop();
                    break;
                }
                for(auto ne : g[u]) {
                    a = ne.first.first;
                    b = ne.first.second;
                    c = ne.second;
                    if(k==1 && c==1) continue;
                    if(dst[a][k|c]==-1) {
                        q.push({-(w+b),{a,k|c}});
                    }
                }
            }
        }
        if(u!=t) printf("-1\n");
    }
    return 0;
}