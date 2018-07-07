#include <bits/stdc++.h>
using namespace std;

int N,u,v;
vector<int>g[100005];
int dp[100005][2];

int mic(int node,int prev,int state) {
    if(dp[node][state]!=-1)
        return dp[node][state];
    if(g[node].size()==1 && g[node][0]==prev) {
        if(state==0) return dp[node][state]=0;
        if(state==1) return dp[node][state]=1;
    }
    int sum = 0, minsum = INT_MAX;
    if(state==1) {
        for(int i=0;i<g[node].size();i++) {
            if(g[node][i]==prev)continue;
            sum += min(mic(g[node][i],node,0), mic(g[node][i],node,1));
        }
        return dp[node][state] = sum+1;
    } else {
        for(int i=0;i<g[node].size();i++) {
            if(g[node][i]==prev)continue;
            sum += mic(g[node][i],node,1);
        }
        return dp[node][state] = sum;
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N-1;i++) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }    
    memset(dp,-1,sizeof dp);
    printf("%d\n",min(mic(1,0,0),mic(1,0,1)));
    return 0;
}
