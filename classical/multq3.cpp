#include <bits/stdc++.h>
using namespace std;

struct A {
    int n0, n1, n2;
    int lazy;
    A *l, *r;
};

int n,m,x,y,z;
A* tree;

A* construct(A* node, int l,int r) {
    if(l == r) {
        A* newnode = new A;
        newnode->n0 = 1;
        newnode->n1 = newnode->n2 = newnode->lazy = 0;
        newnode->l = newnode->r = NULL;
        return newnode;
    }
    int mid = (l+r) >> 1;
    node = new A;
    node->l = construct(node->l, l, mid);
    node->r = construct(node->r, mid+1, r);
    node->n0 = node->l->n0 + node->r->n0;
    node->n1 = node->n2 = node->lazy = 0;
    return node;  
}

void increase(A* node, int l,int r, int a, int b) {
    if(node->lazy > 0) {
        if(node->l!=NULL) node->l->lazy += node->lazy;
        if(node->r!=NULL) node->r->lazy += node->lazy;
        for(int i=0; i<node->lazy%3; i++) {
            int tmp = node->n2;
            node->n2 = node->n1;
            node->n1 = node->n0;
            node->n0 = tmp;
        }
        node->lazy = 0;
    }
    if(r<a || l>b || l>r) return;
    if(l>=a && r<=b) {
        int tmp = node->n2;
        node->n2 = node->n1;
        node->n1 = node->n0;
        node->n0 = tmp;
        if(l==r) return;
        node->l->lazy++;
        node->r->lazy++;
        return;
    }
    int mid = (l+r) >> 1;
    increase(node->l, l, mid, a, b);
    increase(node->r, mid+1, r, a, b);
    node->n0 = node->l->n0 + node->r->n0;
    node->n1 = node->l->n1 + node->r->n1;
    node->n2 = node->l->n2 + node->r->n2;   
}

int query(A* node, int l,int r,int a,int b) {
    if(node->lazy > 0) {
        if(node->l!=NULL) node->l->lazy += node->lazy;
        if(node->r!=NULL) node->r->lazy += node->lazy;
        for(int i=0; i<node->lazy%3; i++) {
            int tmp = node->n2;
            node->n2 = node->n1;
            node->n1 = node->n0;
            node->n0 = tmp;
        }
        node->lazy = 0;
    }
    if(r<a || l>b || l>r) return 0;
    if(l>=a && r<=b) {
        return node->n0;
    }
    int mid = (l+r) >> 1, askL, askR;
    askL = query(node->l, l, mid, a, b);
    askR = query(node->r, mid+1, r, a, b);
    node->n0 = node->l->n0 + node->r->n0;
    node->n1 = node->l->n1 + node->r->n1;
    node->n2 = node->l->n2 + node->r->n2;
    return askL + askR;  
}

void preorder(A* now) {
    if(now->l != NULL) printf("L"), preorder(now->l);
    if(now->r != NULL) printf("R"), preorder(now->r);
}

int main() {
    scanf("%d%d",&n,&m);
    tree = construct(tree, 0, n-1);
    while(m--) {
        scanf("%d%d%d",&x,&y,&z);
        if(x == 0) {
            increase(tree,0,n-1,y,z);
        } else {
            printf("%d\n",query(tree,0,n-1,y,z));
        }
    }
    return 0;
}