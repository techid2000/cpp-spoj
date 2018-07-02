#include <bits/stdc++.h>
using namespace std;

int t,n,u,l,r,val,q,idx;
int bit[10005];
void add(int i,int v){
    while(i<10005){
        bit[i]+=v;
        i+=(i&(-i));
    }
}
int ask(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=(i&(-i));
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        memset(bit,0,sizeof bit);
        scanf("%d%d",&n,&u);
        while(u--){
            scanf("%d%d%d",&l,&r,&val);
            l++, r++;
            add(l,val);
            add(r+1,-val);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d",&idx);
            printf("%d\n",ask(idx+1));
        }
    }
    return 0;
}
