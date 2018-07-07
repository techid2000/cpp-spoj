#include <bits/stdc++.h>
#define of 200000
#define N 200000
using namespace std;

int tree[10*N],cnt;

void upd(int node,int a,int b,int ind,int key) {
    if(b < ind || a > ind)
        return;
    if(a == b) {
        tree[node] = key;
        return;
    }
    int mid = (a + b) >> 1;
    upd(2 * node, a , mid, ind, key);
    upd(2 * node+1, mid+1, b, ind, key);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

int que(int node,int a,int b,int p,int q) {
    if(a > q || b < p || p > q) return INT_MIN;
    if(a >= p && b <= q)
        return tree[node];
    int mid = (a+b) >> 1;
    int mal, mar;

    mal = que(2*node, a, mid, p, q);
    mar = que(2*node+1, mid+1, b, p, q);

    return max(mal, mar);
}

int a[N], ml[2*N], mr[2*N],m1,m2,m3;
int n,q,x,y;

void res() {
    memset(a,0,sizeof a);
    memset(ml,0,sizeof ml);
    memset(mr,0,sizeof mr);
    memset(tree,0,sizeof tree);
    m1=m2=m3=n=x=y=cnt=0;
}

int main()
{
    while(true){
        res();
        scanf("%d",&n);
        if(n==0) return 0;
        scanf("%d",&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",a + i);
            if(a[i] != a[i-1]) {
                upd(1,0,2*N,a[i-1] + of,cnt);
                cnt = 0;
                ml[a[i]+of]=i;
                mr[a[i-1]+of]=i-1;
            }
            cnt++;
        }
        while(q--) {
            scanf("%d%d",&x,&y);
            if(a[x]==a[y]) {
                printf("%d\n",y-x+1);
            } else {
                m1 = que(1,0,2*N,a[mr[a[x]+of]+1]+of, a[ml[a[y]+of]-1]+of);
                m2 = mr[a[x]+of] - x + 1;
                m3 = y - ml[a[y]+of] + 1;
                printf("%d\n",max(m1,max(m2,m3)));
            }
        }
    }
    return 0;
}
