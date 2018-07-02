#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<int>sorted;
};

int a[100005],n,m,k,x,y,p,q,mid,sumlower,sumhigher,minn,maxx;
node tree[3000005];
vector<int>usingnode;

void construct(int no,int p,int q) {
    if(p==q) {
        tree[no].sorted.push_back(a[p]);
        return;
    }
    int mid = (p+q)>>1,i=0,j=0;
    construct(2*no,p,mid);
    construct(2*no+1,mid+1,q);
    while(i<tree[2*no].sorted.size() &&
          j<tree[2*no+1].sorted.size()) {
        if(tree[2*no].sorted[i]<tree[2*no+1].sorted[j]) {
            tree[no].sorted.push_back(tree[2*no].sorted[i++]);
        } else {
            tree[no].sorted.push_back(tree[2*no+1].sorted[j++]);
        }
    }
    while(i<tree[2*no].sorted.size()) tree[no].sorted.push_back(tree[2*no].sorted[i++]);
    while(j<tree[2*no+1].sorted.size())  tree[no].sorted.push_back(tree[2*no+1].sorted[j++]);
}

void getnode(int no,int p,int q) {
    if(q<x || p>y) return;
    if(p>=x && q<=y) {
        usingnode.push_back(no);
        return;
    }
    int mid=(p+q)>>1;
    getnode(2*no,p,mid);getnode(2*no+1,mid+1,q);
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    construct(1,1,n);
    while(m--){
        usingnode.clear();
        scanf("%d%d%d",&x,&y,&k);
        getnode(1,1,n);
        p=-1e9, q=1e9,minn=1e9,maxx=-1e9;
        for(int i=0;i<usingnode.size();i++){
            minn=min(minn,tree[usingnode[i]].sorted.front());
            maxx=max(maxx,tree[usingnode[i]].sorted.back());
        }
        while(p<q){
            mid=(p+q)>>1,sumlower=sumhigher=0;
            for(int i=0;i<usingnode.size();i++){
                sumlower += lower_bound(tree[usingnode[i]].sorted.begin(),tree[usingnode[i]].sorted.end(),mid)
                -tree[usingnode[i]].sorted.begin();

                sumhigher += upper_bound(tree[usingnode[i]].sorted.begin(),tree[usingnode[i]].sorted.end(),mid)
                -tree[usingnode[i]].sorted.begin();
            }
            /*
            Pattern
            ....CCXXXX
            XXXXCC....
            */
            if(sumlower>k-1) q=mid-1;
            else if(sumhigher<k) p=mid+1;
            else {
                break;
            }
        }
        mid=(p+q)>>1;
        printf("%d\n",mid);
    }
    return 0;
}
