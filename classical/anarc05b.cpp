//Challenge

#include <bits/stdc++.h>
#define offset 10000
using namespace std;

int n,m;
int a[10005],b[10005];
int ina[20005],inb[20005];
int dp[10005][2], overlap[10005][2];

int f(int i,int j) {
    if(i<1) return 0;
    if(overlap[i][j]) {
        return dp[i][j];
    }
    int maxx = INT_MIN;
    if(j==0) {
        maxx = max(maxx, f(i-1,0));
        if(inb[a[i] + offset] > 0) {
            maxx = max(maxx, f(inb[a[i] + offset] - 1, 1));
        }
        overlap[i][j] = 1;
        return dp[i][j] = maxx + a[i];
    }
    else {
        maxx = max(maxx, f(i-1,1));
        if(ina[b[i] + offset] > 0) {
            maxx = max(maxx, f(ina[b[i] + offset] - 1, 0));
        }
        overlap[i][j]=1;
        return dp[i][j] = maxx + b[i];
    }
}


int main() {
    while(true) {
        scanf("%d",&n);
        if(n==0) return 0;
        memset(ina,0,sizeof ina);
        memset(inb,0,sizeof inb);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            ina[a[i]+offset]=i;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            scanf("%d",&b[i]);
            inb[b[i]+offset]=i;
        }
        memset(overlap,0,sizeof overlap);
        printf("%d\n",max(f(n,0),f(m,1)));
    }
}
