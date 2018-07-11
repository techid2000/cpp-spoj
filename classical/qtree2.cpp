#include <bits/stdc++.h>
using namespace std;

int N,u,v,w,t;

int subsize[10005];
int dist[10005];
int parent[10005];
vector<pair<int,int>> g[10005];

int chain;
int chainNum[10005];
int chainSize[10005];
int chainHead[10005];
int chainIdx[10005];
vector<int>groupChain[10005];

int hNode[10005];
int hChain[10005];
char cmd[10];
void dfs(int node,int prev,int depth,int height) {
    dist[node] = depth;
    hNode[node] = height;
    parent[node] = prev;
    if(g[node].size()==1 && g[node][0].first==prev) {
        subsize[node] = 1;
        return;
    }    
    int sum = 0;
    for(int i=0; i<g[node].size(); i++) {
        if(g[node][i].first != prev) {
            dfs(g[node][i].first, node, depth + g[node][i].second,height+1);
            sum += subsize[g[node][i].first];
        }
    }
    subsize[node] = sum + 1;
}

void hld(int node,int prev,int height) {
    if(chainHead[chain]==0)
        chainHead[chain] = node;
    chainNum[node] = chain;
    chainSize[chain]++;
    chainIdx[node] = chainSize[chain];
    groupChain[chain].push_back(node);
    if(hChain[chain] == 0)
        hChain[chain] = height;
    int maxSubsize = 0, go = 0;
    for(int i=0; i<g[node].size(); i++) {
        if(g[node][i].first != prev) {
            if(subsize[g[node][i].first] > maxSubsize) {
                maxSubsize = subsize[g[node][i].first]; 
                go = g[node][i].first;
            }
        }
    }
    if(go) {
        hld(go, node, height);
    }
    for(int i=0; i<g[node].size(); i++) {
        if(g[node][i].first != prev && g[node][i].first != go) {
            ++chain;
            hld(g[node][i].first, node, height+1);
        }
    }
}

int lca(int nodeA, int nodeB) {
    while(chainNum[nodeA] != chainNum[nodeB]) {
        if(hChain[chainNum[nodeA]] > hChain[chainNum[nodeB]]) //ALift
            nodeA = parent[chainHead[chainNum[nodeA]]];
        else //BLift
            nodeB = parent[chainHead[chainNum[nodeB]]];            
    }
    if(hNode[nodeA] < hNode[nodeB]) return nodeA;
    else return nodeB;
}

int findDist(int nodeA, int nodeB) {
    int LCA = lca(nodeA, nodeB);
    return dist[nodeA] + dist[nodeB] - 2*dist[LCA];
}

int findDist2(int nodeA, int nodeB) {
    int LCA = lca(nodeA, nodeB);
    return hNode[nodeA] + hNode[nodeB] - 2*hNode[LCA];
}

int findKth(int nodeA,int nodeB,int k) {
    int LCA = lca(nodeA, nodeB);
    int halfLeft = hNode[nodeA] - hNode[LCA];
    k--;
    int cnt;
    if(k <= halfLeft) {
        cnt = 0;
        while(cnt < k) {
            if(cnt + chainIdx[nodeA] <= k) {
                cnt += chainIdx[nodeA];
                nodeA = parent[chainHead[chainNum[nodeA]]];
            } else {
                nodeA = groupChain[chainNum[nodeA]][chainIdx[nodeA] - (k - cnt) - 1];
                cnt = k;
            }
        }
        return nodeA;
    } else {
        cnt = findDist2(nodeA,nodeB);
        while(cnt > k) {
            if(cnt - chainIdx[nodeB] >= k) {
                cnt -= chainIdx[nodeB];
                nodeB = parent[chainHead[chainNum[nodeB]]];
            } else {
                nodeB = groupChain[chainNum[nodeB]][chainIdx[nodeB] - (cnt - k) - 1];
                cnt = k;
            }
        }
        return nodeB;
    }
}

void res() {
    for(int i=0; i<10005; i++) {
        subsize[i] = 0;
        dist[i] = 0;
        parent[i] = 0;
        chainNum[i] = 0;
        chainHead[i] = 0;
        chainSize[i] = 0;
        chainIdx[i] = 0;
        hNode[i] = 0;
        hChain[i] = 0;
        g[i].clear();
        groupChain[i].clear();
    }
}

int main()
{
    scanf("%d",&t);
    while(t--) {
        res();
        scanf("%d",&N);
        for(int i=0; i<N-1; i++) {
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        dfs(1,0,0,0);
        chain = 1;
        hld(1,0,0);
        while(true) {
            scanf(" %s",cmd);
            if(!strcmp(cmd,"DONE")) break;
            if(cmd[0] == 'D') {
                scanf("%d %d",&u,&v);
                printf("%d\n",findDist(u,v));
            } else {
                scanf("%d %d %d",&u,&v,&w);
                printf("%d\n",findKth(u,v,w));
            }
        }
    }
    return 0;
}