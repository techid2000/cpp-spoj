#include <bits/stdc++.h>
using namespace std;

int n,m,s,cnt;

int main()
{
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        s=5,cnt=0;
        while(m/s > 0){
            cnt+=(m/s);
            s*=5;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

