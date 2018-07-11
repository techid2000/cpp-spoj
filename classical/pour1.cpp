/*
Extended Euclidean is not necessary in this solution but used in proving.
ax + by = k*gcd(a,b) then there will have some (x,y) that satisfied the equation
*/
#include <bits/stdc++.h>
using namespace std;

int gcd,x,y;
int t,a,b,c;
int mo1,mo2,ba,bb;
void euclid(int a,int b,int *gcd, int *x,int *y) {
    if(b == 0) {
        *gcd = a;
        *x = 1;
        *y = 0;
        return;
    }
    int x1, y1;
    euclid(b, a%b, gcd, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b)*y1;
}
void play() {
    mo1 = mo2 = ba = bb = 0;
    while((ba != c && bb != c)) {
        if(ba == 0) { ba = a, mo1++; continue; }
        if(bb == b) { bb = 0, mo1++; continue; }
        if(ba + bb <= b) {
            bb += ba;
            ba = 0;
        } else {
            ba -= (b - bb);
            bb = b;
        }
        mo1++;
    }
    ba = bb = 0;
    while((ba != c && bb != c)) {
        if(bb == 0) { bb = b, mo2++; continue; }
        if(ba == a) { ba = 0, mo2++; continue; }
        if(bb + ba <= a) {
            ba += bb;
            bb = 0;
        } else {
            bb -= (a - ba);
            ba = a;
        }
        mo2++;
    }
    printf("%d\n",min(mo1,mo2));
}
int main()
{
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&a,&b,&c);
        if(c > max(a,b)) {
            printf("-1\n"); continue;
        }
        euclid(a,b,&gcd,&x,&y);
        if(c % gcd != 0) {
            printf("-1\n"); continue;
        }
        play();
    }

    return 0;
}
