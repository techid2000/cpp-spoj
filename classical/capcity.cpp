#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,m,u,v,ch;
int cnt;
int scc;
int idx[N];
int lol[N];
int ins[N];
int tag[N];
stack<int>s;
vector<int>g[N];
vector<int>group[N];
vector<int>G[N];
int out[N];
void tarjan(int u) {
    idx[u] = ++cnt;
    lol[u] = cnt;
    s.push(u);
    ins[u] = 1;
    for(auto adj : g[u]) {
        if(!lol[adj]) {
            tarjan(adj);
            lol[u] = min(lol[u],lol[adj]);
        } else if(ins[adj]) {
            lol[u] = min(lol[u],idx[adj]);
        }
    }
    if(lol[u] == idx[u]) {
        ++scc;
        int del;
        do {
            del = s.top();
            // printf("%d ",del);
            group[scc].push_back(del);
            tag[del] = scc;
            ins[del]=0;
            s.pop();
        } while(del != u);
        // printf("\n");
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    while(m--) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++) {
        if(!lol[i]) {
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++) {
        for(auto j:g[i]) {
            if(tag[i]==tag[j])
                continue;
            G[tag[i]].push_back(tag[j]);
            out[tag[i]]++;
        }
    }
    for(int i=1;i<=scc;i++) {
        // printf("Group %d : %d\n",i,out[i]);
        if(out[i]==0) {
            if(!ch)
                ch = i;
            else {
                printf("0\n");
                return 0;
            }
        }
    }
    printf("%d\n",group[ch].size());
    sort(group[ch].begin(),group[ch].end());
    for(int j:group[ch]) {
        printf("%d ",j);
    }
    return 0;
}