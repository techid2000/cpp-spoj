#include <bits/stdc++.h>
using namespace std;

int T;
int n,m,u,fail,top,v;
vector<int>g[2005];
int ch[2005];
queue<int>q;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(ch,-1,sizeof ch);
        printf("Scenario #%d:\n",t);
        fail=0;
        for(int i=1;i<=n;i++){
            if(ch[i]==-1){
                ch[i]=0;
                q.push(i);
                while(!q.empty()){
                    top=q.front();
                    q.pop();
                    for(int j=0;j<g[top].size();j++){
                        if(ch[g[top][j]]==-1){
                            ch[g[top][j]]=!ch[top];
                            q.push(g[top][j]);
                        } else if(ch[g[top][j]]==ch[top]){
                            printf("Suspicious bugs found!\n");
                            fail=1;
                            break;
                        }
                    }
                    if(fail) break;
                }
                if(fail) break;
            }
        }
        if(!fail){
            printf("No suspicious bugs found!\n");
        }
        while(!q.empty())q.pop();
    }
    return 0;
}
