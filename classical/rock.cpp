#include <bits/stdc++.h>
using namespace std;
int n,tc;
char str[205];
int sour[205];
int sweet[205];
int dp[205];
int main() {
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        scanf(" %s",str+1);
        memset(dp,0,sizeof(dp));
        memset(sweet,0,sizeof(sweet));
        memset(sour,0,sizeof(sour));
        for(int i=1;i<=n;i++) {
            if(str[i]=='0') sour[i]=1;
            else sweet[i]=1;
            sour[i]+=sour[i-1];
            sweet[i]+=sweet[i-1];
        }
        for(int i=1;i<=n;i++) {
            dp[i]=dp[i-1];
            for(int k=1; k<=i; k++) {
                if(sweet[i]-sweet[k-1] > sour[i]-sour[k-1]) {
                     dp[i]=max(dp[i], dp[k-1] + i-k+1);
                }
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}