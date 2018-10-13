#include <bits/stdc++.h>
using namespace std;
int f,s,g,u,d,t;
int mark[1000005];
queue<int>q;
int main() {
    scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
    memset(mark,-1,sizeof mark);
    mark[s]=0;
    q.push(s);
    while(!q.empty()) {
        t=q.front();
        q.pop();
        if(t==g){
            printf("%d\n",mark[t]);
            exit(0);
        }
        if(t+u<=f&&mark[t+u]==-1){
            mark[t+u]=mark[t]+1;
            q.push(t+u);
        }
        if(t-d>=1&&mark[t-d]==-1){
            mark[t-d]=mark[t]+1;
            q.push(t-d);
        }
    }
    printf("use the stairs");
    return 0;
}