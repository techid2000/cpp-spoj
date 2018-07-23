#include <bits/stdc++.h>
using namespace std;

long long poss[65][10];
int T,n,t;
long long m;
int main()
{
    for(int i=0;i<=9;i++)
        poss[1][i] = 1;
    for(int i=1;i<=64;i++)
        for(int j=0;j<=9;j++) 
            for(int k=0;k<=j;k++)
                poss[i][j] += poss[i-1][k];
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&t,&n);
        m = 0;
        for(int i=0; i<=9; i++) m+=poss[n][i];
        printf("%d %lld\n",t,m);
    }
    return 0;
}