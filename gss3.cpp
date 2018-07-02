#include <bits/stdc++.h>
using namespace std;

struct node {
    int msl,msr,pf,sf;
    int bi,bj;
};

node tree[300000];
int n,m,a,b,k;
int in,qsa[50005];
vector<node>opt;

void bit_add(int i,int v){
    while(i<=50000){
        qsa[i]+=v;
        i+=(i&(-i));
    }
}

int bit_ask(int i,int j) {
    i--;
    int si=0,sj=0;
    while(i>0){
        si+=qsa[i];
        i-=(i&(-i));
    }
    while(j>0){
        sj+=qsa[j];
        j-=(j&(-j));
    }
//    printf("<<%d,%d>>\n",si,sj);
    return sj-si;
}

void evaluate(int no) {
   int maxsum=-1e9,tmp;
    tree[no].msl=tree[no].msr=0;
    if(tree[2*no].msl>0 && tree[2*no].msr>0){
        tmp=bit_ask(tree[2*no].msl,tree[2*no].msr);
        if(tmp > maxsum) {
            maxsum = tmp;
            tree[no].msl=tree[2*no].msl;
            tree[no].msr=tree[2*no].msr;
        }
    }
    if(tree[2*no+1].msl>0 && tree[2*no+1].msr>0){
        tmp=bit_ask(tree[2*no+1].msl,tree[2*no+1].msr);
        if(tmp > maxsum) {
            maxsum = tmp;
            tree[no].msl=tree[2*no+1].msl;
            tree[no].msr=tree[2*no+1].msr;
        }
    }
    if(tree[2*no].sf>0 && tree[2*no+1].pf>0){
        tmp=bit_ask(tree[2*no].sf,tree[2*no+1].pf);
        if(tmp > maxsum) {
            maxsum = tmp;
            tree[no].msl=tree[2*no].sf;
            tree[no].msr=tree[2*no+1].pf;
        }
    }
    maxsum=-1e9;
    tree[no].pf=0;
    if(tree[2*no].pf>0){
        tmp=bit_ask(tree[2*no].bi,tree[2*no].pf);
        if(tmp > maxsum) {
            maxsum = tmp;
            tree[no].pf=tree[2*no].pf;
        }
    }
    if(tree[2*no+1].pf>0){
        tmp=bit_ask(tree[2*no].bi,tree[2*no+1].pf);
        if(tmp > maxsum) {
            maxsum = tmp;
            tree[no].pf=tree[2*no+1].pf;
        }
    }
    maxsum = -1e9;
    tree[no].sf=0;
    if(tree[2*no].sf>0){
        tmp=bit_ask(tree[2*no].sf,tree[2*no+1].bj);
        if(tmp > maxsum) {
            maxsum = tmp;
            tree[no].sf=tree[2*no].sf;
        }
    }
    if(tree[2*no+1].sf>0){
        tmp=bit_ask(tree[2*no+1].sf,tree[2*no+1].bj);
        if(tmp > maxsum) {
            maxsum = tmp;
            tree[no].sf=tree[2*no+1].sf;
        }
    }
//    printf("At node %d:\n",no);
//    printf("msl=%d\nmsr=%d\npf=%d\nsf=%d\n",tree[no].msl,tree[no].msr,tree[no].pf,tree[no].sf);
}

void construct(int no,int p,int q) {
//    printf("%d,%d,%d\n",no,p,q);
    if(p==q){
//        if(bit_ask(p,p) >= 0){
            tree[no].msl=p,tree[no].msr=p,
            tree[no].pf=p,tree[no].sf=p;
//        }
        tree[no].bi=p,tree[no].bj=q;
        return;
    }
    int mid=(p+q)>>1;
    construct(2*no,p,mid);
    construct(2*no+1,mid+1,q);

    evaluate(no);

    tree[no].bi=p,tree[no].bj=q;
    return;
}

void add(int no,int p,int q,int idx,int v) {
    if(q<idx || p>idx) return;
    if(p==q) {
        tree[no].msl=p,tree[no].msr=p,
        tree[no].pf=p,tree[no].sf=p;
        int tmp=bit_ask(p,p);
        bit_add(p,-tmp+v);
        return;
    }
    int mid=(p+q)>>1;
    add(2*no,p,mid,idx,v);
    add(2*no+1,mid+1,q,idx,v);
    evaluate(no);
}

void ask(int no,int p,int q) {
    if(q<a || p>b) return;
    if(p>=a && q<=b) {
//        printf("%d,%d : %d,%d <%d>\n",p,q,a,b,no);
        opt.push_back(tree[no]);
        return;
    }
    int mid=(p+q)>>1;
    ask(2*no,p,mid);
    ask(2*no+1,mid+1,q);
}


int query(int i,int j) {
    opt.clear();
    ask(1,1,n);
    int max_ret=-1e9;
//    printf("--%d\n",opt.size());
    for(int i=0; i<opt.size(); i++) {
        for(int j=i;j<opt.size();j++) {
            if(i==j) {
                max_ret = max(max_ret, bit_ask(opt[i].msl,opt[i].msr));
//                printf("%d %d\n",opt[i].msl,opt[i].msr);
            } else if(i+1==j) {
                max_ret = max(max_ret, bit_ask(opt[i].sf,opt[j].pf));
            } else
                max_ret = max(max_ret, bit_ask(opt[i].sf,opt[i].bj)+bit_ask(opt[i+1].bi,opt[j-1].bj)+bit_ask(opt[j].bi,opt[j].pf));
        }
    }
    return max_ret;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&in);
        bit_add(i,in);
    }
//    printf("KK%d\n",bit_ask(1,2));
    construct(1,1,n);
//    printf("<%d,%d> <%d> <%d>",tree[1].msl,tree[1].msr,tree[1].pf,tree[1].sf);
    scanf("%d",&m);
    while(m--) {
        scanf("%d%d%d",&k,&a,&b);
        if(k==0) {
            add(1,1,n,a,b);
        } else {
            printf("%d\n",query(a,b));
        }
    }

    return 0;
}
