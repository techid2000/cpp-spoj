#include <bits/stdc++.h>
using namespace std;
char s[5];
int n,x;
int main() {
    while(true) {
        scanf(" %s",s);
        n = ((s[0]-'0')*10+(s[1]-'0'));
        for(int i=0;i<s[3]-'0';i++) {
            n*=10;
        }
        if(n == 0) return 0;
        if(n == 1) {
            printf("1\n");
            continue;
        }
        n--;
        x = 1;
        while(n-(1<<x) > 0) {
            n -= (1<<(x++));
        }
        printf("%d\n",2*(n)-1);
    }
}