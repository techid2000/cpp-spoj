#include <bits/stdc++.h>
using namespace std;
long long n,i,j;
long long a[300005],sum,maxx,m;
int main() {
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(i=1;i<=n;i++){
        if(i>j){
            j=i;
            sum=a[i];
        }
        if(sum<=m){
            maxx=max(maxx,sum);
        }
        while(j+1<=n&&sum+a[j+1]<=m){
            j++;
            sum+=a[j];
            maxx=max(maxx,sum);
        }
        sum-=a[i];
    }
    printf("%lld\n",maxx);
    return 0;
}
