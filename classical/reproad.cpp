#include <bits/stdc++.h>
using namespace std;

int t,n,k,i,j,c,maxx;
int a[10005];
int main()
{
    scanf ("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&k);
        for (i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        c = 0, j = 1, maxx=0;
        for(i=1; i<=n; i++) {
            if(i > j) {
                j = i;
            }
            while(j <= n) {
                if(a[j] == 0) {
                    if(c == k)
                        break;
                    c++;
                }
                j++;
            }
            maxx = max(maxx, j-i);
            if(a[i]==0) c--;
        }
        printf("%d\n",maxx);
    }
    return 0;
}
