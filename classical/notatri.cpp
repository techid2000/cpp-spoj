#include <bits/stdc++.h>
using namespace std;

int n,lo,hi,mid,ans,sum;
int a[2005];

int main() {
    while(true) {
        sum = 0;
        scanf("%d",&n);
        if(n==0) return 0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        sort(a+1, a+n+1);
        for(int i=1;i<=n-2;i++) {
            for(int j=i+1;j<=n-1;j++) {
                lo=j+1, hi=n;
                ans = -1;
                while(lo<=hi) {
                    mid=(lo+hi)>>1;
                    if(a[mid] > a[i]+a[j]) {
                        ans = mid;
                        hi = mid-1;
                    }
                    if(a[mid] <= a[i]+a[j]) {
                        lo = mid+1;
                    }
                }
                if(ans != -1)
                sum += (n-ans+1);
            }
        }
        printf("%d\n",sum);
    }
}