#include <bits/stdc++.h>
using namespace std;

struct node{
    int sum,minsum;
};
node tree[350000];
char s[35000];
int tc,n,m,k;
void add(int node,int idx,int p,int q,int v){
    if(q<idx || p>idx)return;
    if(p==q){
        tree[node].sum=v;
        tree[node].minsum=v;
        return;
    }
    int mid=(p+q)>>1;
    add(2*node,idx,p,mid,v);
    add(2*node+1,idx,mid+1,q,v);
    tree[node].sum = tree[2*node].sum+tree[2*node+1].sum;
    tree[node].minsum = min(tree[2*node].minsum, tree[2*node].sum+tree[2*node+1].minsum);
}

int main()
{
    for(tc=1;tc<=10;tc++){
        scanf("%d",&n);
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++){
            scanf(" %c",&s[i]);
            if(s[i]=='(') {
                add(1,i,1,n,1);
            } else {
                add(1,i,1,n,-1);
            }
        }
        printf("Test %d:\n",tc);
        scanf("%d",&m);
        while(m--){
            scanf("%d",&k);
            if(k==0){
                if(tree[1].sum==0 && tree[1].minsum>=0){
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            } else {
                if(s[k]=='('){
                    add(1,k,1,n,-1);
                    s[k]=')';
                } else {
                    add(1,k,1,n,1);
                    s[k]='(';
                }
            }
        }
    }
    return 0;
}
