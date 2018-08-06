#include <bits/stdc++.h>
using namespace std;

long long dp[1000006],k;

int main()
{
    dp[1] = 1;
    for(long long i=2; i<=1000000; i++) {
        if(i%2 == 1) k = (i/2)*(i/2 + 1);
        else k = (i/2)*(i/2);
        dp[i] = dp[i-1] + i*(i+1)/2 + k;
    }
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}