/*
#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<int>sorted;
};

int n,m,a[30005],x,y,k,su;
node tree[100000];
vector<int>used;

void construct(int no,int p,int q) {
    if(p==q){
        tree[no].sorted.push_back(a[p]);
        return;
    }
    int mid = (p+q)>>1,i=0,j=0;
    construct(2*no,p,mid);
    construct(2*no+1,mid+1,q);
    while(i<tree[2*no].sorted.size() && j<tree[2*no+1].sorted.size()) {
        if(tree[2*no].sorted[i] < tree[2*no+1].sorted[j]) {
            tree[no].sorted.push_back(tree[2*no].sorted[i++]);
        } else {
            tree[no].sorted.push_back(tree[2*no+1].sorted[j++]);
        }
    }
    while(i<tree[2*no].sorted.size())
        tree[no].sorted.push_back(tree[2*no].sorted[i++]);
    while(j<tree[2*no+1].sorted.size())
        tree[no].sorted.push_back(tree[2*no+1].sorted[j++]);
}

void ask(int no,int p,int q) {
    if(q<x||p>y) return;
    if(p>=x && q<=y){
        used.push_back(no);
        return;
    }
    int mid=(p+q)>>1;
    ask(2*no,p,mid);
    ask(2*no+1,mid+1,q);
}

void process() {
    used.clear();
    ask(1,1,n);
    su=0;
    for(int i=0;i<used.size();i++){
        su+=tree[used[i]].sorted.size()-(upper_bound(tree[used[i]].sorted.begin(),tree[used[i]].sorted.end(),k)
        -tree[used[i]].sorted.begin());
    }
    printf("%d\n",su);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    construct(1,1,n);
    scanf("%d",&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&k);
        process();
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,k,p,a[30005],bit[30005];
vector<pair<int,int>>aa;
struct query {
    int i,j,k,order,answer;
};
vector<query>q;
int sort1(query a,query b) {
    return a.k > b.k;
}
int sort2(query a,query b) {
    return a.order < b.order;
}
void add(int v,int x){
    while(x<30005){
        bit[x]+=v;
        x+=(x&(-x));
    }
}
int ask(int x){
    int s=0;
    while(x>0){
        s+=bit[x];
        x-=(x&(-x));
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        aa.push_back({a[i],i});
    }
    sort(aa.begin(),aa.end(),greater<pair<int,int>>());
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&k);
        q.push_back({x,y,k,i});
    }
    sort(q.begin(),q.end(),sort1);
    for(int i=0;i<m;i++){
//        printf("Query %d : %d <%d,%d>\n",i,q[i].k,q[i].i,q[i].j);
        while(p<n && aa[p].first>q[i].k){
//            printf("Added %d (%d)\n",aa[p].first,aa[p].second);
            add(1,aa[p].second);
            p++;
        }
        q[i].answer=ask(q[i].j)-ask(q[i].i-1);
    }
    sort(q.begin(),q.end(),sort2);
    for(int i=0;i<m;i++){
        printf("%d\n",q[i].answer);
    }
    return 0;
}
