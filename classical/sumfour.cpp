#include <bits/stdc++.h>
using namespace std;
int n,A,B,C,D,lo,hi,mid,p,q,ans;
vector<int>a,b,c,d,ab,cd;
vector<pair<int,int>>oab,ocd;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d%d%d%d",&A,&B,&C,&D);
        a.push_back(A);
        b.push_back(B);
        c.push_back(C);
        d.push_back(D);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ab.push_back(a[i]+b[j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cd.push_back(c[i]+d[j]);
        }
    }
    sort(ab.begin(),ab.end());
    sort(cd.begin(),cd.end());
    for(int i=0;i<n*n;i++) {
        if(i==0 || ab[i]!=ab[i-1]) {
            oab.push_back({ab[i],1});
        } else {
            oab.back().second++;
        }
    }
    for(int i=0;i<n*n;i++) {
        if(i==0 || cd[i]!=cd[i-1]) {
            ocd.push_back({cd[i],1});
        } else {
            ocd.back().second++;
        }
    }
    for(int i=0;i<oab.size();i++) {
        lo=0,hi=(int)ocd.size()-1;
        while(lo<=hi) {
            mid=(lo+hi)/2;
            if(ocd[mid].first > -oab[i].first)
                hi = mid-1;
            if(ocd[mid].first < -oab[i].first) 
                lo = mid+1;
            if(ocd[mid].first == -oab[i].first) {
                ans += oab[i].second*ocd[mid].second;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}