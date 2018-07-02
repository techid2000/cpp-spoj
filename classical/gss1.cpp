#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,x,y;
int a[50005];

struct N {
    ll msum;
    ll tsum;
    ll psum;
    ll ssum;
};

ll ans,csum;

N tree[300005];
vector <N> buffer;

void construct(int node,int p,int q) {
    if (p==q) {
        tree[node].msum=
        tree[node].psum=
        tree[node].ssum=
        tree[node].tsum=a[p];
        return;
    }
    int mid = (p+q) >> 1;
    construct (2*node,p,mid);
    construct (2*node+1,mid+1,q);
    ll sum = 0;
    tree[node].psum=
    tree[node].ssum=
    tree[node].msum=LLONG_MIN;
    for(int i=p; i<=q; i++) {
        sum += a[i];
        tree[node].psum = max(tree[node].psum, sum);
    }
    for(int i=p; i<=q; i++) {
        tree[node].ssum = max(tree[node].ssum, sum);
        sum -= a[i];
    }
    sum = 0;
    for(int i=p; i<=q; i++) {
        if(sum < 0) {
            sum = a[i];
        } else {
            sum += a[i];
        }
        tree[node].msum = max(tree[node].msum, sum);
        tree[node].tsum += a[i];
    }
}

void fetch(int node,int p,int q) {
    if(q<x || p>y)
        return;
    if(p>=x && q<=y) {
        buffer.push_back(tree[node]);
        return;
    }
    int mid = (p+q)>>1;
    fetch(2*node, p,mid);
    fetch(2*node+1, mid+1,q);
}

int main()
{
    scanf ("%d",&n);
    for(int i=1;i<=n;i++)
        scanf ("%d",&a[i]);
    scanf ("%d",&m);
    construct(1,1,n);
    while(m--) {
        scanf("%d%d",&x,&y);
        buffer.clear();
        fetch(1,1,n);
        ans = LLONG_MIN;
        for(int i=0; i<buffer.size(); i++) {
            csum = 0;
            for(int j=i;j<buffer.size();j++) {
                if(j==i)
                    csum += buffer[j].ssum;
                else
                    csum += buffer[j].psum;
                if(i==j) {
                    ans = max(ans,buffer[i].msum);
                } else {
                    ans = max(ans,csum);
                }
                if(j > i) {
                    csum -= buffer[j].psum;
                    csum += buffer[j].tsum;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
