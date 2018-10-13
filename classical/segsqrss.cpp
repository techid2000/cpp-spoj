#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct NODE {
    LL sq;
    LL s;
    LL la;
    LL lc;
    LL pa;
    LL pc;
    NODE* le, *ri;
};

NODE* tree;

NODE* create() {
    NODE* ret = new NODE;
    ret->la  = ret->lc = 0;
    ret->pa = ret->pc = 0;
    ret->s = ret->sq = 0;
    ret->le = ret->ri = 0;
    return ret;
}
NODE* construct(LL l,LL r) {
    if(l == r) return  create();
    LL mid = (l+r) >> 1;
    NODE* ret = create();
    ret->le = construct(l, mid);
    ret->ri = construct(mid+1, r);
    return ret;
}
LL tc,n,q,k,a,b,x;
LL timer = 0;


void update(NODE* cur,LL l,LL r,LL a,LL b,LL x,LL t) {
    if(cur->la != 0 || cur->lc != 0) {
        if(cur->pa > cur->pc) {
            cur->sq += (r-l+1)*(cur->la)*(cur->la) + cur->s*2*(cur->la);
            cur->s += (r-l+1)*cur->la;
            if(l != r) {
                cur->le->la = cur->ri->la = cur->la;
                cur->le->pa = cur->ri->pa = cur->pa;
            }
        } else {
            cur->sq = (r-l+1)*(cur->lc)*(cur->lc);
            cur->s = (r-l+1)*cur->lc;
            if(l != r) {
                cur->le->lc = cur->ri->lc = cur->lc;
                cur->le->pc = cur->ri->pc = cur->pc;
            }
        }
        cur->la = 0;
        cur->lc = 0;
    }
    if(r < a || l > b || l > r) return;
    if(l >= a && r <= b) {
        if(t == 1) {
            cur->sq += (r-l+1)*x*x + cur->s*2*x;
            cur->s += (r-l+1)*x;
            if(l != r) {
                cur->le->la = x;
                cur->ri->la = x;
                cur->le->pa = timer;
                cur->ri->pa = timer;
            }
        } else {
            cur->sq = (r-l+1)*x*x;
            cur->s = (r-l+1)*x;
            if(l != r) {
                cur->le->lc = x;
                cur->ri->lc = x;
                cur->le->pc = timer;
                cur->ri->pc = timer;
            }
        }
        return;
    }
    LL mid = (l + r) >> 1;
    update(cur->le, l, mid, a, b, x, t);
    update(cur->ri, mid+1, r, a, b, x, t);
    cur->s = cur->le->s + cur->ri->s;
    cur->sq = cur->le->sq + cur->ri->sq;
}

LL query(NODE* cur, LL l,LL r,LL a,LL b) {
    if(cur->la != 0 || cur->lc != 0) {
        if(cur->pa > cur->pc) {
            cur->sq += (r-l+1)*(cur->la)*(cur->la) + cur->s*2*(cur->la);
            cur->s += (r-l+1)*cur->la;
            if(l != r) {
                cur->le->la = cur->ri->la = cur->la;
                cur->le->pa = cur->ri->pa = cur->pa;
            }
        } else {
            cur->sq = (r-l+1)*(cur->lc)*(cur->lc);
            cur->s = (r-l+1)*cur->lc;
            if(l != r) {
                cur->le->lc = cur->ri->lc = cur->lc;
                cur->le->pc = cur->ri->pc = cur->pc;
            }
        }
        cur->la = 0;
        cur->lc = 0;
    }
    if(r < a || l > b || l > r) return 0;
    if(l >= a && r <= b) return cur->sq;
    LL mid = (l + r) >> 1;
    LL sl = query(cur->le, l, mid, a, b);
    LL sr = query(cur->ri,mid+1,r,a,b);
    cur->sq = cur->le->sq+cur->ri->sq;
    cur->s = cur->le->s+cur->ri->s;
    return sl+sr;
}

int main() {
    scanf("%lld",&tc); for(LL _=1;_<=tc;_++) {
        delete tree;
        scanf("%lld%lld",&n,&q);
        tree = construct(1,n);
        for(LL i=1;i<=n;i++) {
            scanf("%lld",&k);
            update(tree,1,n,i,i,k,0);
        }
        printf("Case %lld:\n",_);
        while(q--) {
            scanf("%lld",&k);
            if(k==2) {
                scanf("%lld%lld",&a,&b);
                printf("%lld\n",query(tree,1,n,a,b));
            } else {
                scanf("%lld%lld%lld",&a,&b,&x);
                if(k==1){
                    update(tree,1,n,a,b,x,1);
                } else {
                    update(tree,1,n,a,b,x,0);
                }
            }
        }
    }
}