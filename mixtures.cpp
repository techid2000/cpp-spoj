#include <bits/stdc++.h>
using namespace std;

long long dp[200][200];
long long n,a[200],qs[200];

int main()
{
    while(scanf("%lld",&n)!=EOF) {
        memset(qs,0,sizeof qs);
        for(long long i=1;i<=n;i++) {
            scanf("%lld",a+i);
            qs[i]=qs[i-1]+a[i];
        }
        memset(dp,0,sizeof dp);
        for(long long k=2;k<=n;k++){
            for(long long i=1;i<=n-k+1;i++){
                long long j=i+k-1;
                dp[i][j]=LLONG_MAX;
                for(long long p=i;p<=j-1;p++){
                    long long l,r;
                    l=qs[p]-qs[i-1],r=qs[j]-qs[p];
                    l%=100, r%=100;
                    long long x = l*r;
//                    if(k==2){
//                        printf(":%lld,%lld + %lld,%lld\n",i,p,p+1,j);
//                        printf("\t%lld - %lld = %lld\n",l,r,x);
//                        printf("\t%lld - %lld\n",dp[i][p],dp[p+1][j]);
//                    }
                    dp[i][j]=min(dp[i][j],(dp[i][p]+dp[p+1][j])+x);
                }
            }
        }
        printf("%lld\n",dp[1][n]);
    }
    return 0;
}
