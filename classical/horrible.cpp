#include <bits/stdc++.h>
using namespace std;

long long t;
long long N,C,p,q,v,a;
struct node {
    long long value,lazy;
};

node tree[4000005];

void add(long long n,long long l,long long r) {
    if(tree[n].lazy!=0) {
        tree[n].value+=(r-l+1)*tree[n].lazy;
        if(l!=r) {
            tree[2*n].lazy+=tree[n].lazy;
            tree[2*n+1].lazy+=tree[n].lazy;
        }
        tree[n].lazy=0;
    }
    if(r<p || l>q) {
        return;
    }
    if(l>=p && r<=q) {
        if(l!=r) {
            tree[2*n].lazy+=v;
            tree[2*n+1].lazy+=v;
        }
        tree[n].value+=(r-l+1)*v;
        return;
    }
    long long mid = (l+r) >> 1;
    add(2*n, l, mid);
    add(2*n+1, mid+1, r);
    tree[n].value=tree[2*n].value+tree[2*n+1].value;
}

long long query(long long n,long long l,long long r) {
    if(tree[n].lazy!=0) {
        tree[n].value+=(r-l+1)*tree[n].lazy;
        if(l!=r) {
            tree[2*n].lazy+=tree[n].lazy;
            tree[2*n+1].lazy+=tree[n].lazy;
        }
        tree[n].lazy=0;
    }
    if(r<p || l>q) {
        return 0;
    }
    if(l>=p && r<=q) {
        return tree[n].value;
    }
    long long mid = (l+r) >> 1;
    long long sl,sr;
    sl = query(2*n, l, mid);
    sr = query(2*n+1, mid+1, r);
    return sl+sr;
}
int main()
{
    scanf("%lld",&t);
    while(t--){
        for(long long i=0;i<4000005;i++) {
            tree[i].lazy=tree[i].value=0;
        }
        scanf("%lld%lld",&N,&C);
        while(C--) {
            scanf("%lld",&a);
            if(a==0) {
                scanf("%lld%lld%lld",&p,&q,&v);
                add(1,1,N);
            } else {
                scanf("%lld%lld",&p,&q);
                printf("%lld\n",query(1,1,N));
            }
        }
    }
    return 0;
}
