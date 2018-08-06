#include <bits/stdc++.h>
#define ALL(n) n.begin(),n.end()
using namespace std;
int N,M,u,v,w,s,d;
int dst[505],ban[505][505];
vector<vector<int>>from;
vector<vector<pair<int,int>>>g;
priority_queue<pair<int,pair<int,int>>>q;

void track(int x) {
    if(x==s) return;
    for(auto y : from[x]) {
        // printf("banned %d -> %d\n",y,x);
        ban[y][x] = 1;
        ban[x][y] = 1;
        track(y);
    }
}

int main()
{
    while(true) {
        cin >> N >> M;
        if(N + M == 0) return 0;
        g.resize(N);
        from.resize(N);
        for(int i=0; i<N; i++) {
            g[i].clear();
            from[i].clear();
        }
        memset(dst,-1,sizeof dst);
        memset(ban,0,sizeof ban);
        cin >> s >> d;
        for(int i=0; i<M; i++) {
            cin >> u >> v >> w;
            g[u].push_back({v,w});
        }
        q.push({0, {s, 0}});
        while(!q.empty()) {
            u = q.top().second.first;
            v = q.top().second.second;
            w = -q.top().first;
            q.pop();
            if(dst[u] == -1) {
                dst[u] = w;
                from[u].push_back(v);
                for(auto adj : g[u]) {
                    if(dst[adj.first]==-1) {
                        q.push({-(w + adj.second),{adj.first,u}});
                    }
                }
            }
            else if(w == dst[u]) {
                from[u].push_back(v);
            }
        }
        track(d);
        memset(dst,-1,sizeof dst);
        q.push({0, {s,0}});
        while(!q.empty()) {
            u = q.top().second.first;
            w = -q.top().first;
            q.pop();
            if(dst[u] == -1) {
                dst[u] = w;
                if(u == d) {
                    cout << w << "\n";
                    while(!q.empty())
                        q.pop();
                    break;
                }
                for(auto adj : g[u]) {
                    if(dst[adj.first] == -1 && !ban[u][adj.first]) {
                        q.push({-(w + adj.second),{adj.first,0}});
                    }
                }
            }
        }
        if(u != d) cout << "-1\n";
    }
    return 0;
}