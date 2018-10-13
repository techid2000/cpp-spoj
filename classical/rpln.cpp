#include <bits/stdc++.h>
using namespace std;

int tc,n,q,le,wi,a,b;
int tb[20][200005];

int main() {
    scanf("%d",&tc); for(int _tc=1;_tc<=tc;_tc++) {
        memset(tb, 0, sizeof tb);
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++) {
            scanf("%d",&tb[0][i]);
        }
        for(int i=1; 1<<(i-1)<n; i++) {
            wi = (1<<(i-1));
            for(int j=0; j<n-wi;j++) {
                tb[i][j] = min(tb[i-1][j],tb[i-1][j+wi]);
            }
        }    
        printf("Scenario #%d:\n",_tc);
        while(q--) {
            scanf("%d%d",&a,&b);
            a--, b--;
            le = log2(b-a+1);
            printf("%d\n",min(tb[le][a],tb[le][b-(1<<le)+1]));
        }
    }
}