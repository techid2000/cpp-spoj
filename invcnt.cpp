#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;

int bit[N];
int t,n,a,i,b;
long long c,d;
int main()
{
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        c = 0;
        for (i=0; i<n; i++){
            scanf("%d",&a);
            b = a - 1, d = 0;
            while(b > 0) {
                d -= bit[b];
                b -= (b & (-b));
            }
            b = N-1;
            while(b > 0) {
                d += bit[b];
                b -= (b & (-b));
            }
            c += d;
            while(a < N) {
                bit[a]++;
                a += (a & (-a));
            }
        }
        printf("  %lld\n",c);
        memset(bit,0,sizeof(bit));
    }
    return 0;
}
