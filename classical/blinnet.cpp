#include <bits/stdc++.h>
using namespace std;
int n,m,v,w;
long long sum;
int tc;
int mark[10005];
char waste[15];
vector<pair<int,int>>g[10005];
priority_queue<pair<int,int>>q;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        sum = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n;i++) {
            scanf(" %s",waste);
            scanf("%d",&m);
            for(int j=0;j<m;j++) {
                scanf("%d%d",&v,&w);
                g[i].push_back({v,w});
            }
        }
        memset(mark,0,sizeof mark);
        q.push({0,1});
        while(!q.empty()) {
            v=q.top().second;
            w=-q.top().first;
            q.pop();
            if(!mark[v]) {
                mark[v]=1;
                sum += w;
                for(auto adj:g[v]){
                    q.push({-adj.second,adj.first});
                }
            }
        }
        printf("%lld\n",sum);
    }
}