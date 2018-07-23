#include <bits/stdc++.h>
using namespace std;

int a[1005];

int ff(int x) {
    int y=0;
    while(x){
        y+=(x%10)*(x%10);
        x/=10;
    }
    return y;
}

void f(int x) {
    if(a[x]!=-1)
        return;
    a[x]=-2;
    int y=ff(x);
    f(y);
    if(a[y]>=0) a[x]=a[y]+1;
    else a[x]=a[y];
}


int main() {
    memset(a,-1,sizeof a);
    a[1]=0;
    for(int i=2;i<=1000;i++) {
        f(i);
    }
    scanf("%d",&a[0]);
    a[0] = ff(a[0]);
    printf("%d\n",a[a[0]]==-2?-1:a[a[0]]+1);
    return 0;
}