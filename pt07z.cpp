#include <bits/stdc++.h>
using namespace std;

int N,u,v,maxx;
vector<int>g[10005];

int deep[10005];

void d(int node,int par) {
    if(g[node].size()==1 && g[node][0]==par) {
        return;
    }
    int max1 = -1, max2 = -1;
    for(auto x : g[node]) {
        if(x==par)continue;
        d(x,node);
        if(deep[x] > max1) {
            max2 = max1;
            max1 = deep[x];
        } else if(deep[x] > max2) {
            max2 = deep[x];
        }
    }
    maxx = max(maxx, max1 + 1);
    if(max2 >= 0) maxx = max(maxx, max1 + max2 + 2);
    deep[node] = max1 + 1;
    return;
}


int main() {
    scanf("%d",&N);
    for(int i=0;i<N-1;i++) {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d(1,0);
    printf("%d\n",maxx);
}
