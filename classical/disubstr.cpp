#include <bits/stdc++.h>
using namespace std;

char txt[1005],tmp;
int ind[1005],len,lo,hi,mid,cmp,x,y,z,cnt,t;
int ch[1005][1005];
int lexi(int a,int b) {
    return strcmp(txt+a, txt+b) < 0 ? 1 : 0;
}

int main() {
    scanf("%d",&t);
    while(t--) {
        memset(ch,0,sizeof ch);
        memset(ind,0,sizeof ind);
        memset(txt,0,sizeof txt);
        cnt = 0;
        scanf(" %s",txt+1);
        len=strlen(txt+1);
        for(int i=1;i<=len;i++)
            ind[i] = i;
        sort(ind+1, ind+len+1, lexi);
        for(int i=1;i<=len;i++) {
            for(int j=i;j<=len;j++) {
                if(ch[i][j-i+1])continue;
                lo = 1, hi = len;
                while(lo < hi) {
                    mid = (lo + hi) >> 1;
                    cmp = strncmp(txt + ind[mid],txt + i,j-i+1);
                    if(cmp < 0) {
                        lo = mid+1;
                    } else {
                        hi = mid;
                    }
                }
                x = lo;
                lo = 1, hi = len;
                while(lo < hi) {
                    mid = (lo + hi + 1) >> 1;
                    cmp = strncmp(txt + ind[mid],txt + i,j-i+1);
                    if(cmp > 0) {
                        hi = mid-1;
                    } else {
                        lo = mid;
                    }
                }
                y = hi;
                cnt++;
                for(z=x;z<=y;z++) {
                    ch[ind[z]][j-i+1]=1;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}