#include <bits/stdc++.h>
using namespace std;

long long x;
int n,cnt;

void exe() {
    cnt = 0;
    for(long long i=2; i*i<=x; i++) {
        cnt = 0;
        while(x % i == 0) {
            x /= i;
            cnt++;
        }
        if(i%4==3 && cnt%2==1) {
            printf("No\n");
            return;
        }
    }
    if(x%4==3) printf("No\n");
    else printf("Yes\n");
}

int main()
{
    scanf("%d",&n);
    while(n--) {
        scanf("%lld",&x);
        exe();
    }
    return 0;
}