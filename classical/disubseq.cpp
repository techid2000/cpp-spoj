#include <bits/stdc++.h>
using namespace std;
const int modulo = 1000000007;
int n,len;
int lastPos[26];
long long dp[100005];
char str[100005];

int main()
{
    scanf("%d",&n);
    while(n--) {
        scanf(" %s",str+1);
        len = strlen(str+1);
        memset(dp,0,sizeof dp);
        memset(lastPos,0,sizeof lastPos);
        dp[0] = 1;
        for(int i=1; i<=len; i++) {
            dp[i] = dp[i-1]*2;
            if(lastPos[str[i]-'A'] > 0) {
                dp[i] -= dp[lastPos[str[i]-'A']-1];
            }
            dp[i] %= modulo;
            while(dp[i] < 0)
                dp[i] += modulo;
            lastPos[str[i]-'A'] = i;
        }
        printf("%lld\n",dp[len]);
    }
    return 0;
}