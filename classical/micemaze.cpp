#include <bits/stdc++.h>
using namespace std;
int N,M,e,T,u,v,w,cnt;
vector <vector<pair<int,int>>> g;
vector <int> dist;
priority_queue <pair<int,int>> q;
int main() {
    scanf("%d",&N);
    scanf("%d",&e);
    scanf("%d",&T);
    scanf("%d",&M);
    g.resize(N+1);
    dist = vector <int> (N+1, INT_MAX);
    while(M--) {
        scanf("%d%d%d",&u,&v,&w);
        g[v].push_back({u,w});
    }
    dist[e] = 0;
    q.push({0, e});
    while(!q.empty()) {
        w = -q.top().first;
        u = q.top().second;
        q.pop();
        for(auto adj : g[u]) {
            if(w + adj.second < dist[adj.first]) {
                dist[adj.first] = w + adj.second;
                q.push({-dist[adj.first], adj.first});
            }
        }
    }
    for(int i=1; i<=N; i++) {
        //printf("Node %d take %d\n",i,dist[i]);
        if(dist[i] <= T) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}