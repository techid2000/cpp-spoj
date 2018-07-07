#include <bits/stdc++.h>
using namespace std;

int N,t;
int a[100005][5];
long long dp[100005][5];

int main() {
	while(true) {
		scanf( "%d" , &N);
        if(N == 0) break;
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		for(int i=1; i<=N; i++) {
			scanf("%d%d%d",a[i]+1, a[i]+2, a[i]+3);
		}
		dp[1][1] = LLONG_MAX;
		dp[1][2] = a[1][2];
        dp[1][3] = a[1][2] + a[1][3];
		for(int i=2; i<=N; i++) {
			dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + a[i][1];
			
			dp[i][2] = min(dp[i][1], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3]))) + a[i][2];

			dp[i][3] = min(dp[i][2], min(dp[i-1][2], dp[i-1][3])) + a[i][3];
		}
		printf("%d. %lld\n",++t, dp[N][2]);
	}
	return 0;
}