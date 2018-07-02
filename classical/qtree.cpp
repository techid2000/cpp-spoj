#include <bits/stdc++.h>
using namespace std;

int N,u,v,w,tc;
char cmd[20];
int parent[10005];
int upper_weight[10005];
int subsize[10005];
vector<pair<int,int>>tree[10005];
vector<pair<pair<int,int>,int>>edge;

int chain_no;
int chain_node[10005];
int chain_pos[10005];
int chain_size[10005];
int chain_head[10005];
int chain_height[10005];
vector<int>chain_tree[10005];
vector<vector<int>>segment_tree;

void dfs(int cur, int prev) {
    int sum = 0;
    upper_weight[cur] = tree[cur][prev].second;
    parent[cur] = prev;
    for(int i=0; i<tree[cur].size(); i++) {
        if(tree[cur][i].first!=prev) {
            dfs(tree[cur][i].first, cur);
            sum += subsize[tree[cur][i].first];
        }
    }
    subsize[cur]=sum+1;
    return;
}
void hld(int cur,int prev) {
    if(!prev)
        segment_tree.push_back(vector<int>());
    if(chain_head[chain_no] == 0)
        chain_head[chain_no] = cur;
    chain_node[cur] = chain_no;
    chain_size[chain_no]++;
    chain_pos[cur] = chain_size[chain_no];
    int max_subsize = -1, go_node = -1;
    for(int i=0; i<tree[cur].size(); i++) {
        if(tree[cur][i].first==prev)
            continue;
        if(subsize[tree[cur][i].first] > max_subsize) {
            max_subsize = subsize[tree[cur][i].first];
            go_node = tree[cur][i].first;
        }
    }
    if(go_node!=-1)
        hld(go_node, cur);
    for(int i=0; i<tree[cur].size(); i++) {
        if(tree[cur][i].first==prev)
            continue;
        if(tree[cur][i].first != go_node) {
            chain_tree[chain_no].push_back(chain_no+1);
            segment_tree.push_back(vector<int>(5*chain_size[chain_no]));
            chain_no++;
            hld(tree[cur][i].first, cur);
        }
    }
    if(!prev){
        segment_tree.push_back(vector<int>(5*chain_size[chain_no]));
    }
}
void dfs2(int cur,int prev,int hei) {
    chain_height[cur]=hei;
    for(int i=0; i<chain_tree[cur].size(); i++) {
        if(chain_tree[cur][i]!=prev) {
            dfs2(chain_tree[cur][i],cur,hei+1);
        }
    }
}
void update_smt(int node,int p,int q,int layer,int ind, int key){
    if(q<ind || p>ind)
        return;
    if(p==q){
        segment_tree[layer][node]=key;
        return;
    }
    int mid = (p+q) >> 1;
    update_smt(2*node,p, mid, layer, ind, key);
    update_smt(2*node+1,mid+1, q, layer, ind, key);
    segment_tree[layer][node] = max(segment_tree[layer][2*node],segment_tree[layer][2*node+1]);
}
int query_smt(int node,int p,int q,int layer,int a,int b) {
    if(q<a || p>b)
        return INT_MIN;
    if(p>=a && q<=b)
        return segment_tree[layer][node];
    int mid = (p+q) >> 1,max_l,max_r;
    max_l = query_smt(2*node,p, mid, layer, a, b);
    max_r = query_smt(2*node+1,mid+1, q, layer, a, b);
    return max(max_l, max_r);
}
void update_edge(int ind, int wei) {
    int u = edge[ind].first.first,v = edge[ind].first.second;
    if(parent[u] == v) swap(u,v);
    upper_weight[v] = wei;
    update_smt(1,1,chain_size[chain_node[v]],chain_node[v],chain_pos[v],wei);
}
int query_path(int node_a, int node_b) {
    int maxx = INT_MIN;
    while(chain_node[node_a] != chain_node[node_b]) {
        if(chain_height[chain_node[node_a]] > chain_height[chain_node[node_b]]) {
            maxx = max(maxx,query_smt(1,1,chain_size[chain_node[node_a]],chain_node[node_a],1,chain_pos[node_a]));
            node_a = parent[chain_head[chain_node[node_a]]];
        } else {
            maxx = max(maxx,query_smt(1,1,chain_size[chain_node[node_b]],chain_node[node_b],1,chain_pos[node_b]));
            //printf("test %d\n",maxx);
            node_b = parent[chain_head[chain_node[node_b]]];
        }
    }
    if(chain_pos[node_a] > chain_pos[node_b])
        swap(node_a, node_b);
//    printf("-%d %d : %d\n",node_a,node_b,maxx);
    maxx = max(maxx, query_smt(1,1,chain_size[chain_node[node_a]],chain_node[node_a],
                               chain_pos[node_a]+1, chain_pos[node_b]));
    if(maxx == INT_MIN)
        return 0;
    return maxx;
}
void clear_data() {
    for(int i=0;i<10005;i++) {
        parent[i]=
        subsize[i]=
        upper_weight[i]=
        chain_node[i]=
        chain_pos[i]=
        chain_size[i]=
        chain_head[i]=
        chain_height[i]=0;
        tree[i].clear();
        chain_tree[i].clear();
    }
    edge.clear();
    segment_tree.clear();
}
int main()
{
    scanf("%d",&tc);
    while(tc--) {
        clear_data();
        scanf("%d",&N);
        edge.resize(N+1);
        for(int i=1; i<=N-1; i++) {
            scanf("%d%d%d",&u,&v,&w);
            edge[i] = {{u,v},w};
            tree[u].push_back({v,w});
            tree[v].push_back({u,w});
        }
        dfs(1,0);
        chain_no=1;
        hld(1,0);
        dfs2(1,0,0);
        for(int i=1;i<=N-1;i++) {
            update_edge(i,edge[i].second);
        }
        while(true) {
            scanf(" %s",&cmd);
            if(cmd[0]=='D') break;
            scanf("%d%d",&u,&v);
            if(cmd[0]=='Q') {
                printf("%d\n",query_path(u,v));
            } else if(cmd[0]=='C'){
                update_edge(u,v);
            }
        }
    }
    return 0;
}
