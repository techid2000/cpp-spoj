#include <bits/stdc++.h>
using namespace std;

int tc,n,m,u,v,cnt;
vector<vector<int>>g;
vector<bool>p;
queue<int>q;

int main() {
    cin>>tc;
    while(tc--) {
        cin>>n>>m;
        g.resize(n);
        p.resize(n);
        cnt=0;
        for(int i=0;i<n;i++) {
            g[i].clear();
            p[i]=false;
        }
        for(int i=0;i<m;i++) {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=0;i<n;i++) {
            if(!p[i]) {
                q.push(i);
                p[i]=true;
                while(!q.empty()) {
                    u=q.front();
                    q.pop();
                    for(auto adj:g[u]){
                        if(!p[adj]) {
                            p[adj]=true;
                            q.push(adj);
                        }
                    }
                }
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}