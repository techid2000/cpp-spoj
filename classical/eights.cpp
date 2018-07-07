#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long key[] = {192, 442, 692, 942};
    long long n,k;
    scanf("%lld",&n);
    while(n--) {
        scanf("%lld",&k);
        if((k-1)/4 > 0) printf("%lld",(k-1)/4);
        printf("%lld\n",key[(k-1)%4]);
    }
    return 0;
}