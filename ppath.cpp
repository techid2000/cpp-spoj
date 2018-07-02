#include <bits/stdc++.h>
using namespace std;

vector<int>prime;
vector<int>graph[10005];
int chh[10005];
queue<pair<int,int>>que;

int main()
{
    for(int i=1000,ch;i<=9999;i++){
        ch=1;
        for(int j=2;j<=sqrt(i);j++){
            if((i%j)==0) {
                ch=0;
                break;
            }
        }
        if(ch)
        prime.push_back(i);
    }
    for(int i=0,a,b,c,d,e,f,g,h; i<prime.size();i++) {
        for(int j=i+1,k=0;j<prime.size();j++,k=0){
            a=prime[i]/1000;
            b=(prime[i]%1000)/100;
            c=((prime[i]%1000)%100)/10;
            d=((prime[i]%1000)%100)%10;

            e=prime[j]/1000;
            f=(prime[j]%1000)/100;
            g=((prime[j]%1000)%100)/10;
            h=((prime[j]%1000)%100)%10;

            if(a!=e) k++;
            if(b!=f) k++;
            if(c!=g) k++;
            if(d!=h) k++;
            if(k!=1) continue;
            graph[prime[i]].push_back(prime[j]);
            graph[prime[j]].push_back(prime[i]);
        }
    }
    int T,p,q,v1,v2,ch;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&p,&q);
        memset(chh,0,sizeof chh);
        while(!que.empty())que.pop();
        que.push(make_pair(p,0));
        ch=1,chh[p]=1;
        while(!que.empty()){
            v1=que.front().first;
            v2=que.front().second;
            que.pop();
            if(v1==q){
                printf("%d\n",v2);
                ch=0;
                break;
            }
            for(auto x:graph[v1]){
                if(!chh[x]){
                    chh[x]=1;
                    que.push(make_pair(x,v2+1));
                }
            }
        }
        if(ch){
            printf("Impossible\n");
        }
    }
    return 0;
}
