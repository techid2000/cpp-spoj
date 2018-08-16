#include <bits/stdc++.h>
using namespace std;
int k=2,l,cnt,t;
vector<int>ans;
int main() {
    while(ans.size()<1000) {
        l=k;
        cnt=0;
        for(int i=2;i<=sqrt(k);i++) {
            if(l%i==0)
                cnt++;
            while(l%i==0) 
                l/=i;
        }
        if(l>1) cnt++;
        if(cnt>=3) 
            ans.push_back(k);
        k++;
    }
    scanf("%d",&k);
    while(k--) {
        scanf("%d",&l);
        printf("%d\n",ans[l-1]);
    }
    return 0;
}