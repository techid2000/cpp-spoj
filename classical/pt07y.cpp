#include <bits/stdc++.h>
using namespace std;

int n,m,u,v;
vector<int>g[10005];
int ch[10005];
int cnt;
queue<int>q;

int main()
{
    scanf("%d%d",&n,&m);
    if(m!=n-1) {
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<m;i++) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ch[1]=1,cnt=1;
    q.push(1);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(auto x:g[t]) {
            if(!ch[x]){
                ch[x]=1;
                cnt++;
                q.push(x);
            }
        }
    }
    if(cnt==n){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
