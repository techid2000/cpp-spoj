#include <bits/stdc++.h>
using namespace std;

int n;
long long maxx;
int a[100005];
int l[100005],r[100005];
stack<pair<int,int>>s;
pair<int,int> add;
int main()
{
    while(true) {
        scanf("%d",&n);
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        maxx = 0;
        while(!s.empty())s.pop();
        if(n==0)
            return 0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        for(int i=1;i<=n;i++)
        {
            add = {a[i],0};
            while(!s.empty() && s.top().first>=a[i]){
                add.second+=s.top().second+1;
                s.pop();
            }
            l[i]=add.second;
            s.push(add);
        }
        while(!s.empty())s.pop();
        for(int i=n;i>=1;i--)
        {
            add = {a[i],0};
            while(!s.empty() && s.top().first>=a[i]){
                add.second+=s.top().second+1;
                s.pop();
            }
            r[i]=add.second;
            s.push(add);
        }
        for(int i=1;i<=n;i++)
            maxx = max(maxx, (long long)a[i]*(l[i]+r[i]+1));
        printf("%lld\n",maxx);
    }
    return 0;
}
