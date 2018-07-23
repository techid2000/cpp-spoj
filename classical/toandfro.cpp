#include <bits/stdc++.h>
using namespace std;

int n,len;
char a[205];

int main()
{
    while(true) {
        scanf("%d",&n);
        if(n==0) return 0;
        scanf(" %s",a+1);
        len = strlen(a+1);
        int j = 0;
        for(int i=1; i<=len; i+=n) {
            if(j) 
                for(int k=0; k<n/2; k++) 
                    swap(a[i+k], a[i+n-1-k]);
            j = 1-j;
        }
        for(int i=1; i<=n; i++) {
            for(int j=i;j<=len;j+=n) {
                putchar(a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}