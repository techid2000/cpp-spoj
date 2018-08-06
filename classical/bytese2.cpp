#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;

int tc;
int maxx;
int n,a,b;
vector<PII>v;
int main() {
    scanf("%d",&tc);
    while(tc--) {
        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d%d",&a,&b);
            v.push_back({a,1});
            v.push_back({b+1,-1});
        }
        sort(v.begin(),v.end());
        maxx = 0;
        for(int i=1;i<2*n;i++) {
            v[i].second+=v[i-1].second;
            if(i==n-1 || v[i+1].first!=v[i].first) {
                maxx = max(maxx,v[i].second);
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}