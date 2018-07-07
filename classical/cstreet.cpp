#include <bits/stdc++.h>
using namespace std;
struct E{
    int u,v,w;
};
int weightSort(E a, E b) {
    return a.w < b.w;
}
int t,p,n,m,u,v,w;
long long sum;
int parent[1005];
vector<E>edge;

int findpar(int x) {
    if(parent[x]==x) return x;
    return parent[x] = findpar(parent[x]);
}
void merge(int x,int y) {
    parent[findpar(y)] = findpar(x);
}
int same(int x,int y) {
    return findpar(x)==findpar(y);
}
int main()
{
    scanf("%d",&t);
    while(t--) {
        edge.clear();
        scanf("%d%d%d",&p,&n,&m);
        for(int i=1;i<=n;i++) {
            parent[i]=i;
        }
        for(int i=0;i<m;i++) {
            scanf("%d%d%d",&u,&v,&w);
            edge.push_back({u,v,w});
        }
        sort(edge.begin(),edge.end(),weightSort);
        sum = 0;
        for(int i=0; i<m; i++) {
            if(same(edge[i].u, edge[i].v)) continue;
            sum += edge[i].w;
            merge(edge[i].u, edge[i].v);
        }
        printf("%lld\n",sum*p);
    }
    return 0;
}