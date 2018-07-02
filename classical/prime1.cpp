#include <bits/stdc++.h>
using namespace std;

int t;
int a,b,c,i;
int main()
{
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&a,&b);
        for(;a<=b;a++) {
            if(a==1)continue;
            c=sqrt(a);
            for(i=2;i<=c;i++){
                if(a%i==0){
                    break;
                }
            }
            if(i>c){
                printf("%d\n",a);
            }
        }
    }
    return 0;
}
