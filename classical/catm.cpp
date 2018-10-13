#include <bits/stdc++.h>
using namespace std;
int n,m,k,ai,aj,bi,bj,ci,cj;
double m1,m2;

int main() {
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    while(k--){
        scanf("%d%d%d%d%d%d",&ai,&aj,&bi,&bj,&ci,&cj);
        if((bj-aj>0 && aj-cj>0) || (aj-bj>0 && cj-aj>0)) {
            m1 = 1.0*(bi-ai)/(bj-aj);
            m2 = 1.0*(ai-ci)/(aj-cj);
            if((m1==-1||m1==1)&&(m1==m2)) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            printf("YES\n");
        }
    }
}