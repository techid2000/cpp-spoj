#include <bits/stdc++.h>
using namespace std;

int n,k,a[1000005];
deque<pair<int,int>>q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%d",&k);
    for(int i=1;i<=n;i++){
        while(!q.empty()&&q.front().second<=i-k)q.pop_front();
        while(!q.empty()&&a[i]>q.back().first)q.pop_back();
        q.push_back(make_pair(a[i],i));
        if(i>=k){
            printf("%d ",q.front().first);
        }
    }
    return 0;
}
