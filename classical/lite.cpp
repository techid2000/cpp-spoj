#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,z;
int tree[1000005];
int lazy[1000005];
void upd(int node,int l,int r,int a,int b) {
    if(lazy[node] > 0) {
        tree[node] = (r-l+1) - tree[node];
        if(l != r) {
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        lazy[node]=0;
    }
    if(r<a || l>b || l>r) return;
    if(l>=a && r<=b) {
        tree[node] = (r-l+1) - tree[node];
        if(l != r) {
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        return;
    }
    int mid = (l+r) >> 1;
    upd(2*node, l, mid, a, b);
    upd(2*node+1, mid+1, r, a, b);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int que(int node,int l,int r,int a,int b) {
    if(lazy[node] != 0) {
        tree[node] = (r-l+1) - tree[node];
        if(l != r) {
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        lazy[node] = 0;
    }
    if(r<a || l>b || l>r) return 0;
    if(l>=a && r<=b) {
        return tree[node];
    }
    int mid = (l+r) >> 1;
    int ll = que(2*node, l, mid, a, b);
    int rr = que(2*node+1, mid+1, r, a, b);
    tree[node] = tree[2*node] + tree[2*node+1];
    return ll + rr;
}

int main() {
    scanf("%d %d",&n,&m);
    while(m--) {
        scanf("%d %d %d",&x,&y,&z);
        if(x==0) {
            upd(1,1,n,y,z);
        } else {
            printf("%d\n",que(1,1,n,y,z));
        }
    }
}