#include <bits/stdc++.h>
using namespace std;
struct interval{
    int a,b;
    bool operator <(const interval &o)const{
        return b > o.b;
    }
};
priority_queue<interval>q;
int tc,n,v,w,lw,cnt;
int main()
{
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        while(n--){
            scanf("%d%d",&v,&w);
            q.push({v,w});
        }
        cnt=0,lw=-1;
        while(!q.empty()){
            v=q.top().a, w=q.top().b;
            q.pop();
            if(v<lw){
                continue;
            }
            lw=w;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
