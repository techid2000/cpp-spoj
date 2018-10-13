#include <bits/stdc++.h>
using namespace std;

int n;
int A[35];
int B[35];

int main() {
    A[0] = 1, B[0] = 0;
    A[1] = 0, B[1] = 1;
    for(int i=2;i<=30;i++) {
        A[i] = 3*A[i-2] + 2*B[i-3];
                          //serious
        B[i] = A[i-1] + B[i-2];
    }
    while(scanf("%d",&n)!=EOF && n!=-1) {
        printf("%d\n",A[n]);
    }
    return 0;
}