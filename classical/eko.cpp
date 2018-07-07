//I am in luv this style of Bsearch
#include <bits/stdc++.h>
using namespace std;

long long n,m,lo,hi,mid,sum,ans;
long long a[1000005];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++) {
        scanf("%lld",a+i);
    }
    lo=0, hi=LLONG_MAX;
    while(lo <= hi) {
        mid =(lo+hi)>>1;
        sum = 0;
        for(long long i=1;i<=n;i++) {
            if(a[i] - mid > 0)
                sum += a[i] - mid;
        }
        if(sum == m) ans = mid, lo=mid+1;
        if(sum < m) hi = mid-1;
        if(sum > m) ans = mid, lo=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}
